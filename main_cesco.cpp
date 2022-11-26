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
    int n1;
    cin>>n1;
    token a(n1);
    cout << a.valor_enter() << endl;
    exit(0);
}