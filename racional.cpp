#include "racional.hpp"
#include <cmath>

using namespace std;

// Constructora. Construeix un racional en la seva versió simplificada.
// Es produeix un error si el denominador és 0.
racional::racional(int n, int d) throw(error)
{
    _d = d;
    _n = n;
}

// Constructora per còpia, assignació i destructora.
racional::racional(const racional &r) throw(error)
{
    if (r._d == 0)
    {
        throw(21);
    }
    _d = r._d;
    _n = r._d;
}
racional &racional::operator=(const racional &r) throw(error)
{
    if (r._d == 0)
    {
        throw(21);
    }
    _d = r._d;
    _n = r._d;
    return *this;
}
racional::~racional() throw()
{
}

// Consultores. La part_entera d'un racional pot ser
// positiva o negativa. El residu SEMPRE és un racional positiu.
int racional::num() const throw()
{
    return _n;
}
int racional::denom() const throw()
{
    return _d;
}
int racional::part_entera() const throw()
{
    return _n / _d;
}
racional racional::residu() const throw()
{
    /*float c;
    racional r;
    aux = _n % _d;
    int c = 0;
    while ((int)x != x)
    {
        x *= 10;
        c++;
    }
    int deno = 1;
    for (int i = 0; i < c - 1; i++)
    {
        deno = deno * 10;
    }
    r._n = (int)x;
    r._d = deno;
    r.simplificar();
    return r;*/
    racional r;
    r._n = 1;
    r._d = 1;
    return r;
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
racional racional::operator+(const racional &r) throw(error)
{
    int min, den = _d, r_d = r.denom();
    min = mcm(r_d, den);
    _n = (_n * min) + (r.num());
    _d = min;
    simplificar();
    return *this;
}
racional racional::operator-(const racional &r) const throw(error)
{
    int min;
    min = mcm(r.denom(), _d);
    _n = (_n * min) - (r.num());
    _d = min;
    simplificar();
    return *this;
}
racional racional::operator*(const racional &r) const throw(error)
{
    _d = r.denom() * _d;
    _n = r.num() * _n;
    simplificar();
    return *this;
}
racional racional::operator/(const racional &r) const throw(error)
{
    _d = _d * r.num();
    _n = _n * r.denom();
    simplificar();
    return *this;
}

/* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
   el racional sobre el que s'aplica el mètode és igual (==), diferent
   (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
   que el racional r.*/
bool racional::operator==(const racional &r) const throw()
{
    if (r.denom() == _d && r.num() == _n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool racional::operator!=(const racional &r) const throw()
{
    if (r.denom() != _d && r.num() != _n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool racional::operator<(const racional &r) const throw()
{
    int p_entera = part_entera();
    if (r.part_entera() < p_entera)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool racional::operator<=(const racional &r) const throw()
{
    int p_entera = part_entera();
    if (r.part_entera() <= p_entera)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool racional::operator>(const racional &r) const throw()
{
    int p_entera = part_entera();
    if (r.part_entera() >= p_entera)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool racional::operator>=(const racional &r) const throw()
{
    int p_entera = part_entera();
    if (r.part_entera() >= p_entera)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int racional::mcd(int n1, int n1)
{
    int mcd(int n1, int n2)
    {
        int hcf;
        if (n2 > n1)
        {
            int temp = n2;
            n2 = n1;
            n1 = temp;
        }

        for (int i = 1; i <= n2; ++i)
        {
            if (n1 % i == 0 && n2 % i == 0)
            {
                hcf = i;
            }
        }
        if (hcf == 0)
        {
            hcf = n1 * n2;
        }
        return hcf;
    }
}

void racional::simplificar()
{
    bool negatiu = false;
    if (_d < 0)
    {
        _d = _d * -1;
        negatiu = true;
    }
    else if (_n < 0)
    {
        _n = _n * -1;
        negatiu = true;
    }
    int gcd = mcd(_n, _d);
    if (gcd != 0)
    {
        _n = _n / gcd;
        _d = _d / gcd;
    }
    if (negatiu)
        _n = _n * -1;
}

int racional::mcm(int a, int b)
{
    return (a * b) / mcd(a, b);
}