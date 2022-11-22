#include <iostream> 
#include "racional.hpp"

#include <string>
#include <vector>
#include <list>
#include <utility>

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <esin/error>
#include <esin/util>

int main(){
    int a, int b;
    cin >> a;
    cin >> b;
    racional r(a, b);
    cout << racional._n << "/" << racional._d << endl;
}