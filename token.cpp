#include "token.hpp"

using namespace std;

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
  try
  {
    _valor = new int;
  }
  catch(...)
  {
    throw error(ConstructoraInadequada);
  }
  *(int *)_valor = n;
}
token::token(const racional &r) throw(error)
{
  _id = CT_RACIONAL;
  try
  {
    _valor = new racional;
  }
  catch(...)
  {
    throw error(ConstructoraInadequada);
  }
  racional rac = r;
  *(racional *)_valor = rac;
}
token::token(double x) throw(error)
{
  _id = CT_REAL;
  try
  {
    _valor = new double;
  }
  catch(...)
  {
    throw error(ConstructoraInadequada);
  }
  *(double *)_valor = x;
}
token::token(const string &var_name) throw(error)
{
  string s = var_name;
  _id = VARIABLE;
  if (check_variables(var_name))
  {
    cout << _id << endl;
    throw error(IdentificadorIncorrecte);
  }
  else
  {
    _valor = new string;
    *(string *)_valor = s;
  }
}

// Constructora por còpia, assignació i destructora.
token::token(const token &t) throw(error)
{
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    _valor = new int;
    _valor = t._valor;
  }
  else if (_id == CT_RACIONAL)
  {
    _valor = new racional;
    _valor = t._valor;
  }
  else if (_id == CT_REAL)
  {
    _valor = new double;
    _valor = t._valor;
  }
  else if (_id == VARIABLE)
  {
    _valor = new string;
    _valor = t._valor;
  }
  else
    throw error(ConstructoraInadequada);
}
token &token::operator=(const token &t) throw(error)
{
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    _valor = t._valor;
  }
  else if (_id == CT_RACIONAL)
  {
    _valor = t._valor;
  }
  else if (_id == CT_REAL)
  {
    _valor = t._valor;
  }
  else if (_id == VARIABLE)
  {
    _valor = t._valor;
  }
  else
    throw error(ConstructoraInadequada);
  return *this;
}
token::~token() throw()
{
  /*if (_id == CT_ENTERA)
  {
    delete *(int *)_valor;
  }
  else if (_id == CT_RACIONAL)
  {
    delete *(racional *)_valor;
  }
  else if (_id == CT_REAL)
  {
    delete *(double *)_valor;
  }
  else if (_id == VARIABLE)
  {
    delete *(string *)_valor;
  }*/
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
    return *(string *)_valor;
  }
}

/*Igualtat i desigualtat entre tokens. Dos tokens es consideren iguals si els
  seus codis ho són i si 1) en cas de ser CT_ENTERA, CT_RACIONAL o CT_REAL,
  els seus _valors són iguals i 2) en cas de ser VARIABLE, tenen el mateix
  nom. */
bool token::operator==(const token &t) const throw()
{
  if (_id != t._id) return false;
  else if(_id != CT_ENTERA and _id != CT_RACIONAL and _id != CT_REAL and _id != VARIABLE) return true;
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
  if ((_id == SUMA or _id == RESTA or _id == MULTIPLICACIO or _id == DIVISIO or
     _id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU or _id == EXPONENCIACIO or
     _id == SQRT or _id == LOG or _id == EXP or _id == OBRIR_PAR or _id == TANCAR_PAR) and
     (t._id == SUMA or t._id == RESTA or t._id == MULTIPLICACIO or t._id == DIVISIO or
     t._id == CANVI_DE_SIGNE or t._id == SIGNE_POSITIU or t._id == EXPONENCIACIO or
     t._id == SQRT or t._id == LOG or t._id == EXP or t._id == OBRIR_PAR or t._id == TANCAR_PAR))
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
  else
  {
    throw error(PrecedenciaEntreNoOperadors);
  }
}
bool token::operator<(const token &t) const throw(error)
{
  if ((_id == SUMA or _id == RESTA or _id == MULTIPLICACIO or _id == DIVISIO or
     _id == CANVI_DE_SIGNE or _id == SIGNE_POSITIU or _id == EXPONENCIACIO or
     _id == SQRT or _id == LOG or _id == EXP or _id == OBRIR_PAR or _id == TANCAR_PAR) and
     (t._id == SUMA or t._id == RESTA or t._id == MULTIPLICACIO or t._id == DIVISIO or
     t._id == CANVI_DE_SIGNE or t._id == SIGNE_POSITIU or t._id == EXPONENCIACIO or
     t._id == SQRT or t._id == LOG or t._id == EXP or t._id == OBRIR_PAR or t._id == TANCAR_PAR))
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
    else 
    {
      return false;
    }
  }
  else
  {
    throw error(PrecedenciaEntreNoOperadors);
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