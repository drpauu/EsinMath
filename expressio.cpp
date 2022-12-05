#include "expressio.hpp"

#include "expressio.hpp"

/* Constructora d'una expressió formada per un sol token: un operand. Si
   s'utiliza el valor del token per defecte es construeix la que
   anomenem "expressió buida". Si el tipus del token no és el del token
   per defecte (NULLTOK), ni el d'una CT_ENTERA, CT_RACIONAL, CT_REAL,
   CT_E, VARIABLE o VAR_PERCENTAtGE es produeix un error sintàctic. */
expressio::expressio(const token t = token()) throw(error)
{
    exp_ = {t};
    //t.
}

/* Constructora a partir d'una seqüència de tokens. Es produeix un error si
   la seqüència és buida o si no es pot construir l'arbre d'expressió
   corresponent(és a dir, si és sintàcticament incorrecta). */
expressio::expressio(const list<token> &l) throw(error)
{
    exp_ = l;
}

// Constructora per còpia, assignació i destructora.
expressio::expressio(const expressio &e) throw(error)
{
    exp_ = e.exp_;
}
expressio &expressio::operator=(const expressio &e) throw(error)
{
    exp_ = e.exp_;
    return *this;
}
expressio::~expressio() throw(error)
{
    exp_ = {};
}

// Retorna cert si i només si s'aplica a l'expressió buida.
expressio::operator bool() const throw()
{
    list<token> buida = {};
    if (exp_ == buida)
    {
        return true;
    }
    else
        return false;
}

/* Operadors d'igualtat i desigualtat. Dues expressions es consideren
   iguals si i només si els seus arbres d'expressió són idèntics. */
bool expressio::operator==(const expressio &e) const throw()
{
    if (exp_ == e.exp_)
    {
        return true;
    }
    else
        return false;
}
bool expressio::operator!=(const expressio &e) const throw()
{
    if (exp_ != e.exp_)
    {
        return true;
    }
    else
        return false;
}

/* Retorna una llista sense repeticions, en qualsevol ordre, amb
   els noms de les variables de l'expressió. */
void expressio::vars(list<string> &l) const throw(error)
{
    /*for(list <token>::iterator elem = exp_.begin(); elem != exp_.end(); elem++){
        list <string>::iterator it ;
        //it = find(l.begin(), l.end(), elem.)
    } */
}

/* Substitueix totes les aparicions de la variable de nom v per
   l'expressió e. Si no existeix la variable v dins de l'expressió a la
   que apliquem aquest mètode l'expressió no es modifica. */
void expressio::apply_substitution(const string &v, const expressio &e) throw(error)
{
}

/* Aplica un pas de simplificació a l'expressió. La subexpressió a
   simplificar es busca seguint el recorregut "left to right" postordre
   explicat a l'apartat "Procés d'avaluació". Es pot produir qualsevol dels
   errors semàntics que apareixen més avall numerats des del 32 al 35. */
void expressio::simplify_one_step() throw(error)
{
}

/* Aplica successius passos de simplificació com l'anterior fins que
   l'expressió es trobi completament simplificada. Llavors diem que es
   troba en "forma normal". Es pot produir qualsevol dels errors
   semàntics que apareixen més avall numerats des del 32 al 35. */
void expressio::simplify() throw(error)
{
}

/* Converteix l'expressió en la seqüència de tokens lt corresponent: els
   operadors apareixen entre els operands si són infixos, abans si són
   prefixos i els símbols de funció van seguits de parèntesis que tanquen
   els seus arguments separats per comes. S'han d'introduir només aquells
   parèntesis que siguin estrictament necessaris per trencar les regles de
   precedència o associativitat en l'ordre d'aplicació dels operadors. */

void expressio::list_of_tokens(list<token> &lt) throw(error)
{
}