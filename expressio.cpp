#include "expressio.hpp"
#include <stack>
#include <list>
#include <cmath>
#include <iostream>

using namespace std;

// oepradors, copies de nodes pels operadors, i elimina nodes
// per utilitat (aquestes dues ultimes estan escrites al .rep)

expressio &expressio::operator=(const expressio &a)
{
    // Make sure we're not self-assigning
    if (this != &a)
    {
        // Copy the list and the tree
        _lt = a._lt;
        _arrel = copia_nodes(a._arrel);
    }

    return *this;
}

// operacions;

token expressio::operacio_corrent(token op, token a, token b)
{
    if (op.tipus() == token::SUMA)
    {
        if (a.tipus() == token::CT_ENTERA)
        {
            int c, d;
            c = a.valor_enter();
            d = b.valor_enter();
            token ret(c + d);
            return ret;
        }
        else if (a.tipus() == token::CT_RACIONAL)
        {
            racional c, d;
            c = a.valor_racional();
            d = b.valor_racional();
            token ret(c + d);
        }
        else if (a.tipus() == token::CT_REAL)
        {
            double c, d;
            c = a.valor_real();
            d = b.valor_real();
            token ret(c + d);
        }
        else if (a.tipus() == token::VARIABLE)
        {
            // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
            // s ah de preguntar;
        }
        // en el cas que no sigui cap d aquestes, hauria de donar un error semantic
        // pero l hauria de donar quan fessim l expressio, es a dir, que si els dos fills no son dle mateix tipsu,
        // doni un error semantic que no es es pot fer l operacio.
    }
    else if (op.tipus() == token::RESTA)
    {
        if (a.tipus() == token::CT_ENTERA)
        {
            int c, d;
            c = a.valor_enter();
            d = b.valor_enter();
            token ret(c - d);
            return ret;
        }
        else if (a.tipus() == token::CT_RACIONAL)
        {
            racional c, d;
            c = a.valor_racional();
            d = b.valor_racional();
            token ret(c - d);
        }
        else if (a.tipus() == token::CT_REAL)
        {
            double c, d;
            c = a.valor_real();
            d = b.valor_real();
            token ret(c - d);
        }
        else if (a.tipus() == token::VARIABLE)
        {
            // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
            // s ah de preguntar;
        }
    }
    else if (op.tipus() == token::MULTIPLICACIO)
    {
        if (a.tipus() == token::CT_ENTERA)
        {
            int c, d;
            c = a.valor_enter();
            d = b.valor_enter();
            token ret(c * d);
            return ret;
        }
        else if (a.tipus() == token::CT_RACIONAL)
        {
            racional c, d;
            c = a.valor_racional();
            d = b.valor_racional();
            token ret(c * d);
        }
        else if (a.tipus() == token::CT_REAL)
        {
            double c, d;
            c = a.valor_real();
            d = b.valor_real();
            token ret(c * d);
        }
        else if (a.tipus() == token::VARIABLE)
        {
            // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
            // s ah de preguntar;
        }
    }
    else if (op.tipus() == token::DIVISIO)
    {
        if (a.tipus() == token::CT_ENTERA)
        {
            int c, d;
            c = a.valor_enter();
            d = b.valor_enter();
            token ret(c / d);
            return ret;
        }
        else if (a.tipus() == token::CT_RACIONAL)
        {
            racional c, d;
            c = a.valor_racional();
            d = b.valor_racional();
            token ret(c / d);
        }
        else if (a.tipus() == token::CT_REAL)
        {
            double c, d;
            c = a.valor_real();
            d = b.valor_real();
            token ret(c / d);
        }
        else if (a.tipus() == token::VARIABLE)
        {
            // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
            // s ah de preguntar;
        }
    }
    else if (op.tipus() == token::EXPONENCIACIO)
    {
        if (a.tipus() == token::CT_ENTERA)
        {
            int c, d;
            c = a.valor_enter();
            d = b.valor_enter();
            token ret(c ^ d);
            return ret;
        }
        else if (a.tipus() == token::CT_RACIONAL)
        {
            racional c, d;
            c = a.valor_racional();
            d = b.valor_racional();
            // token ret(c^d); caldria fer una funcio extra a racional, per poder fer aquesta operacio.
        }
        else if (a.tipus() == token::CT_REAL)
        {
            double c, d;
            c = a.valor_real();
            d = b.valor_real();
            // token ret(c^d); te sentit, s ha de mirar per internet a veure si es pot fer, i com fer ho.
        }
        else if (a.tipus() == token::VARIABLE)
        {
            // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
            // s ah de preguntar;
        }
    }
    token buit;
    return buit;
}

