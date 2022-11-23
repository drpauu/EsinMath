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

using namespace std;

int main()
{
    int a = 0, b = 0;
    cin >> a;
    cin >> b;
    racional r = racional(a, b);
    cout << r.num() << "/" << r.denom() << endl;
    cout << r.part_entera() << endl;
}