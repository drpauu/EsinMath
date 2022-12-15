#include "expressio.hpp"
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
    if (t.tipus() == token::NULLTOK)
    {
        _arrel = new node;
        _arrel = NULL;
        es_buit = true;
    }
    else if (t.tipus() == token::CT_ENTERA or t.tipus() == token::CT_RACIONAL or t.tipus() == token::CT_REAL or t.tipus() == token::VARIABLE or t.tipus() == token::VAR_PERCENTATGE)
    {
        _arrel = new node;
        _arrel->f_dret = NULL;
        _arrel->f_esq = NULL;
        _arrel->_info = t;
        _lt.push_back(t);
        es_buit = false;
    }
    else
    {
        throw error(ErrorSintactic);
    }
}

int operators(token op)
{
    if (op.tipus() == token::SUMA or op.tipus() == token::RESTA)
        return 1;
    if (op.tipus() == token::MULTIPLICACIO or op.tipus() == token::DIVISIO)
        return 2;
    return 0;
}

bool expressio::es_operand(token t)
{
    if (t.tipus() == token::CT_ENTERA or t.tipus() == token::CT_RACIONAL or t.tipus() == token::CT_REAL or t.tipus() == token::VARIABLE or t.tipus() == token::VAR_PERCENTATGE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_operator(token op)
{
    return op.tipus() == token::MULTIPLICACIO or op.tipus() == token::DIVISIO or op.tipus() == token::SUMA or op.tipus() == token::RESTA;
}

bool is_open_parenthesis(token token) { return token.tipus() == token::OBRIR_PAR; }

bool is_close_parenthesis(token token) { return token.tipus() == token::TANCAR_PAR; }

expressio expressio::constructora_op(token t, expressio a, expressio b)
{
    expressio ret;
    if (es_operador(t))
    {
        ret._arrel = new node;
        ret._arrel->_info = t;
        ret._arrel->f_dret = a._arrel;
        ret._arrel->f_esq = b._arrel;
    }
    ret.es_buit = false;
    return ret;
}

expressio::expressio(const list<token> &l) throw(error)
{
    _lt = l;
    stack<expressio> expre;
    stack<token> oops;
    for (list<token>::const_iterator it = l.begin(); it != l.end(); ++it)
    {
        if (is_open_parenthesis(*it))
        {
            oops.push(*it);
        }
        else if (is_close_parenthesis(*it))
        {
            while (!oops.empty() and
                   (operators(oops.top()) >= operators(*it)) and
                   !is_open_parenthesis(oops.top()))
            {
                expressio aux = expre.top();
                expre.pop();
                expressio exp = constructora_op(oops.top(), expre.top(), aux);
                expre.pop();
                oops.pop();
                expre.push(exp);
            }
            oops.pop();
        }
        else if (is_operator(*it))
        {
            while (!oops.empty() and
                   (operators(*it) <= operators(oops.top())))
            {
                expressio aux = expre.top();
                expre.pop();
                expressio exp = constructora_op(oops.top(), expre.top(), aux);
                expre.pop();
                oops.pop();
                expre.push(exp);
            }
            oops.push(*it);
        }
        else if (es_operand(*it))
        {
            expressio exp(*it);
            expre.push(exp);
        }
    }
    while (!oops.empty())
    {
        expressio aux = expre.top();
                expre.pop();
                expressio exp = constructora_op(oops.top(), expre.top(), aux);
                expre.pop();
                oops.pop();
                expre.push(exp);
    }
    es_buit = false;
    *this = expre.top();
}

// Constructora per còpia, assignació i destructora.
expressio::expressio(const expressio &e) throw(error)
{
    *this = e;
}
expressio &expressio::operator=(const expressio &e) throw(error)
{
    *this = e;
    return *this;
}
expressio::~expressio() throw(error)
{
    esborra_nodes(_arrel);
    es_buit = true;
}

// Retorna cert si i només si s'aplica a l'expressió buida.
expressio::operator bool() const throw()
{
    return es_buit;
}

/* Operadors d'igualtat i desigualtat. Dues expressions es consideren
   iguals si i només si els seus arbres d'expressió són idèntics. */
bool expressio::operator==(const expressio &e) const throw()
{
    if (*this == e)
    {
        return true;
    }
    else
        return false;
}
bool expressio::operator!=(const expressio &e) const throw()
{
    if (*this == e)
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
    /*
    /*for(list <token>::iterator elem = exp_.begin(); elem != exp_.end(); elem++){
        list <string>::iterator it ;
        //it = find(l.begin(), l.end(), elem.)
    } */
    for (list<token>::const_iterator it = _lt.begin(); it != _lt.end(); ++it)
    {
        if (it->tipus() == token::VARIABLE)
        {
            l.push_back(it->identificador_variable());
        }
    }
    l.sort();
    l.unique();
    // return variables;
}

/* Substitueix totes les aparicions de la variable de nom v per
   l'expressió e. Si no existeix la variable v dins de l'expressió a la
   que apliquem aquest mètode l'expressió no es modifica. */
void expressio::apply_substitution(const string &v, const expressio &e) throw(error)
{
    /*
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
    */
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
    lt = _lt;
}

bool operand(token t)
{
    if (t.tipus() == (token::SUMA or token::RESTA or token::MULTIPLICACIO or token::DIVISIO or token::EXPONENCIACIO or token::CANVI_DE_SIGNE or token::SIGNE_POSITIU or token::SQRT or token::LOG or token::EXP))
    {
        return true;
    }
    else
    {
        return false;
    }
}