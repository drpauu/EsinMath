// $Id: error.cpp 108 2005-04-17 20:02:00Z conrado $

#include <string>
#include <iostream>
#include <map>
#include <esin/error>
#include <esin/util>

#define MAX_LINE_LENGTH 1024

using namespace std;

map<int,string> error::tabla_mensajes;
map<int,string> error::tabla_modulos;

error::error(int codigo, const string& nom_mod, const string& msg) 
     : _codigo(codigo), _modulo(nom_mod), _mensaje(msg) {
#ifdef _DEBUG
  cout << "construyendo objeto error" << endl;
#endif
    if (_mensaje == "" && tabla_mensajes.find(codigo) != tabla_mensajes.end())
      _mensaje = tabla_mensajes[codigo];
    if (_modulo == "" && tabla_modulos.find(codigo) != tabla_modulos.end())
      _modulo = tabla_modulos[codigo];
}

string error::modulo() const { 
  return _modulo; 
}

int error::codigo() const { 
  return _codigo; 
}

string error::mensaje() const { 
  return _mensaje; 
}

void error::print(ostream& out) const { 
  out << "Error::" << _modulo << ":" << _codigo << ":" << _mensaje; 
}

void error::load_messages(istream& is) {
  int c; string msg; 
  char line[MAX_LINE_LENGTH];
  vector<string> args;

#ifdef _DEBUG
  cout << "Cargando la tabla de mensajes de error ..." << endl;
#endif

  while (is) {
    args.clear();
    if (is.getline(line, MAX_LINE_LENGTH)) {
      util::split(line, args);
      if (args.size() >= 3 && args[0][0] != '#') {
        c = util::toint(args[0]);
        tabla_modulos[c] = args[1];
        msg = "";
        for (util::nat i = 2; i < args.size() - 1; ++i)
          msg += args[i] + " ";
        tabla_mensajes[c] = msg + args[args.size() - 1];
      }
    }
  }
}

ostream& operator<<(ostream& os, const error& e) {
  e.print(os);
  return os;
}
