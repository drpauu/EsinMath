// $Id: gen_driver.cpp 132 2005-09-16 13:03:47Z conrado $
// (C) Conrado Martinez Parra, Diciembre, 2003

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

//#include <esin/mem_din>
#include <esin/error>
#include <esin/gen_driver>
#include <esin/util>

using util::nat;
using std::string;
using std::istream;
using std::ostream;
using std::map; 
using std::vector;
using std::ofstream;  
using std::ifstream;  
using std::endl;
using std::cout; 
using std::endl;

void* user_init(gen_driver&);
ofstream* gen_driver::_null_stream = NULL;

const string gen_driver::nom_mod = "gen_driver";
const string gen_driver::NoOpMsg = "Operacion incorrecta";
const string gen_driver::WrongNumArgsMsg = "Num. argumentos incorrecto";
const string gen_driver::WrongTypeArgsMsg = "Tipo argumentos incorrecto";
const string gen_driver::NoObjMsg = "Objeto inexistente";
const string gen_driver::WrongTypeObjMsg = "Operacion no aplicable sobre objeto";
const string gen_driver::NoFileMsg = "No se puede abrir el fichero";


////////////////////////////////////////////////////////////////////////
// gen_driver::input_line
//

bool gen_driver::input_line::_echoing = true;
const string gen_driver::input_line::nom_mod  = "gen_driver::input_line";
const string gen_driver::input_line::ArgNoExisteMsg = "Argumento inexistente"; 
const string &gen_driver::input_line::args(int m) const throw(error) {
   int n = _args.size();
   if (m < 1 || m > n) 
     throw error(ArgNoExiste, nom_mod, ArgNoExisteMsg);
   return _args[m - 1];
}   

void gen_driver::input_line::push_back(const gen_driver::input_line& L) {
  for (util::nat i = 0; i < L.nargs(); ++i) {
    _args.push_back(L._args[i]);
    _orig.push_back(L._orig[i]);
  }
}

void gen_driver::input_line::push_back(const string& s) {
    _args.push_back(s);
    _orig.push_back(s);
}

void gen_driver::input_line::shift_args(int i) {

  i--;

  util::nat sz = _args.size();
  for(util::nat j = i; j < sz; ++j) 
    _args[j - i] = _args[j];

  //  _args.erase(_args.end() - i,_args.end());

  _args.resize(sz-i);
 
}

void gen_driver::input_line::read(istream& is) {
  char line[gen_driver::input_line::MAX_LINE_LENGTH];
  
  do {
    _args.clear();
    if (is.getline(line, gen_driver::input_line::MAX_LINE_LENGTH)) {
      util::split(line, _args);
      if (_args.size() > 0) {
        if (gen_driver::input_line::_echoing) 
          _echo_stream << "#" << line << endl;
        if (_args[0] == "%") 
          system(&line[1]);
      }
    } else break;
  }
  while (_args.size() == 0 || _args[0][0] == '#' || _args[0][0] == '%');
  _orig = _args;
}

void gen_driver::input_line::write(ostream& os) const {
   for (util::nat i = 0; i < _orig.size() - 1; ++i)
        os << _orig[i] << " "; 
   os << _orig[_orig.size() - 1];
}


namespace gen_driver_aux {

  void version_libesin(gen_driver& dr) {
    static const char LIBESIN_VERSION[] = "$Revision: 132 $ $Date: 2005-09-16 15:03:47 +0200 (Fri, 16 Sep 2005) $";
    dr.get_ostream() << LIBESIN_VERSION << endl;
  }
  
  void turn_memory(gen_driver& dr) {
    if (dr.args(1) == "on")
      dr.memory(true);
    else if (dr.args(1) == "off" && mem_din::nr_chunks() == 0)
      dr.memory(false);
    else if (dr.args(1) == "off" && mem_din::nr_chunks() > 0)
      throw error(gen_driver::NoOp, gen_driver::nom_mod, 
		  gen_driver::NoOpMsg);
    else
      throw error(gen_driver::WrongTypeArgs, gen_driver::nom_mod, 
		  gen_driver::WrongTypeArgsMsg);
  }

  void test_memory(gen_driver& dr) {
    dr.test_memory();
  }

  void init(gen_driver& dr) {
    dr.init();
  }

  void copy(gen_driver& dr) {
    dr.copy();
  }
  
  void initcopy(gen_driver& dr) {
    std::cout << dr << std:endl;
    dr.initcopy();
  }
  
