#include "token.hpp"

//funciona

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

token::token(codi cod /*= NULLTOK*/) throw(error)
{
  if (cod == CT_ENTERA)
  {
    throw(11);
  }
  else if (cod == CT_RACIONAL)
  {
    throw(11);
  }
  else if (cod == CT_REAL)
  {
    throw(11);
  }
  else if (cod == VARIABLE)
  {
    throw(11);
  }
  else
  {
    id_ = cod;
  }
} 
token::token(int n) throw(error)
{
  id_ = CT_ENTERA;
  valor.enter_ = n;
}
token::token(const racional &r) throw(error)
{
  id_ = CT_RACIONAL;
  valor.racional_ = r;
}
token::token(double x) throw(error)
{
  id_ = CT_REAL;
  valor.real_ = x;
}
token::token(const string &var_name) throw(error)
{
  if (var_name == "unassign" or var_name == "e" or var_name == "log" or
      var_name == "exp" or var_name == "sqrt" or var_name == "evalf")
  {
    throw(11);
  }
  id_ = VARIABLE;
  valor.variable_ = var_name;
}

// Constructora por còpia, assignació i destructora.
token::token(const token &t) throw(error)
{
  id_ = t.id_;
  if (id_ == CT_ENTERA)
  { // igualar els dos valors.
    throw(11);
  }
  else if (id_ == CT_RACIONAL)
  {
    throw(11);
  }
  else if (id_ == CT_REAL)
  {
    throw(11);
  }
  else if (id_ == VARIABLE)
  {
    throw(11);
  }
}
token &token::operator=(const token &t) throw(error)
{
  id_ = t.id_;
  if (id_ == CT_ENTERA)
  { // igualar els dos valors.
    throw(11);
  }
  else if (id_ == CT_RACIONAL)
  {
    throw(11);
  }
  else if (id_ == CT_REAL)
  {
    throw(11);
  }
  else if (id_ == VARIABLE)
  {
    throw(11);
  }
  return *this;
}
token::~token() throw()
{
  id_ = NULLTOK;
}

/*Consultores: Retornen respectivament el codi i el valor (en el cas de
  constants enteres, racionals o reals) o l'identificador (en el cas de
  variables). Es produeix un error si apliquem una consultora inadequada
  sobre un token, p.e. si apliquem valor_enter sobre un token que no sigui
  una CT_ENTERA.*/
token::codi token::tipus() const throw()
{
  return id_;
}
int token::valor_enter() const throw(error)
{
  return valor.enter_;
}
racional token::valor_racional() const throw(error)
{
  return valor.racional_;
}
double token::valor_real() const throw(error)
{
  return valor.real_;
}
string token::identificador_variable() const throw(error)
{
  return valor.variable_;
}

/*Igualtat i desigualtat entre tokens. Dos tokens es consideren iguals si els
  seus codis ho són i si 1) en cas de ser CT_ENTERA, CT_RACIONAL o CT_REAL,
  els seus valors són iguals i 2) en cas de ser VARIABLE, tenen el mateix
  nom. */
bool token::operator==(const token &t) const throw()
{
  bool ret = false;
  if (id_ != t.id_)
  {
    throw(13);
  }
  if (id_ == CT_ENTERA)
  {
    if (id_ == t.id_ and valor.enter_ == t.valor.enter_)
    {
      ret = true;
    }
    else
    {
      ret = false;
    }
  }
  return ret;
}
bool token::operator!=(const token &t) const throw()
{
  bool ret = false;
  if (id_ != t.id_)
  {
    throw(13);
  }
  if (id_ == CT_ENTERA)
  {
    if (id_ == t.id_ and valor.enter_ != t.valor.enter_)
    {
      ret = true;
    }
    else
    {
      ret = false;
    }
  }
  return ret;
}

/*Precedència entre tokens. L'operador > retorna cert si i només si el token
  és un operador amb major precedència que l'operador del token t. Si algun
  dels tokens no és un operador es produeix un error.*/
bool token::operator>(const token &t) const throw(error)
{
  bool ret = false;
  if (id_ != t.id_)
  {
    throw(13);
  }
  if (id_ == CT_ENTERA)
  {
    if (valor.enter_ > t.valor.enter_)
    {
      ret =  true;
    }
    else
    {
      ret = false;
    }
  }
  return ret;
}
bool token::operator<(const token &t) const throw(error)
{
  bool ret = false;
  if (id_ != t.id_)
  {
    throw(13);
  }
  if (id_ == CT_ENTERA)
  {
    if (valor.enter_ < t.valor.enter_)
    {
      ret = true;
    }
    else
    {
      ret = false;
    }
  }
  return ret;
}
