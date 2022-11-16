#include "racional.hpp"

using namespace std;

// Constructora. Construeix un racional en la seva versió simplificada.
// Es produeix un error si el denominador és 0.
racional::racional(int n = 0, int d = 1) throw(error){
    if(d == 0){
        throw(error);
    }
    _d = d;
    _n = n;
}

// Constructora per còpia, assignació i destructora.
racional::racional(const racional &r) throw(error)
{
    _d = r._d;
    _n = r._d;
}
racional & racional::operator=(const racional &r) throw(error)
{
    _d = r._d;
    _n = r._d;
    return r; 
}
racional::~racional() throw()
{
    _n = 0;
    _d = 1;
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
    return *this;
}

/* Sobrecàrrega d'operadors aritmètics. Retorna un racional en la seva
   versió simplificada amb el resultat de l'operació. Es produeix un
   error al dividir dos racionals si el segon és 0.*/
racional racional::operator+(const racional &r) const throw(error)
{
    int min; 
    min = mcm(r._d, _d);
    _n = (_n*min) + (r._n);
    _d = min;
    // funciona
}
racional racional::operator-(const racional &r) const throw(error)
{
    return *this;
}
racional racional::operator*(const racional &r) const throw(error)
{
    _d = r._d * _d;
    _n = r._n * _n;
}
racional racional::operator/(const racional &r) const throw(error)
{
    return *this;
}

/* Sobrecàrrega de operadors de comparació. Retornen cert, si i només si
   el racional sobre el que s'aplica el mètode és igual (==), diferent
   (!=), menor (<), menor o igual (<=), major (>) o major o igual(>=)
   que el racional r.*/
bool racional::operator==(const racional &r) const throw()
{
    if(r._d == _d && r._n == _n){
        return true;
    } else {
        return false;
    }
}
bool racional::operator!=(const racional &r) const throw()
{
    if(r._d != _d && r._n != _n){
        return true;
    } else {
        return false;
    }
}
bool racional::operator<(const racional &r) const throw()
{
    int p_entera = part_entera();
    if(r.part_entera() < p_entera){
        return true;
    } else {
        return false;
    }
}
bool racional::operator<=(const racional &r) const throw()
{
    if(r.part_entera() <= *this.part_entera()){
        return true;
    } else {
        return false;
    }
}
bool racional::operator>(const racional &r) const throw()
{
    if(r.part_entera() >= *this.part_entera()){
        return true;
    } else {
        return false;
    }
}
bool racional::operator>=(const racional &r) const throw()
{
    if(r.part_entera() >= *this.part_entera()){
        return true;
    } else {
        return false;
    }
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

void racional::simplificar(){
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

int racional::mcm(int a, int b){
    return (a*b)/mcd(a, b);
}