  void destroy(gen_driver& dr) {
    dr.destroy();
  }

  void clear_all(gen_driver& dr) {
    dr.clear_all();
  }

  void set_memory(gen_driver& dr) {
    dr.set_memory();
  }

  void print_memory(gen_driver& dr) {
    dr.print_memory();
  }
  
  void echo_input(gen_driver& dr) { 
    dr.echo_input();
  }
  
  void echo_output(gen_driver& dr) {
    dr.echo_output();
  }
  
  void help(gen_driver& dr) {
    dr.help();
  }
  
  void list_objects(gen_driver& dr) {
    dr.list_objects();
  }
  
  void known_types(gen_driver& dr) {
    dr.known_types();
  }

  void apply(gen_driver& dr) {
    dr.apply();
  }
  
  void iter(gen_driver& dr) {
    dr.iter();
  }

  void load(gen_driver& dr) {
    dr.load();
  }
  
  void curr_obj_name(gen_driver& dr) {
    dr.curr_obj_name();
  }
  
  void select_curr_obj(gen_driver& dr) {
    dr.select_curr_obj();
  }
  
  void applies_to(gen_driver& dr) {
    dr.applies_to();
  }

  void timer_on(gen_driver& dr) {
    dr.timer_on();
  }
  
  void timer_off(gen_driver& dr) {
    dr.timer_off();
  }

// chequeos
bool check_string(const string& s) { return true; }
bool check_char(const string& s) { return s.length() == 1; }
bool check_int(const string& s) { 
  try { util::toint(s); return true; } catch(...) { return false; }}
bool check_nat(const string& s) { 
  try { int n = util::toint(s); return n >= 0; } catch(...) { return false; }}
bool check_double(const string& s) { 
  try { util::todouble(s); return true; } catch(...) { return false; }}
}

// ========================================================================

// metodos de gen_driver
//

void gen_driver::init() {
  mem_din::switch_off();
  
  if (_il->nargs() < 2)
    throw error(WrongNumArgs, nom_mod, WrongNumArgsMsg);
  const string& objid = _il->args(1);
  const string& typeofobj = _il->args(2);
  if (_obj.find(objid) != _obj.end()) {
    DtorFunction destruye = _dtor[_type[objid]];
    if (_memdin) 
      mem_din::switch_on();
    destruye(_obj[objid]);
    mem_din::switch_off();
    _obj.erase(objid);
    _type.erase(objid);
  }
  void *p =NULL;
  if (_memdin)
    mem_din::switch_on();
  p = user_init(*this);
  mem_din::switch_off();
  
  if (p != NULL) {
    _obj[objid] = p;
    _type[objid] = typeofobj;
    _curr_obj = objid;
  }
}

void gen_driver::initcopy() {
  mem_din::switch_off();
// string src = _il->object();

  // nueva variante: initcopy x = y
  const string& newobj = _il->args(1);
  // error de sintaxis
  if (_il->args(2) != "=") 
    throw error(NoOp, nom_mod, NoOpMsg);
  const string& src = _il->args(3);
  if (_obj.find(src) == _obj.end()) {
     throw error(NoObj, nom_mod, NoObjMsg);
  }
  if (_obj.find(newobj) != _obj.end()) {
    DtorFunction destruye = _dtor[_type[newobj]];
    if (_memdin)
      mem_din::switch_on();
    destruye(_obj[newobj]);
    mem_din::switch_off();
    _obj.erase(newobj);
    _type.erase(newobj);
  }
  CopyCtorFunction copia = _copyctor[_type[src]];
  if(_memdin)
    mem_din::switch_on();
  void * c = copia(_obj[src]);
  mem_din::switch_off();
  _obj[newobj] = c;
  _type[newobj] = _type[src];
}


void gen_driver::copy() {
  mem_din::switch_off();
  if (_type[_il->object()] != _type[_il->args(1)])
    throw error(WrongTypeArgs, nom_mod, WrongTypeArgsMsg);
  AsgnFunction copia = _assignment[_type[_il->object()]];
  if (_memdin)
    mem_din::switch_on();
  copia(_obj[_il->object()], _obj[_il->args(1)]);
  mem_din::switch_off();
}

void gen_driver::destroy() {
  mem_din::switch_off();
  const string& to_kill = _il->object();
  DtorFunction destruye = _dtor[_type[to_kill]];
  if (_memdin)
    mem_din::switch_on();
  destruye(_obj[to_kill]);
  mem_din::switch_off();
  _obj.erase(to_kill);
  _type.erase(to_kill);
}

