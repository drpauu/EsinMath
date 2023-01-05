#include "token.hpp"

using namespace std;

// funciona

/*Constructores: Construeixen tokens pels operadors, les constants enteres,
  les constants racionals, les constants reals i les variables(el seu
  identificador), respectivament.

  La primera constructora s'utiliza para aquells tokens que són operadors,
  funcions predefinides, noms de comandes o símbols de ``puntuació''; per
  tant es produeix un error si el codi és CT_ENTERA, CT_RACIONAL, CT_REAL o
  VARIABLE.

  L'última constructora torna un error si l'string donat no és un
  identificador vàlid per una variable: ha d'estar format exclusivament per
  lletres majúscules, minúscules o caràcters de subratllat _. Dit d'una altra
  forma, només conté caràcters els codis ASCII dels quals estan entre 65
  ('A') i 90('Z'), entre 97 ('a') i 122 ('z') o el 95 ('_') i no pot
  coincidir amb un nom reservat: unassign, e, sqrt, log, exp i evalf.*/


/*token::data::data()
{
}

token::data::data(const data & d) throw()
{
}

data & token::data::operator=(const data & d) throw();
{
}

token::data::~data() throw();
{
}*/

token::token(codi cod /*= NULLTOK*/) throw(error)
{
  if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE)
    throw error(ConstructoraInadequada);
  else
    _id = cod;
}
token::token(int n) throw(error)
{
  _id = CT_ENTERA;
  //_valor._enter = n;
  _valor = new int;
  _valor = &n;
  cout << "valor enter: " << *(int *)_valor << endl;
}
token::token(const racional &r) throw(error)
{
  _id = CT_RACIONAL;
  //_valor._racional = r;
  _valor = new racional;
  racional rac = r;
  _valor = &rac;
}
token::token(double x) throw(error)
{
  _id = CT_REAL;
  //_valor._real = x;
  _valor = new double;
  _valor = &x;
}
token::token(const string &var_name) throw(error)
{
  string s = var_name;
  if (check_variables(var_name))
  {
    throw error(IdentificadorIncorrecte);
  }
  else
  {
    _id = VARIABLE;
    //_valor._variable = var_name;
    _valor = new string;
    _valor = &s;
  }
}

// Constructora por còpia, assignació i destructora.
token::token(const token &t) throw(error)
{
  //Fer per tots els codis
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    //_valor._enter = t._valor._enter;
    _valor = new int;
    _valor = t._valor;
  }
  else if (_id == CT_RACIONAL)
  {
    //_valor._racional = t._valor._racional;
    _valor = new racional;
    _valor = t._valor;
  }
  else if (_id == CT_REAL)
  {
    //_valor._real = t._valor._real;
    _valor = new double;
    _valor = t._valor;
  }
  else if (_id == VARIABLE)
  {
    //_valor._variable = t._valor._variable;
    _valor = new string;
    _valor = t._valor;
  }
}
token &token::operator=(const token &t) throw(error)
{
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    //Guardar en un int 
    //_valor._enter = t._valor._enter;
    _valor = t._valor;
  }
  else if (_id == CT_RACIONAL)
  {
    //_valor._racional = t._valor._racional;
    _valor = t._valor;
  }
  else if (_id == CT_REAL)
  {
    //_valor._real = t._valor._real;
    _valor = t._valor;
  }
  else if (_id == VARIABLE)
  {
    // valor._variable = t._valor._variable;
    _valor = t._valor;
  } // s'ha d'eliminar el _valor que te, en el cas que en tingui

  return *this;
}
token::~token() throw()
{
  _id = NULLTOK;
}

/*Consultores: Retornen respectivament el codi i el _valor (en el cas de
  constants enteres, racionals o reals) o l'identificador (en el cas de
  variables). Es produeix un error si apliquem una consultora inadequada
  sobre un token, p.e. si apliquem _valor_enter sobre un token que no sigui
  una CT_ENTERA.*/
