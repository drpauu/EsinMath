#include "math_sessio.hpp"

math_sessio::math_sessio() throw(error)
{
    string tok = "%";
    token t(tok);
    expressio especial(t);
    _sessio.insert(_sessio.begin(), especial);
}

// Constructora per còpia, assignació i destructora.
math_sessio::math_sessio(const math_sessio &es) throw(error) {
  _sessio = es._sessio;
}
math_sessio &math_sessio::operator=(const math_sessio &es) throw(error) {
  _sessio = es._sessio;
  return *this;
}
math_sessio::~math_sessio() throw(error) {
  list<expressio> buida = {};
  _sessio = buida;
}

/* Aquest mètode rep una llista de tokens, lin, lèxicament correcta.
   Primerament analitza parcialment lin per verificar si la comanda és
   correcta. Si és correcta executa la comanda que conté lin.
   Les comandes són:
    * avaluació d'una expressió E.
    * assignació v :=  E. S'avalua E i s'assigna el resultat a la variable
      de nom v.
    * desassignació d'una variable v: unassign v.
    * final de sessió: byebye

   En l'anàlisi de la comanda lin es produeix un error de comanda
   incorrecta en els següents casos:
    * si conté el token DESASSIGNACIO i,
      * o bé la comanda no té dos tokens
      * o bé aquest no és el primer token
      * o bé el segon token no és una VARIABLE.
    * si conté el token BYEBYE i aquest no és el primer i únic token
      de la comanda.
    * si conté el token ASSIGNACIO i,
      * o bé la comanda té longitud menor que dos
      * o bé no és el segon token
      * o bé el primer token no és un token VARIABLE.

   Les comandes que involucren avaluació (avaluar i assignar) retornen
   l'expressió avaluada en forma de llista de tokens en lout. La comanda
   unassign retorna la llista que conté com únic token la variable
   desassignada. Finalment la comanda byebye retorna la llista buida.
   Es produeix un error en una assignació, si després l'avaluació de
   l'expressió es comprova que la variable assignada forma part del conjunt
   de variables de l'expressió avaluada, tal i com s'explica a
   l'apartat "Procés d'avaluació". */
void math_sessio::execute(const list<token> &lin, list<token> &lout) throw(error)
{
    
}

// Retorna cert si i només si la sessió ha finalitzat.
bool math_sessio::end_of_session() const throw() {}

/* Retorna en forma de llista d'strings, en un ordre qualsevol, la llista de
   variables juntament amb el seu valor assignat. Cada string de la llista
   té el format id = e, on id és el nom d'una variable i e és l'expressió
   (com string) assignada a id. Convertim una expressió e en el seu string
   corresponent invocant al mètode tostring del mòdul esinmath_io. */
void math_sessio::dump(list<string> &l) const throw(error) {}

/* Donada una expressió e, aplica a les seves variables totes les
   substitucions definides per elles. L'expressió resultant només contindrà
   variables per les quals no hi ha substitució definida (no estan en el
   conjunt). Aquest procés s'explica en detall a l'apartat "Procés
   d'avaluació". S'assumeix que no existeix circularitat infinita entre les
   substitucions de les variables que formen part de l'expressió e. */
void math_sessio::apply_all_substitutions(expressio &e) const throw(error) {}