void gen_driver::clear_all() {
  mem_din::switch_off();
  // const string& to_kill = _il->object();
  ObjTbl::const_iterator ito = _obj.begin();
  while (ito != _obj.end()) {
    DtorFunction destruye = _dtor[_type[ito -> first]];
    if (_memdin)
      mem_din::switch_on();
    destruye(ito -> second);
    mem_din::switch_off();
    ito++;
  }
  _obj.clear();
}

void gen_driver::test_memory(const string& _class) {
 mem_din::switch_off();
 ostream& os = get_ostream();
 bool ok = true;
  os << "Performing " << _tm[_class].size() << " memtests for class "; 
  os << _class << endl;
  vector<MemTestFunction>::iterator it = _tm[_class].begin();
  vector<MemTestFunction>::iterator end = _tm[_class].end();
  while (ok && it != end) {
    ok = (*it)(*this);
    ++it;
  }
  if (ok)
    os << "Passed all memtests for class " << _class << endl;
}

void gen_driver::test_memory() {
  if (!_memdin) return;
  mem_din::switch_off();
  if (nargs() > 1) 
    throw error(WrongNumArgs, nom_mod, WrongNumArgsMsg);
  if (nargs() == 1) {
    const string& _class = args(1);
    if (_tm.find(_class) == _tm.end())
      throw error(WrongTypeArgs, nom_mod, WrongTypeArgsMsg);
    test_memory(_class);
  } else {
    for (MemTestTbl::iterator it = _tm.begin();
	 it != _tm.end(); ++it)
      test_memory(it -> first);
  }
}

bool gen_driver::generic_memtest(void (*_build)(void*&), const string& _class,
				 const string& _msg) {
  int nchunks, nbytes;
  if (!_memdin) return true;
  mem_din::switch_off();
  void* p = NULL;
  ostream& os = get_ostream();
  string header = "Memory test::" + _msg + "::" + _class;
  os << header << endl;
  try {
    mem_din::switch_on();
    mem_din::set_parameters(100000, 1000000);
    _build(p);
    nchunks = mem_din::nr_chunks();
    nbytes = mem_din::nr_bytes();
    _dtor[_class](p);
    mem_din::switch_off();
  } catch(const error& e) {
    mem_din::switch_off();
    os << header << " FAILURE [" << e << "]" << endl;
    return false;
  }
  
  os << "*Num. chunks::" 
     << _class << " = " << nchunks << endl;
  os << "*Num. bytes::" 
     << _class <<" = " << nbytes << endl; 
  int nc = nchunks - 1; bool ok = true;
  while (nc >= 0 && ok) {
    try {
      #ifdef _DEBUG
      cout << "Testing " << nc << " chunks in " << header << endl;
      mem_din::print_memory_status_report(cout, 1);
      #endif
      p = NULL;
      mem_din::switch_on();
      mem_din::set_parameters(nc, nbytes);
      _build(p);
      _dtor[_class](p);
      mem_din::switch_off();
    } catch(const error& e) {
      if (e.codigo() != mem_din::FaltaMemoriaDin) {
	os << header << " FAILURE [" << e << "]" << endl;
	ok = false;
      }
      if (p != NULL) 
	_dtor[_class](p);
      mem_din::switch_off();
    }
    --nc;
  }
  if (ok) 
    os << header << " OK" << endl;
  return ok;
}
  