token::codi token::tipus() const throw()
{
  return _id;
}
int token::valor_enter() const throw(error)
{
  if(_id != CT_ENTERA)
  {
    throw(ConsultoraInadequada);
  }
  else
  {
    //return _valor._enter;
    return *(int *)_valor;
  }
}
racional token::valor_racional() const throw(error)
{
  if(_id != CT_RACIONAL)
  {
    throw(ConsultoraInadequada);
  }
  else
  {
    //return _valor._racional;
    return *(racional *)_valor;
  }
}
double token::valor_real() const throw(error)
{
  if(_id != CT_REAL)
  {
    throw(ConsultoraInadequada);
  }
  else
  {
    //return _valor._real;
    return *(double *)_valor;
  }
}
string token::identificador_variable() const throw(error)
{
  if(_id != VARIABLE)
  {
    throw(ConsultoraInadequada);
  }
  else
  {
    //return _valor._variable;
    return *(string *)_valor;
  }
}

/*Igualtat i desigualtat entre tokens. Dos tokens es consideren iguals si els
  seus codis ho són i si 1) en cas de ser CT_ENTERA, CT_RACIONAL o CT_REAL,
  els seus _valors són iguals i 2) en cas de ser VARIABLE, tenen el mateix
  nom. */
bool token::operator==(const token &t) const throw()
{
  cout << "valor enter1: " << *(int *)_valor << " valor enter1: " << *(int *)_valor << endl;
  //cout << "valor racional: " << *(racional *)_valor << endl;
  //cout << "valor float: " << *(double *)_valor << endl;
  //cout << "valor string: " << *(string *)_valor << endl;
  if (_id != t._id) return false;
  if (_id == CT_ENTERA) return *(int *)_valor == *(int *)t._valor;
  if (_id == CT_RACIONAL) return *(racional *)_valor == *(racional *)t._valor;
  if (_id == CT_REAL) return *(double *)_valor == *(double *)t._valor;
  if (_id == VARIABLE) return *(string *)_valor == *(string *)t._valor;
  return false;
}
bool token::operator!=(const token &t) const throw()
{
  return not(*this == t);
}

/*Precedència entre tokens. L'operador > retorna cert si i només si el token
  és un operador amb major precedència que l'operador del token t. Si algun
  dels tokens no és un operador es produeix un error.*/
