#include "variables.hpp"

using std::map;

// Constructor
variables::variables() throw(error)
{
    node *v;
    v = new node;
    v->seg = nullptr;
    primer = v;
}

// Copy constructor
variables::variables(const variables &v) throw(error)
{
    // Create a new node to serve as the head of the new list
    node *new_head = new node;
    new_head->seg = nullptr;
    primer = new_head;

    // Create a pointer to traverse the list
    node *current = v.primer;

    // Copy each node in the list
    while (current != nullptr)
    {
        primer->seg = new node;
        primer->seg->info = current->info;
        primer = primer->seg;
        current = current->seg;
    }
}

// Assignment operator
variables &variables::operator=(const variables &v) throw(error)
{
    // Check for self-assignment
    if (this == &v)
    {
        return *this;
    }

    // Clear the current list
    node *current = primer;
    while (current != nullptr)
    {
        node *temp = current;
        current = current->seg;
        delete temp;
    }

    // Create a new head node
    node *new_head = new node;
    new_head->seg = nullptr;
    primer = new_head;

    // Copy each node in the list
    current = v.primer;
    while (current != nullptr)
    {
        primer->seg = new node;
        primer->seg->info = current->info;
        primer = primer->seg;
        current = current->seg;
    }

    return *this;
}

// Destructor
variables::~variables() throw(error)
{
    // Delete each node in the list
    node *current = primer;
    while (current != nullptr)
    {
        node *temp = current;
        current = current->seg;
        delete temp;
    }
}

/* Afegeix al conjunt de variables la variable de nom v juntament amb el seu
   valor-expressió e. Si la variable v ja existia llavors li assigna el nou
   valor-expressió. */
void variables::assign(const string &v, const expressio &e) throw(error)
{
    // Check if the variable already exists
    node* current = primer;
    while (current != nullptr)
    {
        if (current->info.first == v)
        {
            // If it exists, assign the new value
            current->info.second = e;
            return;
        }
        current = current->seg;
    }

    // If the variable does not exist, create a new node and add it to the list
    node* new_node = new node;
    new_node->seg = nullptr;
    new_node->info = std::make_pair(v, e);

    // Add the new node to the end of the list
    current = primer;
    while (current->seg != nullptr)
    {
        current = current->seg;
    }
    current->seg = new_node;
}

/* Elimina del conjunt de variables el parell amb la variable de nom v. Si
   la variable no existeix llavors no fa res. */
void variables::unassign(const string &v) throw()
{
    // Check if the variable exists
    node* current = primer;
    while (current != nullptr)
    {
        if (current->info.first == v)
        {
            // If it exists, delete the node
            node* temp = current;
            current = current->seg;
            delete temp;
            return;
        }
        current = current->seg;
    }
}

/* Consulta el valor-expressió de la variable v. Si la variable no està en
   el conjunt de variables retorna l'expressió buida. */
expressio variables::valor(const string &lv) const throw(error)
{
    // Search for the variable
    node* current = primer;
    while (current != nullptr)
    {
        if (current->info.first == lv)
        {
            // If the variable is found, return its value
            return current->info.second;
        }
        current = current->seg;
    }

    // If the variable is not found, return an empty expression
    expressio e;
    return e;
}

/* Retorna en l totes les claus del conjunt de variables, en un ordre
   qualsevol. Si no hi ha cap clau retorna la llista buida.*/
void variables::dump(list<string> &l) const throw(error)
{
    node* current = primer;
    while (current != nullptr)
    {
        l.push_back(current->info.first);
        current = current->seg;
    }
}