bool gen_driver::copyctor_memtest(void (*_build)(void*&), 
				  const string& _class) { 
  int nchunks1, nchunks, nbytes; //nchunks2

  if (!_memdin) return true;

  mem_din::switch_off();

  void* p1 = NULL; void* p2 = NULL; 
  ostream& os = get_ostream();
  string header = "Memory test::copyctor::" + _class;
  try {
    mem_din::switch_on();
    mem_din::set_parameters(100000, 1000000);
    _build(p1);
    nchunks1 = mem_din::nr_chunks();
    p2 = _copyctor[_class](p1);
    //nchunks2 = mem_din::nr_chunks() - nchunks1;
    
    nchunks = mem_din::nr_chunks();
    nbytes = mem_din::nr_bytes();
    
    _dtor[_class](p1);
    _dtor[_class](p2);
    mem_din::switch_off();
  } catch(const error& e) {
    os << header << " FAILURE" << endl;
    mem_din::switch_off();
    return false;
  }
  
  os << "*Num. chunks::" 
     << _class << " = " << nchunks << endl;
  os << "*Num. bytes::" 
     << _class <<" = " << nbytes << endl; 
  
  int nc = nchunks - 1; bool ok = true; bool buildok;
  while (nc >= nchunks1 && ok) {
    try {
      p1 = p2 = NULL;
      buildok = false;
      mem_din::switch_on();
      mem_din::set_parameters(nc, 1000000);
      _build(p1);
      buildok = true;
      p2 = _copyctor[_class](p1);
      _dtor[_class](p1);
      _dtor[_class](p2);
      mem_din::switch_off();
    } catch(const error& e) {
      if (e.codigo() != mem_din::FaltaMemoriaDin) {
	os << header << " FAILURE [" << e << "]" << endl;
	ok = false;
      } else {
	if (buildok && mem_din::nr_chunks() != nchunks1) {
	  os << header << " FAILURE [copy was not cleanly destroyed]" << endl;
	  ok = false;
	}
	if (p1 != NULL) 
	  _dtor[_class](p1);
	if (p2 != NULL) 
	  _dtor[_class](p2);
      }
      mem_din::switch_off();
    }
    --nc;
  }
  if (ok) 
    os << header << " OK" << endl;
  return ok;
}
  

bool gen_driver::assgn_memtest(void (*_build1)(void*&), 
			       void (*_build2)(void*&), 
			       const string& _class) { 
  if (!_memdin) return true;
  int nc;
  bool ok = true;
  int size1, size2;
  void* p1 = NULL; void* p2 = NULL;
  
  ostream& os = get_ostream();
  string header = "Memory test::operator=::" + _class;
  try {
    mem_din::switch_on();
    mem_din::set_parameters(100000, 1000000);
    _build1(p1);
    size1 = mem_din::nr_chunks();
    _build2(p2);
    size2 = mem_din::nr_chunks() - size1;
    _dtor[_class](p1);
    _dtor[_class](p2);
    mem_din::switch_off();
  } catch(const error& e) {
    os << header << " FAILURE" << endl;
    mem_din::switch_off();
    return false;
  }
  
  nc = size1 + 2 * size2 - 1; bool buildok;
  while (nc >= size1 + size2 && ok) {
    mem_din::switch_on();
    mem_din::set_parameters(nc, 1000000);
    try {    
      buildok = false;
      p1 = p2 = NULL;
      _build1(p1);
      _build2(p2);
      buildok = true;
      _assignment[_class](p1, p2);
      _dtor[_class](p1);
      _dtor[_class](p2);
      mem_din::switch_off();
    } catch(error e) {
      if (e.codigo() != mem_din::FaltaMemoriaDin) {
	os << header << " FAILURE [" << e << "]" << endl;
	ok = false;
      } else {
	if (buildok && mem_din::nr_chunks() != size1 + size2) {
	  os << header << " FAILURE [something went wrong]" << endl;
	  ok = false;
	}
      }
      if (p1 != NULL) 
	_dtor[_class](p1);
      if (p2 != NULL) 
	_dtor[_class](p2);
      mem_din::switch_off();
    }
    --nc;
  }
  if (ok)
    os << header << " OK" << endl;
  return ok;
}
  

string gen_driver::build_help_message(const string& op ) {
  if (_funct.find(op) != _funct.end()) {

    if (_help.find(op) != _help.end() && _help[op] != "") 
      return _help[op];

    string helpmsg = "";
    if (_applies_to[op] != "*") {
      helpmsg = "[<" + _applies_to[op] + ">] ";
    }
    helpmsg += op;
    for (nat i = 0; i < _type_args[op].size(); ++i) {
      helpmsg += (" <" + _type_args[op][i] + ">");
    }
    return helpmsg;
  } else {
    return "Sintaxis general: [<obj>] operacion [<argumento(s)>]";
  }
}

