// $Id: mem_din.cpp 82 2005-03-03 09:20:28Z conrado $

#include <iostream>
#include <cstdlib>
#include <string>

#include <esin/mem_din>
#include <esin/error>
#include <esin/gen_driver>

using namespace std;

// funciones utiles
namespace mem_din_util {
  bool is_prime(int n) {
    if ((n <= 2) || (n % 2 == 0)) return n <= 2;
    int j = 3;
    while (j * j <= n && n % j != 0) 
      j += 2;
    return (j * j > n);
  }
  int hash(void* p, int M) {
    return ((unsigned long) p) % M;
  }
  int nearest_prime(int n) {
    int i = n;
    while (!is_prime(i)) 
      i++;
    return i;
  }
}




// declaraciones de mem_din_pool y objetos de la clase (static's) 
class mem_din_pool {
public:

   mem_din_pool(int max_chunks = mem_din::DEFAULT_MAX_CHUNKS, 
                long max_bytes = mem_din::DEFAULT_MAX_SIZE);
   ~mem_din_pool();

  friend void mem_din::set_parameters(int, long) throw(error);

  friend void* operator new(size_t s) throw(std::bad_alloc);
  friend void operator delete(void* p) throw();
  friend void* operator new[](size_t s) throw(std::bad_alloc);
  friend void operator delete[](void* p) throw();

  void print_memory_status_report(ostream& os, int vb_level) throw();
  int nr_chunks() { return nr_allocated_chunks_; }
  int nr_bytes() { return nr_allocated_bytes_; } 
  int nr_news() { return nr_news_; }
  int nr_del_no_new() { return nr_del_no_new_; }
  int max_chunks() { return max_chunks_; }
  int max_bytes() { return max_bytes_; }

  static void switch_on() { active_memdin_ = true; }
  static void switch_off() { active_memdin_ =  false; }
  static bool active() { return active_memdin_; }

private:
   struct pool_node {
     void* p;
     size_t sz;
     int nobjs;
     pool_node():p(0), sz(0), nobjs(0) {}
   };

   pool_node* pool;

   int max_chunks_;
   int max_bytes_;
   int real_chunks;

   int nr_allocated_chunks_;
   int nr_allocated_bytes_;
   int nr_news_;
   int nr_del_nil_;
   int nr_del_type_;
   int nr_del_no_new_;

  static int nr_mem_dins;
  static bool active_memdin_;

  static void rehash(pool_node* p, pool_node* aux, int real_chunks);

   // no se puede usar inic. por copia y asignacion

   mem_din_pool(const mem_din_pool& m) {}
   void operator=(const mem_din_pool& m) {}
  
};

mem_din_pool& _MEMDIN__() {
  static mem_din_pool m; 
  return m;
};

int mem_din_pool::nr_mem_dins = 0;
bool mem_din_pool::active_memdin_ = false;

namespace mem_din {

  void switch_on() throw() {    mem_din_pool::switch_on(); }
  void switch_off() throw() {    mem_din_pool::switch_off(); }
  bool active() throw() { return mem_din_pool::active(); }
  
  void set_parameters(int max_chks, long max_sz) throw(error) {
    if (_MEMDIN__().nr_allocated_chunks_ > max_chks || 
        _MEMDIN__().nr_allocated_bytes_ > max_sz)
      throw error(MemDinNoConfigurable, nom_mod,MsgMemDinNoConfigurable);
    
    if (max_chks < 0 || max_sz < 0)
      throw error(ParMemDinIncorrectos, nom_mod,MsgParMemDinIncorrectos); 
    
    int real_chunks = mem_din_util::nearest_prime(max_chks);
    
    mem_din_pool::pool_node* aux = (mem_din_pool::pool_node*) calloc(sizeof(mem_din_pool::pool_node), real_chunks);
    
    if (aux == 0)
      throw error(MemDinNoConfigurable, nom_mod,MsgMemDinNoConfigurable); 
    
    for (int i = 0; i < real_chunks; i++) {
      aux[i].sz = 0;
      aux[i].nobjs = 0;
      aux[i].p = 0;
    }
    
    for (mem_din_pool::pool_node* pn = _MEMDIN__().pool; 
	 pn != _MEMDIN__().pool + _MEMDIN__().real_chunks; ++pn) {
      if (pn -> p) 
	mem_din_pool::rehash(pn, aux, real_chunks);
    }

    free(_MEMDIN__().pool);
    _MEMDIN__().pool = aux;
    
    _MEMDIN__().real_chunks = real_chunks;
    _MEMDIN__().max_chunks_ = max_chks;
    _MEMDIN__().max_bytes_ = max_sz;
    
  }


