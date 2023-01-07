#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <esin/error>
#include <esin/util>

#include "token.hpp"

using namespace std;

// RACIONAL:

/*
int main()
{   
    int r1 = 0, r2 = 1;
    cin >> r1;
    cin >> r2;
    racional r = racional(r1, r2), residu;
    cout << "racional: " << r.num() << "/" << r.denom() << endl;
    cout << "part entera: " << r.part_entera() << endl; 
    residu = r.residu();
    cout << "residu: " << residu.num() << '/' << residu.denom() << endl;
}*/

// TOKEN:
int main()
{
    //int n1 = 1;
    //int n2 = 2;
    //racional n3 = racional(1, 2);
    //racional n4 = racional(3, 4);
    //double n5 = 1.23;
    //double n6 = 4.56;
    string n7 = "ab";
    string n8 = "cd";
    token t1(n7);
    token t2(n8);
    token t3(t2);
    token t4(token::SUMA);
    token t5(token::RESTA);
    if(t2 == t3)
    {
        cout << "son iguals" << endl;
    }
    else
        cout << "son diferents" << endl;
    
    if(t4 < t5)
    {
        cout << "és més petit";
    }
    
    return 0;
}