void gen_driver::help() {
  if (nargs() > 1)
    throw error(WrongNumArgs, nom_mod, WrongNumArgsMsg);
  if (nargs() == 1) {
    const string& op = args(1);
    // si 'op' es el nombre de una funcion ...
    if (_funct.find(op) != _funct.end()) {
      get_ostream() << build_help_message(op) << endl;
    } else {
      // si 'op' no es una clase o '*'
      if (_dtor.find(op) == _dtor.end())
	throw error(WrongTypeArgs, nom_mod, 
		    WrongTypeArgsMsg); 
      // 'op' debe ser el nombre de una clase ...
      get_ostream() << "-----------------------------------------------" << endl;
      get_ostream() << "Operaciones disponibles para la clase: " << op << endl;
      
      HelpTbl::const_iterator it = _help.begin();
      while (it != _help.end()) {
	if (_applies_to[it -> first] == op && it -> first[0] != '_') {
	  string helpmsg = build_help_message(it -> first);
	  get_ostream() << helpmsg << endl;
	}
	++it;
      }
      get_ostream() << "-----------------------------------------------" << endl;
    }
  } else {
  // nargs() == 0
    get_ostream() << "-----------------------------------------------" << endl;
    get_ostream() << "Operaciones disponibles:" << endl;
    
    get_ostream() << "# <comentario>" << endl;
    get_ostream() << "% <comando Unix>" << endl;
    
    HelpTbl::const_iterator it = _help.begin();
    while (it != _help.end()) {
      if (it -> first[0] != '_') {
	string helpmsg = build_help_message(it -> first);
	get_ostream() << helpmsg << endl;
      }
      ++it;
    }
    get_ostream() << "-----------------------------------------------" << endl;
  }
}

void gen_driver::list_objects() {
#ifdef _DEBUG
  cout << "gen_driver::list_objects()" << endl;
#endif
  if (nargs() > 1)
    throw error(WrongNumArgs, nom_mod, WrongNumArgsMsg);
  const string* theclass = NULL;
  get_ostream() << "-----------------------------------------------" << endl;
  if (nargs() == 0)
    get_ostream() << "Objetos en el sistema:" << endl;
  else {
    theclass = &args(1);
    // si *theclass no es una clase, entonces no hay objetos de ese tipo
    if (_dtor.find(*theclass) == _dtor.end())
	throw error(WrongTypeArgs, nom_mod, 
		    WrongTypeArgsMsg); 
    get_ostream() << "Objetos de la clase " << *theclass << " en el sistema:" << endl;
  }
  if (nargs() == 0) {
    ObjTbl::const_iterator it = _obj.begin();
    while (it != _obj.end()) {
      if (it -> second) {
	get_ostream() << it -> first << ": ";
	get_ostream() << _type[it -> first];
	if (it -> first == _curr_obj)
	  get_ostream() << " <=";
	get_ostream() << endl;
      }
      ++it;
    }
  } else {
    ObjTbl::const_iterator it = _obj.begin();
    while (it != _obj.end()) {
      if (it -> second && _type[it -> first] == *theclass) {
	get_ostream() << it -> first << ": ";
	get_ostream() << *theclass;
	if (it -> first == _curr_obj)
	  get_ostream() << " <=";
	get_ostream() << endl;
      }
      ++it;
    }
  }
  get_ostream() << "-----------------------------------------------" << endl;
}

void gen_driver::known_types() {
  get_ostream() << "-----------------------------------------------" << endl;
  get_ostream() << "Tipos en el sistema:" << endl;
  DtorTbl::const_iterator it = _dtor.begin();
  while (it != _dtor.end()) {
    get_ostream() << it -> first << endl;
    ++it;
  }
  get_ostream() << "-----------------------------------------------" << endl;
}

void gen_driver::apply() {
  mem_din::switch_off();
  const string& op = _il->args(1);
  ifstream f(_il->args(2).c_str());
  if (!f) throw error(NoFile, nom_mod, NoFileMsg);
  input_line L2;
  bool was_echoing = echoing();
  input_line::echo_off();
  try {
    L2.read(f);
    while (f) {
      input_line L1;
      L1.push_back(op);
      L1.push_back(L2);
      process_operation(&L1);
      L2.read(f);
    }
  } catch (error e) {
    if (was_echoing) 
      input_line::echo_on();
    throw;
  }
  if (was_echoing) 
    input_line::echo_on();
}

void gen_driver::iter() {
  mem_din::switch_off();
  int N = util::toint(_il->args(1));
  // const string& op = _il->args(2);
  input_line L(*_il);
  L.shift_args(2);
  bool was_echoing = echoing();
  _echoing = false;
  input_line::echo_off();
  for(int i = 0; i < N; ++i) {
     input_line Laux(L);
     process_operation(&Laux);
  }
  if (was_echoing) {
    input_line::echo_on();
    _echoing = true;
  }
}
 