  void print_memory_status_report(ostream& os, int vb) throw() {
    _MEMDIN__().print_memory_status_report(os, vb);
  }
  
  int nr_chunks() throw() {
    return _MEMDIN__().nr_chunks();
  }
  
  int nr_bytes() throw() {
    return _MEMDIN__().nr_bytes();
  }
  
  int nr_news() throw() {
    return _MEMDIN__().nr_news();
  }
  
  int nr_del_no_new() throw() {
    return _MEMDIN__().nr_del_no_new();
  }
  
  int max_chunks() throw() {
    return _MEMDIN__().max_chunks();
  }
  
  int max_bytes() throw() {
    return _MEMDIN__().max_bytes();
  }
}

void* operator new(size_t bytes) throw(std::bad_alloc) {
  if (!mem_din_pool::active_memdin_) {
    void* p = malloc(bytes);
    if (p == 0)
      throw std::bad_alloc();
    return p;
  }
  if (_MEMDIN__().nr_allocated_bytes_ + int(bytes) > _MEMDIN__().max_bytes_) 
    throw error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);
  
  if (_MEMDIN__().nr_allocated_chunks_ + 1 > _MEMDIN__().max_chunks_) 
    throw  error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);
  
  void* p = malloc(bytes);
  if (p == 0)
    throw error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);
  
  mem_din_pool::pool_node* pool = _MEMDIN__().pool;
  
  int i = mem_din_util::hash(p,_MEMDIN__().real_chunks);
  while (pool[i].nobjs > 0) 
    i = (i + 1) % _MEMDIN__().real_chunks;
  
  pool[i].sz = bytes;
  pool[i].p = p;
  pool[i].nobjs = 1;

  _MEMDIN__().nr_allocated_chunks_++;
  _MEMDIN__().nr_allocated_bytes_ += bytes;
  _MEMDIN__().nr_news_++;
  return p;    
}

void operator delete(void* p) throw() {
  if (!mem_din_pool::active_memdin_) {
    free(p); return;
  }
  if (p == 0) { _MEMDIN__().nr_del_nil_++; 
    return; }

  mem_din_pool::pool_node* pool = _MEMDIN__().pool;

  int i = mem_din_util::hash(p, _MEMDIN__().real_chunks); 
  int prev_i = (i == 0) ? _MEMDIN__().real_chunks - 1 
                        : (i - 1) % _MEMDIN__().real_chunks;
  while (pool[i].nobjs != 0 && pool[i].p != p && i != prev_i) {
    i = (i + 1) % _MEMDIN__().real_chunks;
  }
  if (pool[i].p != p) // no esta en la tabla de apuntadores
    { _MEMDIN__().nr_del_no_new_++; 
      return; }
  
  size_t bytes = pool[i].sz;
  if (pool[i].nobjs != 1)
    _MEMDIN__().nr_del_type_++;
  free(p);
  pool[i].sz = 0;
  pool[i].p = 0;
  pool[i].nobjs = -1;

  _MEMDIN__().nr_allocated_chunks_--;
  _MEMDIN__().nr_allocated_bytes_ -= bytes;
}

void* operator new[](size_t bytes) throw(std::bad_alloc) {
  if (!mem_din_pool::active_memdin_) {
    void* p = malloc(bytes);
    if (p == 0)
      throw std::bad_alloc();
    return p;
  }
  if (_MEMDIN__().nr_allocated_bytes_ + int(bytes) > _MEMDIN__().max_bytes_) 
    throw error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);

  if (_MEMDIN__().nr_allocated_chunks_ + 1 > _MEMDIN__().max_chunks_) 
    throw  error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);

  void* p = malloc(bytes);
  if (p == 0)
    throw error(mem_din::FaltaMemoriaDin, mem_din::nom_mod,mem_din::MsgFaltaMemoriaDin);

  mem_din_pool::pool_node* pool = _MEMDIN__().pool;

  int i = mem_din_util::hash(p,_MEMDIN__().real_chunks);
  while (pool[i].nobjs > 0) 
    i = (i + 1) % _MEMDIN__().real_chunks;

  pool[i].sz = bytes;
  pool[i].p = p;
  pool[i].nobjs = 2;

  _MEMDIN__().nr_allocated_chunks_++;
  _MEMDIN__().nr_allocated_bytes_ += bytes;
  _MEMDIN__().nr_news_++;
  return p;    
}

