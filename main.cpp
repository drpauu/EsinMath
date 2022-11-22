#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <esin/error>
#include <esin/util>

#include "racional.hpp"

using namespace std;

int main(){
    int a, b;
    cin >> a;
    cin >> b;
    racional r(a, b);
    //cout << r.num() << "/" << r.denom() << endl;
}