void gen_driver::load() {
  mem_din::switch_off();
  ifstream loadf(args(1).c_str());
  if (!loadf) throw error(NoFile, nom_mod, NoFileMsg);
  input_line L1; L1.read(loadf);
  while (loadf) {  
    try {
      process_operation(&L1);
    } catch (error e) {
      get_ostream() << e << endl;
    }
    L1.read(loadf);
  }
}

void gen_driver::memory(bool _act) {
  _memdin = _act;
}

void gen_driver::curr_obj_name() {
  get_ostream() << _curr_obj << endl;
}

void gen_driver::select_curr_obj() {
  _curr_obj = _il->args(1);
}


void gen_driver::applies_to() {
  if (_applies_to.find(_il->args(1)) != _applies_to.end()) 
    get_ostream() << _applies_to[_il->args(1)] << endl;
  else
    throw error(NoOp, nom_mod, NoOpMsg);
}

void gen_driver::echo_input() {
  const string& echoinp = _il->args(1);
  if (echoinp == "off")
    input_line::echo_off();
  else if (echoinp == "on")
    input_line::echo_on();
}

void gen_driver::echo_output() {
  const string& echoout = _il->args(1);
  if (echoout == "off")
    _echoing = false;
  else if (echoout == "on")
    _echoing = true;
}

void gen_driver::set_memory() {
  int max_chunks = util::toint(_il->args(1)); 
  int max_bytes = util::toint(_il->args(2));
  mem_din::set_parameters(max_chunks, max_bytes);
}

void gen_driver::print_memory() {
  int lv = util::toint(_il->args(1));
  if (lv < 0 || lv > 2) 
    throw error(WrongTypeArgs, nom_mod, 
                WrongTypeArgsMsg);
  mem_din::print_memory_status_report(get_ostream(), lv);
}

void gen_driver::timer_on() {
  util::start_time();
}

void gen_driver::timer_off() {
  get_ostream() << util::stop_time() << " segs." << endl;
}

bool gen_driver::has_type(int i) {
  return _type.find(_il->args(i)) != _type.end();
}

const string& gen_driver::object_type(const string& obj_name) {
  if (_type.find(obj_name) == _type.end()) {
    throw error(NoObj, nom_mod, NoObjMsg);
  }
  return _type[obj_name];
}

const string& gen_driver::object_type(int i) {
  if (_type.find(_il->args(i)) == _type.end()) {
    throw error(NoObj, nom_mod, NoObjMsg);
  }
  return _type[_il->args(i)];
}

const string& gen_driver::object_type() {
  return _type[_il->object()];
}

const string& gen_driver::args(int i) {
  return _il->args(i);
}

nat gen_driver::nargs() {
  return _il->nargs();
}

void gen_driver::go() {
  input_line L;
  L.read(get_istream());
  while (get_istream() && L.args(1) != "exit" && L.args(1) != "quit" &&
	 L.args(1) != "ex") {
    try {
      process_operation(&L);
    } catch (error e) {  
      get_ostream() << e << endl;
    }    
    L.read(get_istream());
  }
  _il = NULL;
}

void gen_driver::add_call(const string& fname, 
			  DriverFunction f, 
			  const string& applies_to,
			  const string& type_args,
			  const string& helpmsg) {
  _funct[fname] = f;
  _help[fname] = helpmsg;
  _applies_to[fname] = applies_to;

#ifdef _DEBUG
  cout << "Registering function : " << fname << endl;
  cout << "Registered parameters: " << type_args << endl;
#endif
  util::split(type_args, _type_args[fname]);  
#ifdef _DEBUG
  cout << "Parsed               : " << endl;
  for (nat i = 0; i < _type_args[fname].size(); ++i)
    cout << "<" << _type_args[fname][i] << "> ";
  cout << endl;
#endif
}

void gen_driver::add_check(const string& tid, CheckFunction f) {
  _check[tid] = f;
}

