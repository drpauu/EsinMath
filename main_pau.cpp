#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <esin/error>
#include <esin/util>

#include "racional.cpp"
#include "token.hpp"

using namespace std;

int main()
{
    int n1, n2;
    token a(n1);
    token b(n2);
    if(a == b){
        cout << "funciona" << endl;
    }
    exit(0);
}