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
#include "token.cpp"

using namespace std;

int main()
{
    string com;
    cin >> com;
    token a(com);
    cout << a.tipus() << endl;
    exit(0);
}