gen_driver::gen_driver(const string& error_filename,
		       bool active_memdin,
                       bool echoing, istream& is, ostream& os) : 
  _il(NULL), _echoing(echoing), _memdin(active_memdin),
  _isdriv(is), _osdriv(os) {

#ifdef _DEBUG
  cout << "Starting gen_driver" << endl;
#endif

  if (error_filename != "") {
    ifstream fichero_errores(error_filename.c_str());
    if (!fichero_errores) 
      throw error(NoFile, nom_mod, NoFileMsg);
    error::load_messages(fichero_errores);
  }

  echoing ? input_line::echo_on() : input_line::echo_off();
  
  add_call("_version", &gen_driver_aux::version_libesin);
  add_call("_turn_memory", &gen_driver_aux::turn_memory, "*", "string");

  add_call("init", &gen_driver_aux::init, "*", "", "init <id> <class> <arg1> ...");
  add_call("initcopy", &gen_driver_aux::initcopy, "any", "any any any",
   "initcopy <id1> = <id2>: inicializa <id1> con una copia de <id2>");

  add_call("destroy", &gen_driver_aux::destroy, "any", "", 
   "[<id>] destroy: destruye el objeto <id> o el OC");

  add_call("clear_all", &gen_driver_aux::clear_all, "*", "", 
   "clear_all: destruye todos los objetos en el sistema");

  add_call("=", &gen_driver_aux::copy, "any", "any",
   "[<id1>] = <id2>: copia <id2> sobre el OC o sobre <id1>");

  add_call("curr_obj", &gen_driver_aux::curr_obj_name, "*", "",
   "curr_obj: imprime el nombre del objeto en curso");

  add_call("sel_curr_obj", &gen_driver_aux::select_curr_obj, "*", "any",
   "sel_curr_obj <id>: selecciona <id> como objeto en curso");

  add_call("applies_to", &gen_driver_aux::applies_to, "*", "string",
            "applies_to <op>: devuelve el tipo sobre el que se aplica <op>");

  add_call("known_types", &gen_driver_aux::known_types, "*", "",
	   "known_types: retorna la lista de tipos conocidos");

  add_call("start_t", &gen_driver_aux::timer_on, "*", "",
            "start_t: pone en marcha el crono");

  add_call("stop_t", &gen_driver_aux::timer_off, "*", "",
            "stop_t: detiene e imprime el crono"); 

  add_call("list_objects", &gen_driver_aux::list_objects, "*", "...",
            "list_objects [<class>]: lista todos los objetos en el sistema o los de la clase dada");

  add_call("help", &gen_driver_aux::help, "*", "...",
            "help|? [<op|clase>]: ayuda sobre las operaciones; si se indica 'op' da ayuda sobre una concreta, si se indica 'clase' da ayuda sobre las operaciones aplicables sobre la clase");

  add_call("?", &gen_driver_aux::help, "*", "...",
            "help|? [<op|clase>]: ayuda sobre las operaciones; si se indica 'op' da ayuda sobre una concreta, si se indica 'clase' da ayuda sobre las operaciones aplicables sobre la clase");

//    add_call("?", &gen_driver_aux::help_op, "*", "string",
//              "? <operacion>|<clase>: ayuda sobre la operacion o clase");

  add_call("load", &gen_driver_aux::load, "*", "string",
	    "load <filename>: lee instrucciones desde el fichero indicado");

  add_call("apply", &gen_driver_aux::apply, "*", "string string",
	    "apply <operacion> <filename>: aplica <op> sobre los argumentos en <filename>");

  add_call("iter", &gen_driver_aux::iter, "*", "...",
	    "iter <N> <op> <parametros>: aplica <op> sobre los argumentos N veces>");

  add_call("echo_input", &gen_driver_aux::echo_input, "*", "string",
"echo_input <on|off>: reproduce o no en el output las instrucciones del input");
  add_call("echo_output", &gen_driver_aux::echo_output, "*", "string", 
"echo_output <on|off>: escribe en el output el resultado de las operaciones");

  add_call("print_memory", &gen_driver_aux::print_memory, "*", "nat",
"print_memory|pm <n>: imprime un informe sobre el estado de memoria dinamica");

  add_call("pm", &gen_driver_aux::print_memory, "*", "nat",
"print_memory|pm <n>: imprime un informe sobre el estado de memoria dinamica");

  add_call("set_memory", &gen_driver_aux::set_memory, "*", "nat nat",
	    "set_memory <max_chunks> <max_bytes>: fija el tama�o de memoria");

  add_call("test_memory", &gen_driver_aux::test_memory, "*", "...",
            "test_memory [<class>]: pasa tests de memoria din�mica de la clase o de todas las clases");

  add_check("string", &gen_driver_aux::check_string);
  add_check("char", &gen_driver_aux::check_char);
  add_check("int", &gen_driver_aux::check_int);
  add_check("nat", &gen_driver_aux::check_nat);
  add_check("double", &gen_driver_aux::check_double);

#ifdef _DEBUG
  cout << "gen_driver started" << endl;
#endif
}

