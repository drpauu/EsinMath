// $Id: util.cpp 82 2005-03-03 09:20:28Z conrado $

#include <string>
#include <esin/error>
#include <esin/util>
#include <sys/time.h>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cstdio>
#include <vector>

namespace util {
  using namespace std;
  static const int MAX_BUFF = 200;
  char tmp_buf[MAX_BUFF + 1];
  clock_t tinit;

  string tostring(long int n) throw() {
    sprintf(tmp_buf, "%ld", n);
    return string(tmp_buf);
  };
  
  string tostring(int n) throw() {
    sprintf(tmp_buf, "%d", n);
    return string(tmp_buf);
  };
  
  string tostring(double x) throw() {
    sprintf(tmp_buf, "%g", x);
    return string(tmp_buf);
  };
  
  bool is_nat(const string& s, int i, int j) throw() {
    if (i == j) return false;
    while (i < j && isdigit(s[i])) ++i;
    return (i == j); 
  };
  
  bool is_nat(const string& s) throw() {
    return is_nat(s, 0, s.length()); 
  };
  
  bool is_int(const string& s) throw() {
    if (s.length() == 0) 
      return false;
    if (!isdigit(s[0]) && s[0] != '+' && s[0] != '-')
      return false;
    int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    return is_nat(s, i, s.length());
  };
  
  bool is_double(const string& s) throw() {
    if (s.length() == 0) 
      return false; 
    if (!isdigit(s[0]) && s[0] != '+' 
	&& s[0] != '-' && s[0] != '.')
      return false;
    string pe, pf, exp;
    int l = s.length();
    int i = 0;
    while (i < l && s[i] != '.' && s[i] != 'e' && s[i] != 'E')
      pe += s[i++];
    if (i < l && s[i] == '.') {
      i++;
      while (i < l && s[i] != 'e' && s[i] != 'E')
	pf += s[i++];
    }
    if (i < l - 1 && (s[i] == 'e' || s[i] == 'E')) {
      i++; 
      while (i < l)
	exp += s[i++];
    }
    if (pe != "" && !is_int(pe)) 
      return false;
    if (!is_nat(pf, 0, pf.length()))
      return false;
    if (exp != "" && !is_int(exp)) 
      return false;
    return true;
  }

  int toint(const string& s) throw (error) {
    if (!is_int(s))
      throw error(90, "util", "Cannot convert string to int");
    int n = atoi(s.c_str());
    if (errno == ERANGE) 
      throw error(90, "util", "Cannot convert string to int");
    return n;
  };
  
  double todouble(const string& s) throw (error) {
    if (!is_double(s))
      throw error(91, "util", "Cannot convert string to int");
    double d = atof(s.c_str());
    if (errno == ERANGE) 
      throw error(91, "util", "Cannot convert string to double");
    return d;
  };
  
  void start_time() throw() {
    tinit = clock();
  };

  double stop_time() throw() {
    clock_t tend = clock();
    if (tend >= 0)
      return (double) (tend-tinit) / (double) CLOCKS_PER_SEC;
    return 0.0;
  };
  
  byte pack(const string& s) throw(error) {
    if (s.length() != 8)
      throw error(97, "util", "String does not represent a byte");
    byte c = 0;
    for (int i = 0; i < 8; ++i)
      if (s[i] == '1') 
	c = (c << 1) | 01;
      else if (s[i] == '0')
	c <<= 1;
      else
	throw error(97, "util", "String does not represent a byte");
    return c;
  }

  string unpack(byte c) throw() {
    string s = "";
    while (c != 0) {
      if (c & 01) 
	s = "1" + s;
      else
	s = "0" + s;
      c >>= 1;
    }
    while (s.length() < 8)
      s = "0" + s;
    return s;
  }

  int get_next_param(char* line, int& pos, string& s) {
    char c = line[pos]; bool something_read = false;
#ifdef _DEBUG
    cout << "util::get_next_param: initial char read is " << c;
    cout << " at pos " << pos << endl;
#endif
    
    s = "";
    while (c != '\0' && isspace(c)) c = line[++pos];
#ifdef _DEBUG
    cout << "util::get_next_param: reached end of string or non-space = " << c;
    cout << " at pos " << pos << endl;
#endif
    
    if (c != '\"') {
      while (c != '\0' && !isspace(c)) { s += c; c = line[++pos]; }
#ifdef _DEBUG
      cout << "util::get_next_param: reached end of string or space = " << c;
      cout << " at pos " << pos << endl;
      cout << "now s = " << s << endl;
#endif
      something_read = (s != "");
    }
    else {
      bool fin = false; 
      something_read = true;
      pos++; c = line[pos];
      do {
	char slash = '\\';
	while (c != '\0' && c != '\"' && c != slash) { 
	  s += c; c = line[++pos]; 
	}
	if (c != slash) 
	  { fin = true; if (c != '\0') pos++; }
	else {
	  if (c == slash && line[pos + 1] == '\"') 
	    { s += '\"'; pos += 2; c = line[pos]; }
	  else 
	    { s += slash; pos++; c = line[pos]; }
      }
      } while (!fin);
    }
    return ((c == '\0' && !something_read) ? -1 : pos);
  }
  