token expressio::logaritme(token op) throw(error)
{
    if (op.tipus() == token::CT_ENTERA)
    {
        token ret(log(op.valor_enter()));
        return ret;
    }
    else if (op.tipus() == token::CT_RACIONAL)
    {
        // token ret(log(op.valor_racional())); no es pot fer un logaritme d un valor racional
    }
    else if (op.tipus() == token::CT_REAL)
    {
        token ret(log(op.valor_real()));
    }
    else if (op.tipus() == token::VARIABLE)
    {
        // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
        // s ah de preguntar;
    }
    token buit;
    return buit;
}

token exponencial(token op) throw(error)
{
    if (op.tipus() == token::CT_ENTERA)
    {
        token ret(exp(op.valor_enter()));
        return ret;
    }
    else if (op.tipus() == token::CT_RACIONAL)
    {
        // token ret(exp(op.valor_racional())); no es pot fer un logaritme d un valor racional
    }
    else if (op.tipus() == token::CT_REAL)
    {
        token ret(exp(op.valor_real()));
    }
    else if (op.tipus() == token::VARIABLE)
    {
        // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
        // s ah de preguntar;
    }
    token buit;
    return buit;
}

token expressio::func_sqrt(token op) throw(error)
{
    if (op.tipus() == token::CT_ENTERA)
    {
        token ret(sqrt(op.valor_enter()));
        return ret;
    }
    else if (op.tipus() == token::CT_RACIONAL)
    {
        // token ret(sqrt(op.valor_racional())); no es pot fer un logaritme d un valor racional
    }
    else if (op.tipus() == token::CT_REAL)
    {
        token ret(sqrt(op.valor_real()));
    }
    else if (op.tipus() == token::VARIABLE)
    {
        // la suma de variable, ns com es faria, suposu que es queda igual o algo ns
        // s ah de preguntar;
    }
    token buit;
    return buit;
}

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

bool expressio::es_operador(token op)
{
    return op.tipus() == token::MULTIPLICACIO or op.tipus() == token::DIVISIO or op.tipus() == token::SUMA or op.tipus() == token::RESTA;
}

bool expressio::funcio(token t)
{
    return t.tipus() == token::LOG or t.tipus() == token::EXP or t.tipus() == token::SQRT;
}

bool is_parenthesis(token token){
    return is_open_parenthesis(token) and is_close_parenthesis(token);
}

bool es_variable(token t){
    if (!es_operador(t) and !is_parenthesis(t) and !funcio(t)) {
    return true;
  } else {
    return false;
  }
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
        if (is_open_parenthesis(*it) or funcio(*it))
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
            if(funcio(oops.top())){
                expressio aux;
                expressio exp = constructora_op(oops.top(), aux, expre.top());
                expre.pop();
                oops.pop();
                expre.push(exp);
            }
        }
        else if (es_operador(*it) or es_variable(*it))
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
    l.sort();
    l.unique();
    for (list<token>::const_iterator it = _lt.begin(); it != _lt.end(); ++it)
    {
        if (it->tipus() == token::VARIABLE)
        {
            l.push_back(it->identificador_variable());
        }
    }
    // return variables;
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
    // s ha de baixar fins abaix a la dreta, que es la primera operacio,
    // i modificar el fill dret, per una expressio amb fills dret i esquerra nullptr;
    node *aux = _arrel;
    node *ant = NULL;
    while (aux->f_dret != NULL)
    {
        ant = aux;
        aux = aux->f_dret;
    }
    if (ant->_info.tipus() == token::EXPONENCIACIO)
    {
        ant->_info = exponencial(ant->f_dret->_info);
    }
    else if (ant->_info.tipus() == token::LOG)
    {
        ant->_info = logaritme(ant->f_dret->_info);
    }
    else if (ant->_info.tipus() == token::SQRT)
    {
        ant->_info = func_sqrt(ant->f_dret->_info);
    }
    else
    {
        ant->_info = operacio_corrent(ant->_info, ant->f_esq->_info, ant->f_dret->_info);
    }
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

bool operand(token t) // es diferent que la de es_operand(), no borrar
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

void printl(list<token> l)
{
    list<token>::iterator it = l.begin();
    while (it != l.end())
    {
        // cout << *it;, dona erro ja que ejn la clase de token
        // no hi ha un operador per poder fer un cout d un token
        // pero com que aquesta funcio crec que no es del tot necessaria
        // ho deixo en comentari.
        it++;
        if (it != l.end())
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}