gen_driver::~gen_driver() {
    ObjTbl::const_iterator ito = _obj.begin();
    
    if (_memdin)
      mem_din::switch_on();
    while (ito != _obj.end()) {
#ifdef DEBUG
      cout << "Destroying object " << ito->first << " of type " << _type[ito->first] << endl;
#endif
      DtorFunction destruye = _dtor[_type[ito -> first]];
      destruye(ito -> second);
      ito++;
    }
    mem_din::switch_off();
    delete _null_stream;
    delete _il;
}

// ==========================================================================
// privadas

void gen_driver::process_operation(input_line* L) 
{
#ifdef _DEBUG
  cout << "gen_driver::process_operation" << endl;
#endif
  if (_funct.find(L->args(1)) == _funct.end()) { 
#ifdef _DEBUG
    cout << "el primer argumento no es la operacion ... " << endl;
#endif
    if (L->nargs() < 2 || _funct.find(L->args(2)) == _funct.end()) {
#ifdef _DEBUG
    cout << "el segundo argumento tampoco lo es!" << endl;
    cout << "NoOp = " << NoOp << endl;
    cout << "nom_mod= " << nom_mod << endl;
    cout << "NoOpMsg = " << NoOpMsg << endl;
#endif
      throw error(NoOp, "gen_driver", NoOpMsg);
    }
    if (_obj.find(L->args(1)) == _obj.end()) {
#ifdef _DEBUG
    cout << "el primer argumento no es la operacion ni un objeto!" << endl;
#endif
      throw error(NoObj, nom_mod, NoObjMsg);
    }
    L->set_object(L->args(1)); L->set_op(L->args(2)); 
    L->shift_args(3);
  } else {
    L->set_object(_curr_obj); L->set_op(L->args(1)); 
    L->shift_args(2);
  }
  // las comprobaciones solo se aplican a operaciones != init
  // y != initcopy
  const string& op = L->op();
  const string& obj_name = L->object();

#ifdef _DEBUG
  cout << "op = " << op << endl;
  cout << "obj_name = " << obj_name << endl;
#endif

  if (op != "init" && op != "initcopy") {
    
#ifdef _DEBUG
    cout << "L->nargs() = " << L-> nargs() << endl;
    cout << "_type_args[op].size() = " << _type_args[op].size() << endl;
#endif
    if (_type_args[op].size() != 0 && 
        _type_args[op][0] != "..." && 
        L->nargs() != _type_args[op].size()) 
      throw error(WrongNumArgs, nom_mod, WrongNumArgsMsg);
#ifdef _DEBUG
    cout << "chequeo numero argumentos" << endl;
#endif
    if (_applies_to[op] != "*" 
        && _obj.find(obj_name) == _obj.end()) {
      throw error(NoObj, nom_mod, NoObjMsg);
    }
#ifdef _DEBUG
    cout << "chequeo que se aplica a objeto o es *" << endl;
#endif
    if (_applies_to[op] != "*" && _applies_to[op] != "any" &&
        _applies_to[op] != _type[obj_name])
      throw error(WrongTypeObj, nom_mod, WrongTypeObjMsg);
#ifdef _DEBUG
    cout << "chequeo que se aplica sobre el tipo de objeto adecuado" << endl;
#endif
    if (_type_args[op].size() > 0 && _type_args[op][0] != "...") {
      // chequeo de tipos de argumentos
      for (nat i = 0; i < _type_args[op].size(); ++i) { 
	if (_check.find(_type_args[op][i]) != _check.end()) {
	  // existe una funcion de chequeo
	  if(!_check[_type_args[op][i]](L->args(i+1)))
	    throw error(WrongTypeArgs, nom_mod, WrongTypeArgsMsg);
	} else {
	  // el argumento deberia ser un identificador ...
	  if (_type_args[op][i] != _type[L->args(i+1)] && 
	      _type_args[op][i] != "any")
	    throw error(WrongTypeArgs, nom_mod, WrongTypeArgsMsg);
	    
	  if (_type_args[op][i] != "any" && 
	      _obj.find(L->args(i+1)) == _obj.end() && op != "initcopy") {
	    throw error(NoObj, nom_mod, NoObjMsg);
	  }
        }
       }
    }
  }
  
#ifdef _DEBUG
  cout << "todos los chequeos" << endl;
  cout << "invocando funcion" << endl;
#endif
  _il = L;
  if (_memdin)
    mem_din::switch_on();
  try{
    _funct[op](*this);
  } catch(error) {
    throw;
  }
  mem_din::switch_off();
}