void operator delete[](void* p) throw() {
  if (!mem_din_pool::active_memdin_) {
    free(p); 
    return;
  }

  if (p == 0) { 
    _MEMDIN__().nr_del_nil_++; 
    return; 
  }

  mem_din_pool::pool_node* pool = _MEMDIN__().pool;

  int i = mem_din_util::hash(p, _MEMDIN__().real_chunks); 
  int prev_i = (i == 0) ? _MEMDIN__().real_chunks - 1 
                        : (i - 1) % _MEMDIN__().real_chunks;
  while (pool[i].nobjs != 0 && pool[i].p != p && i != prev_i) {
    i = (i + 1) % _MEMDIN__().real_chunks;
  }
  if (pool[i].p != p) { // no esta en la tabla de apuntadores
    _MEMDIN__().nr_del_no_new_++; 
  }
  else {
    size_t bytes = pool[i].sz;
    if (pool[i].nobjs != 2)
      _MEMDIN__().nr_del_type_++;
    free(p);
    pool[i].sz = 0;
    pool[i].p = 0;
    pool[i].nobjs = -1;
    
    _MEMDIN__().nr_allocated_chunks_--;
    _MEMDIN__().nr_allocated_bytes_ -= bytes;
  }
}



void mem_din_pool::rehash(pool_node* pn, pool_node* aux, int real_chunks) {
    int i = mem_din_util::hash(pn -> p, real_chunks);
    while (aux[i].nobjs > 0) 
      i = (i + 1) % real_chunks;
    aux[i].sz = pn -> sz;
    aux[i].p = pn -> p;
    aux[i].nobjs = pn -> nobjs;
}


mem_din_pool::mem_din_pool(int max_chks, long max_sz):
         pool(0), max_chunks_(max_chks),max_bytes_(max_sz),
         real_chunks(mem_din_util::nearest_prime(max_chks)) {

  pool = (pool_node*) calloc(sizeof(pool_node), real_chunks);
  for(int i = 0; i < real_chunks; i++) {
    pool[i].sz = 0;
    pool[i].nobjs = 0;
    pool[i].p = 0;
  }
  if (nr_mem_dins > 0) 
    throw error(0, "mem_din_pool", "CANT HAPPEN!!");   
  // solo hay 1 memoria dinamica!!
  nr_mem_dins++;
  
  nr_allocated_chunks_ = 0;
  nr_allocated_bytes_ = 0;
  nr_news_ = 0;
  nr_del_nil_ = nr_del_type_ = nr_del_no_new_ = 0; 
}

mem_din_pool::~mem_din_pool() {
  print_memory_status_report(cout, 0);
  if (nr_allocated_chunks_ > 0) {
    for (int i = 0; i < max_chunks_; i++) {
      if (pool[i].p != 0) {
	free(pool[i].p);
      }
    }
  }
  free(pool);
}

void mem_din_pool::print_memory_status_report(ostream& os, int vb) throw() {
  switch (vb) {
  case 2 : {
    os << "[MEMORY DUMP:" << endl;
    os << "\treal_chunks = " << real_chunks << endl;
    for (int i = 0; i < real_chunks; i++)
      if (pool[i].p != 0) {
        os << "pool[" << i << "]: size = " << pool[i].sz << ", ";
        os << "alloc by " << ((pool[i].nobjs > 1) ? "new[]" : "new") << ", ";
        os << "address = " << pool[i].p << endl;
      }
    os << "]" << endl; }
  case 1 : {
    os << "[MEMORY STATUS REPORT:" << endl;
    os << "\tmax_chunks = " << max_chunks_ << endl;
    os << "\tmax_bytes = " << max_bytes_ << endl;
    os << "\talloc_chunks = " << nr_allocated_chunks_ << endl;
    os << "\talloc_bytes = " << nr_allocated_bytes_ << endl;
    os << "\tallocations = " << nr_news_ << endl;
    os << "\t#delete[] - new (E) = " << nr_del_type_ << endl;
    os << "\t#delete without new (E) = " << nr_del_no_new_ << endl;
    os << "]" << endl;
    break; }
  default: { 
    string c = (nr_news_ > 0) ? "" : "**";
    os << "[" << nr_allocated_chunks_ << "/";
    os << nr_del_type_ + nr_del_no_new_ << "]" << c << endl; }
  }
}

