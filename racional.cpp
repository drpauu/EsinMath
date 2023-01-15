#include "racional.hpp"
#include <cmath>

using namespace std;

// Constructora. Construeix un racional en la seva versió simplificada.
// Es produeix un error si el denominador és 0.
racional::racional(int n, int d) throw(error)
{
    if (d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        pair<int, int> simplificat = simplificar(n, d);
        _n = simplificat.first;
        _d = simplificat.second;
        _part_entera = calcula_part_entera();
        _residu = calcula_residu();
        this->simplificar(_n, _d);
    }
}

// Constructora per còpia, assignació i destructora.
racional::racional(const racional &r) throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {   pair<int, int> simplificat = simplificar(r._n, r._d);
        _n = simplificat.first;
        _d = simplificat.second;
        _part_entera = r.part_entera();
        _residu.first = r._residu.first;
        _residu.second = r._residu.second;
    }
}
racional &racional::operator=(const racional &r) throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        pair<int, int> simplificat = simplificar(r._n, r._d);
        _n = simplificat.first;
        _d = simplificat.second;
        _part_entera = r.part_entera();
        _residu.first = r._residu.first;
        _residu.second = r._residu.second;
        return *this;
    }
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
    return _part_entera;
}
racional racional::residu() const throw()
{
    return racional(_residu.first, _residu.second);
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
racional racional::operator+(const racional &r) const throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        racional aux;
        pair<int, int> simplificat;
        aux._n = _n * r._d + r._n * _d;
        aux._d = _d * r._d;
        simplificat = aux.simplificar(aux._n, aux._d);
        aux._n = simplificat.first;
        aux._d = simplificat.second;
        return aux;
    }
}
racional racional::operator-(const racional &r) const throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        racional aux;
        pair<int, int> simplificat;
        aux._n = _n * r._d - r._n * _d;
        aux._d = _d * r._d;
        simplificat = aux.simplificar(aux._n, aux._d);
        aux._n = simplificat.first;
        aux._d = simplificat.second;
        return aux;
    }
}
racional racional::operator*(const racional &r) const throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        racional aux;
        pair<int, int> simplificat;
        aux._d = r._d * _d;
        aux._n = r._n * _n;
        simplificat = aux.simplificar(aux._n, aux._d);
        aux._n = simplificat.first;
        aux._d = simplificat.second;
        return aux;
    }
}
racional racional::operator/(const racional &r) const throw(error)
{
    if (r._d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        racional aux;
        pair<int, int> simplificat;
        aux._n = _n * r._d;
        aux._d = _d * r._n;
        simplificat = aux.simplificar(aux._n, aux._d);
        aux._n = simplificat.first;
        aux._d = simplificat.second;
        return aux;
    }
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

int racional::mcd(int n1, int n2) throw()
{
    if (n2 > n1)
    {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }
    while (n1 % n2 != 0)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp % n2;
    }
    return n2;
}


pair<int, int> racional::simplificar(int n, int d) throw(error)
{
    if (d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        if (n == 0)
        {
            d = 1;
        }
        else
        {
            if (d < 0)
            {
                n = -n;
                d = -d;
            }
            int gcd = mcd(n, d);
            if (gcd != 0)
            {
                n /= gcd;
                d /= gcd;
            }
        }
        pair<int, int> retorn;
        retorn.first = n;
        retorn.second = d;
        return retorn;
    }
}

int racional::mcm(int a, int b) throw()
{
    return (a * b) / mcd(a, b);
}

int racional::calcula_part_entera() throw ()
{
    int divisio = floor(float(_n) / float(_d));
    return divisio;
}

pair<int, int> racional::calcula_residu() throw(error)
{
    if (_d == 0)
    {
        throw error(DenominadorZero);
    }
    else
    {
        pair<int, int> residu;
        int num_residu;
        num_residu = -1 * (_part_entera * _d) + _n;
        residu = simplificar(num_residu, _d);
        return residu;
    }
}