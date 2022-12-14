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
    token tok = t;
    if (t.NULLTOK == t.tipus())
    {
        _exp = arbreBin<token>();
    }
    else if (t.tipus() != (t.CT_ENTERA and t.CT_RACIONAL and t.CT_REAL and t.CT_E and t.VARIABLE and t.VAR_PERCENTATGE))
        throw(31);
    if(coperand(t))
    {
        arbreBin<token> _exp(tok, arbreBin<token>(), arbreBin<token>());
    }
}

int operators(char op) {
  if (op == '+' or op == '-')
    return 1;
  if (op == '*' or op == '/')
    return 2;
  return 0;
}

bool is_operator(char token) {
  return token == '+' or token == '-' or token == '*' or token == '/';
}

bool is_parenthesis(char token) { return token == '(' or token == ')'; }

bool is_open_parenthesis(char token) { return token == '('; }

bool is_close_parenthesis(char token) { return token == ')'; }

arbreBin<char> arbre(string tokens) {
  stack<arbreBin<char>> expressio;
  stack<char> oops;
  for (int i = 0; i < tokens.length(); i++) {
    if (is_open_parenthesis(tokens[i])) {
      oops.push(tokens[i]);
    } else if (is_close_parenthesis(tokens[i])) {
      while (!oops.empty() and
             (operators(oops.top()) >= operators(tokens[i])) and
             !is_open_parenthesis(oops.top())) {
        arbreBin<char> aux = expressio.top();
        expressio.pop();
        arbreBin<char> exp(oops.top(), expressio.top(), aux);
        expressio.pop();
        oops.pop();
        expressio.push(exp);
      }
      oops.pop();
    } else if (is_operator(tokens[i])) {
      while (!oops.empty() and
             (operators(tokens[i]) <= operators(oops.top()))) {
        arbreBin<char> aux = expressio.top();
        expressio.pop();
        arbreBin<char> exp(oops.top(), expressio.top(), aux);
        expressio.pop();
        oops.pop();
        expressio.push(exp);
      }
      oops.push(tokens[i]);
    } else if (isdigit(tokens[i])) {
      arbreBin<char> exp(tokens[i], arbreBin<char>(), arbreBin<char>());
      expressio.push(exp);
    }
  }
  while (!oops.empty()) {
    arbreBin<char> aux = expressio.top();
    expressio.pop();
    arbreBin<char> exp(oops.top(), expressio.top(), aux);
    expressio.pop();
    oops.pop();
    expressio.push(exp);
  }
  return expressio.top();
}

/* Constructora a partir d'una seqüència de tokens. Es produeix un error si
   la seqüència és buida o si no es pot construir l'arbre d'expressió
   corresponent(és a dir, si és sintàcticament incorrecta). */
expressio::expressio(const list<token> &l) throw(error)
{
    // Recorrer la llista l
    stack<token> operador, output;
    token tok;
    for (list<token>::const_iterator it = l.begin(); it != l.end(); ++it)
    {
        tok = *it;
        // if (token == var/constant)
        if (tok.tipus() == (tok.VARIABLE or tok.CT_ENTERA or tok.CT_RACIONAL or tok.CT_REAL or tok.CT_E or tok.COMA))
        {
            // Guardar token a l'stack output
            output.push(tok);
        }
        // else (token == operador)
        else
        {
            // Mirar la prioritat dels operadors i guardar l'operador a l'stack operador
            if (operador.empty())
            {
                operador.push(tok);
            }
            else if (operador.top().tipus() != operador.top().OBRIR_PAR)
            {
                int prioritat_oper1, prioritat_tok;
                prioritat_oper1 = operador.top().prioritat_operacio();
                prioritat_tok = tok.prioritat_operacio();
                if (tok.tipus() == tok.TANCAR_PAR)
                {
                    while (operador.top().tipus() != operador.top().OBRIR_PAR)
                    {
                        output.push(operador.top());
                        operador.pop();
                    }
                }
                else
                {
                    while (prioritat_oper1 <= prioritat_tok)
                    {
                        output.push(operador.top());
                        operador.pop();
                        prioritat_oper1 = operador.top().prioritat_operacio();
                    }
                    operador.push(tok);
                }
            }
            else
            {
                operador.push(tok);
            }
        }
    }
    while (not operador.empty())
    {
        if (operador.tipus() != (operador.OBRIR_PAR or operador.TANCAR_PAR))
            output.push(operador.top());
        operador.pop();
    }
    // Recorrer la llista output des del final cap al principi i guardar-la a l'arbreBin
}

expressio::expressio(const list<token> &l) throw(error)
{
    // jo primer faria obviant quin tipus de prioritat te,
    // i despres ho faria mirant quin tipus de prioritat.
    list<token> llista;
    llista = l;
    list<token> operadors;
    list<token> expressions; // aquesta pila hauria de ser, una pila d 'arbres d'expressions
    // pero ns pq, al .rep, no em deixa fer un arbre, dema ho miro
    list<token>::iterator it;
    token t;
    for (it = llista.begin(); it != llista.end(); it++)
    {
        if (it->tipus() == t.OBRIR_PAR)
        {
            operadors.push(*it);
        }
        else if (it->tipus() == t.TANCAR_PAR)
        {
            while (operadors.top().tipus() != t.OBRIR_PAR)
            {
                // crear la expressio amb una o dues expressions, i apilarla a les expressions
                // expressions.pop();
                // expressions.pop();
                // aquestes dos expressions s han de guardar i tal, per poder fer aquest mini arbreBin
                // expressions.push(operador amb un o dos operands com a fill)
                operadors.pop();
            }
        }
        else if (it->tipus() == t.VARIABLE or t.CT_ENTERA or t.CT_RACIONAL or t.CT_REAL or t.CT_E or t.COMA)
        {
            // s ha de crear l arbre amb aquest operand
            // expressions.push(aquest arbre);
        }
        else if (it->tipus() == t.SUMA or t.RESTA or t.MULTIPLICACIO or t.DIVISIO or t.SQRT or t.CANVI_DE_SIGNE or t.LOG)
        {
            // assumim que la prioritat es d esquera a dreta, ja despres modifiquem aixo
            // o fem una funcio auxiliar, per canviar ho, pero primer que funcioni be;
            // expressio.pop();
            // expressio.pop(); s han de guardar aquestes dues expressions, ja que seran els fills de la que crearem ara
            // operadors.pop(); ja que com que l utilitzem, s ha de desapilar;
            // aqui no entenc ven be el que s ha de fer; pero en si.
        }
        // despres s ha d acabar de desapilar tot, fent expressions mes grans, a partir de les que tenim ja a la pilla
        // d'expressions. Pero el que no em quadra es quan s ha de fer un push a la pila operadors.
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
    _exp = arbreBin<token>(); 
}

// Retorna cert si i només si s'aplica a l'expressió buida.
expressio::operator bool() const throw()
{
    if (_exp.es_buit())
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
    /*
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
    */
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
}

bool operand(token t)
{
    if (t.tipus() == (token::SUMA or token::RESTA or token::MULTIPLICACIO 
                        or token::DIVISIO or token::EXPONENCIACIO or token::CANVI_DE_SIGNE 
                        or token::SIGNE_POSITIU or token::SQRT or token::LOG or token::EXP)){
                            return true;
                        } else {
                            return false;
                        }
}