#include "expressio.hpp"
#include "token.hpp"
#include <stack>
#include <list>

using namespace std;

/* Constructora d'una expressió formada per un sol token: un operand. Si
   s'utiliza el valor del token per defecte es construeix la que
   anomenem "expressió buida". Si el tipus del token no és el del token
   per defecte (NULLTOK), ni el d'una CT_ENTERA, CT_RACIONAL, CT_REAL,
   CT_E, VARIABLE o VAR_PERCENTAtGE es produeix un error sintàctic. */
expressio::expressio(const token t = token()) throw(error)
{
    if (t.tipus() != (t.NULLTOK and t.CT_ENTERA and t.CT_RACIONAL and t.CT_REAL and t.CT_E and t.VARIABLE and t.VAR_PERCENTATGE))
        throw(31);
    else
    {
        _exp.push_back(t);
    }
}

/* Constructora a partir d'una seqüència de tokens. Es produeix un error si
   la seqüència és buida o si no es pot construir l'arbre d'expressió
   corresponent(és a dir, si és sintàcticament incorrecta). */
expressio::expressio(const list<token> &l) throw(error)
{
    //1r faig l'algorisme suposant que l'expressio donada es correcta:
    stack<string> output, operador;
    token tok;
    for (list<token>::const_iterator it = l.begin(); it != l.end(); ++it)
    {
        tok = *it;
        if(tok.tipus() == (tok.VARIABLE or tok.CT_ENTERA or tok.CT_RACIONAL or tok.CT_REAL or tok.CT_E or tok.COMA))
        {
            output.push(tok);
        }
        else
        {
            if(tok.tipus == TANCAR_PAR)
            {
                while(tok.tipus != OBRIR_PAR)
                {
                    output.push(operador.top());
                    operador.pop();
                }
                operador.pop();
                if(operador.tipus() != OBRIR_PAR)
                {
                    output.push(operador.top());
                    operador.pop();
                }
            }
            else
            {
                bool treure_de_la_pila;
                if(operador.empty())
                {
                    treure_de_la_pila = false;
                }
                else
                    treure_de_la_pila = calcular_prioritat(tok, operador.top());
                                        // retorna true si l'operador de la pila té més prioriat
                                        // que el token 
                if(treure_de_la_pila)
                {
                    output.push(operador.top());
                    operador.pop();
                }
                operador.push(tok);
            }
        }
    }
    while(not operador.empty())
    {
        output.push(operador.top());
        operador.pop();
    }
}

// Constructora per còpia, assignació i destructora.
expressio::expressio(const expressio &e) throw(error)
{
    _exp = e._exp;
}
expressio &expressio::operator=(const expressio &e) throw(error)
{
    _exp = e._exp;
    return *this;
}
expressio::~expressio() throw(error)
{
    list<token> buida;
    _exp = buida;
}

// Retorna cert si i només si s'aplica a l'expressió buida.
expressio::operator bool() const throw()
{
    list<token> buida;
    if (_exp == buida)
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
    if (_exp == e._exp)
    {
        return true;
    }
    else
        return false;
}
bool expressio::operator!=(const expressio &e) const throw()
{
    if (_exp != e._exp)
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
    list<token> elem;
    elem = _exp;
    list<token>::iterator it;
    for (it = elem.begin(); it != elem.end(); ++it)
    {
        token t;
        if (it->tipus() == t.VARIABLE)
        {
            l.push_back(it->identificador_variable());
        }
    }
    l.sort();
    l.unique();
}

/* Substitueix totes les aparicions de la variable de nom v per
   l'expressió e. Si no existeix la variable v dins de l'expressió a la
   que apliquem aquest mètode l'expressió no es modifica. */
void expressio::apply_substitution(const string &v, const expressio &e) throw(error)
{
    list<token> elem;
    elem = _exp;
    list<token>::iterator it;
    for (it = elem.begin(); it != elem.end(); ++it)
    {
        token t;
        if (it->tipus() == t.VARIABLE)
        {
            if (it->identificador_variable() == v)
            {
                list<token> ins;
                ins = e._exp;
                list<token>::iterator in;
                in = ins.begin();
                *it = *in;
                it++;
                in++;
                while (in != ins.end())
                {
                    _exp.insert(it, *in);
                    in++;
                }
                return;
            }
        }
    }
}

/* Aplica un pas de simplificació a l'expressió. La subexpressió a
   simplificar es busca seguint el recorregut "left to right" postordre
   explicat a l'apartat "Procés d'avaluació". Es pot produir qualsevol dels
   errors semàntics que apareixen més avall numerats des del 32 al 35. */
void expressio::simplify_one_step() throw(error)
{
    // sha de fer un arbre i tal, sino no entenc
    // L'arbre el fem al constructor, quan ens passen la llista de tokens
    // Aquí el que hem de fer és simplificar una sola cosa. Crec que el mètode simplify anirà cridant
    // al mètode simplify_one_step fins que ja no es pugui simplificar més.
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