  /*
    int get_next_param(char* line, int& pos, string& s, char sep) {
    char c = line[pos]; bool something_read = false;
    #ifdef _DEBUG
    cout << "util::get_next_param: initial char read is " << c;
    cout << " at pos " << pos << endl;
    #endif

    s = "";
    while (c != '\0' && c == sep) c = line[++pos];
    #ifdef _DEBUG
    cout << "util::get_next_param: reached end of string or non-space = " << c;
    cout << " at pos " << pos << endl;
    #endif
    
    if (c != '\"') {
    while (c != '\0' && c != sep) { s += c; c = line[++pos]; }
    #ifdef _DEBUG
    cout << "util::get_next_param: reached end of string or space = " << c;
    cout << " at pos " << pos << endl;
    cout << "now s = " << s << endl;
    #endif
    something_read = (s != "");
    }
    else {
    bool fin = false; 
    something_read = true;
    pos++; c = line[pos];
    do {
    char slash = '\\';
      while (c != '\0' && c != '\"' && c != slash) { 
        s += c; c = line[++pos]; 
      }
      if (c != slash) 
        { fin = true; if (c != '\0') pos++; }
      else {
        if (c == slash && line[pos + 1] == '\"') 
          { s += '\"'; pos += 2; c = line[pos]; }
        else 
          { s += slash; pos++; c = line[pos]; }
      }
    } while (!fin);
  }
  return ((c == '\0' && !something_read) ? -1 : pos);
}

void split(const string& s, vector<string>& x, char c) throw() {
  int pos = 0; 

  for (nat i = 0; i < s.length(); ++i) tmp_buf[i] = s[i];
  tmp_buf[s.length()] = '\0';

  string field = ""; 
  while (get_next_param(tmp_buf, pos, field, c) > 0) {
#ifdef _DEBUG
    cout << "util::split: next token read is " << field << endl;
#endif
    x.push_back(field);
  }
}

void split(char* line, vector<string>& x, char c) throw() {
  int pos = 0; string field; 
  while (get_next_param(line, pos, field, c) > 0) 
    x.push_back(field);
}
*/

  void split(const string& s, vector<string>& x) throw() {
    int pos = 0; 
    
    for (nat i = 0; i < s.length(); ++i) tmp_buf[i] = s[i];
    tmp_buf[s.length()] = '\0';
    
    string field = ""; 
    while (get_next_param(tmp_buf, pos, field) > 0) {
#ifdef _DEBUG
      cout << "util::split: next token read is " << field << endl;
#endif
      x.push_back(field);
  }
  }
  
  void split(char* line, vector<string>& x) throw() {
    int pos = 0; string field; 
    while (get_next_param(line, pos, field) > 0) 
      x.push_back(field);
  }
  
#define TWOP31 ((unsigned long) 0x80000000)
  
  double Random::operator()() throw() {
    return double(Random::rand()) / double(TWOP31);
  };
  
long Random::operator()(long a, long b) throw (error) {
  if (a > b || a < 0) 
    throw error(95, "util::Random", "Bad range for random integer");
  return operator()(b - a + 1) + a;
};
  
  long Random::operator()(long n) throw (error) {
    if (n <= 0) 
      throw error(95, "util::Random", "Bad range for random integer");
    register unsigned long t = TWOP31 - (TWOP31 % n);
    register long r;
    do {
      r = Random::rand();
    } while (t <= (unsigned long) r);
    return r % n;
  };
  
  Random::Random(long int seed) {
    A[0] = -1;
    for (int i = 1; i<= 55; ++i) A[i] = 0;
    init_rand(seed);
  };
  
         
  // difference modulo 2^31
#define mod_diff(x,y) (((x) - (y)) & 0x7fffffff)
  
  long Random::cycle() {
    int i,j;
    for (i = 1, j = 32; j < 56; ++i, ++j)
      A[i] = mod_diff(A[i], A[j]);
    for (j = 1; i < 56; ++i, ++j)
      A[i] = mod_diff(A[i], A[j]);
    fptr = &A[54];
    return A[55];
  };
  
  
  void Random::init_rand(long seed) {
    register long i;
    register long prev = seed, next = 1;
    seed = prev = mod_diff(prev,0);
    A[55] = prev;
    for (i = 21; i; i = (i + 21) % 55) {
      A[i] = next;
      next = mod_diff(prev,next);
      if (seed & 1) seed = 0x40000000 + (seed >> 1);
    else seed >>= 1;
      next = mod_diff(next,seed);
      prev = A[i];
    }
    cycle(); cycle(); cycle(); cycle();
  };
}