bool token::operator>(const token &t) const throw(error)
{
  if (_id != SUMA or _id != RESTA or _id != MULTIPLICACIO or _id != DIVISIO or
     _id != CANVI_DE_SIGNE or _id != SIGNE_POSITIU or _id != EXPONENCIACIO or
     _id != SQRT or _id != LOG or _id != EXP or _id != OBRIR_PAR or _id != TANCAR_PAR or
     t._id != SUMA or t._id != RESTA or t._id != MULTIPLICACIO or t._id != DIVISIO or
     t._id != CANVI_DE_SIGNE or t._id != SIGNE_POSITIU or t._id != EXPONENCIACIO or
     t._id != SQRT or t._id != LOG or t._id != EXP or t._id != OBRIR_PAR or t._id != TANCAR_PAR)
  { 
    throw error(PrecedenciaEntreNoOperadors);
  }
  else
  {
    if (_id == SUMA or _id == RESTA)
      return false;
    else if ((_id == MULTIPLICACIO or _id == DIVISIO) and
            (t._id != SUMA and t._id != RESTA))
      return false;
    else if ((_id == MULTIPLICACIO or _id == DIVISIO) and (t._id == SUMA or t._id == RESTA))
      return true;
    else if ((_id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU) and
            (t._id != SUMA and t._id != RESTA and t._id != MULTIPLICACIO and t._id != DIVISIO))
      return false;
    else if ((_id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU) and
            (t._id == SUMA or t._id == RESTA or t._id == MULTIPLICACIO or t._id == DIVISIO))
      return true;
    else if ((_id == EXPONENCIACIO or _id == SQRT or _id == LOG or _id == EXP) and
            (t._id == EXPONENCIACIO or t._id == SQRT or t._id == LOG or t._id == EXP 
            or t._id == OBRIR_PAR or t._id == TANCAR_PAR))
      return false;
    else if ((_id == EXPONENCIACIO or _id == SQRT or _id == LOG or _id == EXP) and
            (t._id != OBRIR_PAR and t._id != TANCAR_PAR))
      return true;
    else return false;
  }
}
bool token::operator<(const token &t) const throw(error)
{
  if (_id != SUMA or _id != RESTA or _id != MULTIPLICACIO or _id != DIVISIO or
     _id != CANVI_DE_SIGNE or _id != SIGNE_POSITIU or _id != EXPONENCIACIO or
     _id != SQRT or _id != LOG or _id != EXP or _id != OBRIR_PAR or _id != TANCAR_PAR or
     t._id != SUMA or t._id != RESTA or t._id != MULTIPLICACIO or t._id != DIVISIO or
     t._id != CANVI_DE_SIGNE or t._id != SIGNE_POSITIU or t._id != EXPONENCIACIO or
     t._id != SQRT or t._id != LOG or t._id != EXP or t._id != OBRIR_PAR or t._id != TANCAR_PAR)
  { 
    throw error(PrecedenciaEntreNoOperadors);
  }
  else
  {
    if ((_id == SUMA or _id == RESTA) and
       (t._id != SUMA and t._id != RESTA))
      return true;
    else if ((_id == SUMA or _id == RESTA) and (t._id == SUMA or t._id == RESTA))
      return false;
    else if ((_id == MULTIPLICACIO or _id == DIVISIO) and
            (t._id != SUMA and t._id != RESTA and t._id != MULTIPLICACIO and t._id != DIVISIO))
      return true;
    else if ((_id == MULTIPLICACIO or _id == DIVISIO) and
            (t._id == SUMA or t._id == RESTA or t._id == MULTIPLICACIO or t._id == DIVISIO))
      return false;
    else if ((_id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU) and
            (t._id == SQRT or t._id == LOG or t._id == EXP or t._id == OBRIR_PAR or t._id == TANCAR_PAR))
      return true;
    else if ((_id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU) and
            (t._id == SUMA or t._id == RESTA or t._id == MULTIPLICACIO or t._id == DIVISIO or
            t._id == CANVI_DE_SIGNE or t._id == SIGNE_POSITIU))
      return false;
    else if ((_id == EXPONENCIACIO or _id == SQRT or _id == LOG or _id == EXP) and
            (t._id == OBRIR_PAR or t._id == TANCAR_PAR))
      return true;
    else return false;
  }
}

bool token::check_variables(string var)
{
  char lletra;
  bool incorrecte = false;
  for (unsigned int i = 0; i < var.length() and not incorrecte; i++)
  {
    lletra = var[i];
    if (!isalpha(lletra) and int(lletra) != 95)
    {
      incorrecte = true;
    }
  }
  if(not incorrecte)
  {
    if(var == "unassign")
      incorrecte = true;
    else if(var == "e")
      incorrecte = true;
    else if(var == "sqrt")
      incorrecte = true;
    else if(var == "log")
      incorrecte = true;
    else if(var == "exp")
      incorrecte = true;
    else if(var == "evalf")
      incorrecte = true;
  }
  return incorrecte;
}
/*
int token::prioritat_operacio()
// Pre: El token ha de ser un operador
// Post: Retorna del 1 al 4 un enter que representa la prioritat de l'operador.
//       Si el token no és cap operador retornarà un 0(error).
{
    if (_id == (SUMA or RESTA))
        return 1;
    else if (_id == (MULTIPLICACIO or DIVISIO))
        return 2;
    else if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU))
        return 3;
    else if (_id == (EXPONENCIACIO or SQRT or LOG or EXP))
        return 4;
    else
        return 0;
}*/

int token::numero_operadors()
// Pre: El token ha de ser un operador
// Post: Retorna un enter que representa el nombre d'operands sobre el que l'operador
//       actua. Si el token no és cap operador retornarà un 0, per exemple en el cas
//       de les constants o variables. Si el token no és vàlid en una expressió retorna -1.
{
  if (_id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU or _id == SQRT or _id == LOG or _id == EXP)
    return 1;
  else if (_id == SUMA or _id == RESTA or _id == MULTIPLICACIO or _id == DIVISIO or _id == EXPONENCIACIO)
    return 2;
  else if (_id == CT_ENTERA or _id == CT_RACIONAL or _id == CT_REAL or _id == CT_E or _id == VARIABLE)
    return 0;
  else
    return -1;
}