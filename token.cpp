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

token::token(codi cod /*= NULLTOK*/) throw(error)
{
  _id = cod;
}
token::token(int n) throw(error)
{
  _id = CT_ENTERA;
  _valor._enter = n;
}
token::token(const racional &r) throw(error)
{
  _id = CT_RACIONAL;
  _valor._racional = r;
}
token::token(double x) throw(error)
{
  _id = CT_REAL;
  _valor._real = x;
}
token::token(const string &var_name) throw(error)
{
  if (check_variables(var_name))
  {
    throw(11);
  }
  else
  {
    _id = VARIABLE;
    _valor._variable = var_name;
  }
}

// Constructora por còpia, assignació i destructora.
token::token(const token &t) throw(error)
{
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    _valor._enter = t._valor._enter;
  }
  else if (_id == CT_RACIONAL)
  {
    _valor._racional = t._valor._racional;
  }
  else if (_id == CT_REAL)
  {
    _valor._real = t._valor._real;
  }
  else if (_id == VARIABLE)
  {
    _valor._variable = t._valor._variable;
  }
}
token &token::operator=(const token &t) throw(error)
{
  _id = t._id;
  if (_id == CT_ENTERA)
  {
    _valor._enter = t._valor._enter;
  }
  else if (_id == CT_RACIONAL)
  {
    _valor._racional = t._valor._racional;
  }
  else if (_id == CT_REAL)
  {
    _valor._real = t._valor._real;
  }
  else if (_id == VARIABLE)
  {
    _valor._variable = t._valor._variable;
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
  return _valor._enter;
}
racional token::valor_racional() const throw(error)
{
  return _valor._racional;
}
double token::valor_real() const throw(error)
{
  return _valor._real;
}
string token::identificador_variable() const throw(error)
{
  return _valor._variable;
}

/*Igualtat i desigualtat entre tokens. Dos tokens es consideren iguals si els
  seus codis ho són i si 1) en cas de ser CT_ENTERA, CT_RACIONAL o CT_REAL,
  els seus _valors són iguals i 2) en cas de ser VARIABLE, tenen el mateix
  nom. */
bool token::operator==(const token &t) const throw()
{
  bool ret = false;
  if (_id != t._id)
  {
    throw(13);
  }
  if (_id == CT_ENTERA)
  {
    if (_id == t._id and _valor._enter == t._valor._enter)
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
  if (_id != t._id)
  {
    throw(13);
  }
  if (_id == CT_ENTERA)
  {
    if (_id == t._id and _valor._enter != t._valor._enter)
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
  if ((_id and t._id) != (SUMA or
                          RESTA or
                          MULTIPLICACIO or
                          DIVISIO or
                          CANVI_DE_SIGNE or
                          SIGNE_POSITIU or
                          EXPONENCIACIO or
                          SQRT or
                          LOG or
                          EXP))
    throw(14);
  else
  {
    if (_id == (SUMA or RESTA))
      return false;
    else if (_id == (MULTIPLICACIO or DIVISIO) and (t._id == MULTIPLICACIO or
                                                    DIVISIO or
                                                    CANVI_DE_SIGNE or
                                                    SIGNE_POSITIU or
                                                    EXPONENCIACIO or
                                                    SQRT or
                                                    LOG or
                                                    EXP))
      return false;
    else if (_id == (MULTIPLICACIO or DIVISIO) and (t._id == SUMA or
                                                    RESTA))
      return true;
    else if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU) and (t._id == CANVI_DE_SIGNE or
                                                           SIGNE_POSITIU or
                                                           EXPONENCIACIO or
                                                           SQRT or
                                                           LOG or
                                                           EXP))
      return false;
    else if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU) and (t._id == SUMA or
                                                           RESTA or
                                                           MULTIPLICACIO or
                                                           DIVISIO))
      return true;
    else if (_id == (EXPONENCIACIO or SQRT or LOG or EXP) and (t._id == EXPONENCIACIO or
                                                               SQRT or
                                                               LOG or
                                                               EXP))
      return false;
    else if
      (_id == (EXPONENCIACIO or SQRT or LOG or EXP)) return true;
  }
}
bool token::operator<(const token &t) const throw(error)
{
  if ((_id and t._id) != (SUMA or
                          RESTA or
                          MULTIPLICACIO or
                          DIVISIO or
                          CANVI_DE_SIGNE or
                          SIGNE_POSITIU or
                          EXPONENCIACIO or
                          SQRT or
                          LOG or
                          EXP))
    throw(14);
  else
  {
    if (_id == (SUMA or RESTA) and (t._id == MULTIPLICACIO or
                                    DIVISIO or
                                    CANVI_DE_SIGNE or
                                    SIGNE_POSITIU or
                                    EXPONENCIACIO or
                                    SQRT or
                                    LOG or
                                    EXP))
      return true;
    else if (_id == (SUMA or RESTA) and (t._id == SUMA or
                                         RESTA))
      return false;
    else if (_id == (MULTIPLICACIO or DIVISIO) and (t._id == CANVI_DE_SIGNE or
                                                    SIGNE_POSITIU or
                                                    EXPONENCIACIO or
                                                    SQRT or
                                                    LOG or
                                                    EXP))
      return true;
    else if (_id == (MULTIPLICACIO or DIVISIO) and (t._id == SUMA or
                                                    RESTA or
                                                    MULTIPLICACIO or
                                                    DIVISIO))
      return false;
    else if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU) and (t._id == SQRT or
                                                           LOG or
                                                           EXP))
      return true;
    else if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU) and (t._id == SUMA or
                                                           RESTA or
                                                           MULTIPLICACIO or
                                                           DIVISIO or
                                                           CANVI_DE_SIGNE or
                                                           SIGNE_POSITIU))
      return false;
    else if (_id == (EXPONENCIACIO or SQRT or LOG or EXP))
      return false;
  }
}

bool token::check_variables(string var)
{
  char lletra;
  bool incorrecte = false;
  for (unsigned int i = 0; i < var.length(); i++)
  {
    lletra = var[i];
    if (!isalpha(lletra) and int(lletra) != 95)
    {
      incorrecte = true;
    }
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
  if (_id == (CANVI_DE_SIGNE or SIGNE_POSITIU or SQRT or LOG or EXP))
    return 1;
  else if (_id == (SUMA or RESTA or MULTIPLICACIO or DIVISIO or EXPONENCIACIO))
    return 2;
  else if (_id == (CT_ENTERA or CT_RACIONAL or CT_REAL or CT_E or VARIABLE))
    return 0;
  else
    return -1;
}