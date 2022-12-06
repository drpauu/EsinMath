#include "variables.hpp"

// Construeix un conjunt de variables buit.
variables::variables() throw(error){
    _var :
}

// Constructora per còpia, assignació i destructora.
variables::variables(const variables &v) throw(error)
{
    _var = v._var;
}

variables &variables::operator=(const variables &v) throw(error)
{
    _var = v._var;
    return *this;
}
variables::~variables() throw(error) {}

/* Afegeix al conjunt de variables la variable de nom v juntament amb el seu
   valor-expressió e. Si la variable v ja existia llavors li assigna el nou
   valor-expressió. */
void variables::assign(const string &v, const expressio &e) throw(error)
{
    std::map<string, expressio>::iterator it;
    it = _var.find(v);
    if (it != _var.end())
    {
        it->second = e;
    }
    else
    {
        _var.insert(it, std::pair<string, expressio>(v, e));
    }
}

/* Elimina del conjunt de variables el parell amb la variable de nom v. Si
   la variable no existeix llavors no fa res. */
void variables::unassign(const string &v) throw() {
    std::map<string, expressio>::iterator it;
    it = _var.find(v);
    if (it != _var.end())
    {
        _var.erase(it);
    }
}

/* Consulta el valor-expressió de la variable v. Si la variable no està en
   el conjunt de variables retorna l'expressió buida. */
expressio variables::valor(const string &lv) const throw(error) {
    std::map<string, expressio>::iterator it;
    //it = _var.find(lv); no entenc pq dona error, nidea, despres ho miro
    if (it != _var.end())
    {
        return it->second;
    } else{
        expressio a;
        return a;
    }
}

/* Retorna en l totes les claus del conjunt de variables, en un ordre
   qualsevol. Si no hi ha cap clau retorna la llista buida.*/
void variables::dump(list<string> &l) const throw(error) {
    std::map<string, expressio>::iterator it;
    while(it != _var.end()){
        l.push_back(it->first);
        it++;
    }
    //return l; en el post diu que s ha de retornar una llista,
    // pero es una fucnio void, no ho entenc.
    //ho poso com a comentari 
}