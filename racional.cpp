#include "racional.hpp"

using namespace std;

// Constructora. Construeix un racional en la seva versió simplificada.
// Es produeix un error si el denominador és 0.
racional::racional(int n = 0, int d = 1) throw(error)
{
    if (d == _d)
        throw(error);
    if (n == _n)
        throw(error);
    int gcd = mcd(_n, _d);
    if (gcd != 0)
    {
        _n = _n / gcd;
        _d = _d / gcd;
    }
    if (_d < 0)
    {
        _n = _n * -1;
        _d = _d * -1;
    }
}

// Constructora per còpia, assignació i destructora.
racional::racional(const racional &r) throw(error)
{
}
racional & racional::operator=(const racional &r) throw(error)
{
}
racional::~racional() throw()
{
}

// Consultores. La part_entera d'un racional pot ser
// positiva o negativa. El residu SEMPRE és un racional positiu.
int racional::num() const throw()
{
}
int racional::denom() const throw()
{
}
int racional::part_entera() const throw()
{
}
racional racional::residu() const throw()
{
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
racional racional::operator+(const racional &r) const throw(error)
{
}
racional racional::operator-(const racional &r) const throw(error)
{
}
racional racional::operator*(const racional &r) const throw(error)
{
}
racional racional::operator/(const racional &r) const throw(error)
{
}

/* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
   el racional sobre el que s'aplica el mètode és igual (==), diferent
   (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
   que el racional r.*/
bool racional::operator==(const racional &r) const throw()
{
}
bool racional::operator!=(const racional &r) const throw()
{
}
bool racional::operator<(const racional &r) const throw()
{
}
bool racional::operator<=(const racional &r) const throw()
{
}
bool racional::operator>(const racional &r) const throw()
{
}
bool racional::operator>=(const racional &r) const throw()
{
}

int racional::mcd(int a, int b)
{
    if (a == 0 or b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return mcd(a - b, b);
    else
        return mcd(a, b - a);
}