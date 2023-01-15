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


int main()
{   
    /*int r1 = 0, r2 = 1;
    cin >> r1;
    cin >> r2;
    racional r = racional(r1, r2), residu;
    cout << "racional: " << r.num() << "/" << r.denom() << endl;
    cout << "part entera: " << r.part_entera() << endl; 
    residu = r.residu();
    cout << "residu: " << residu.num() << '/' << residu.denom() << endl;
    racional x = r + r;
    cout << "n: " << x.num() << "d: " << x.denom() << endl;*/
//}

// TOKEN:
//int main()
//{
    //int n1 = 1;
    //int n2 = 1;
    racional n3 = racional(1, 2);
    racional n4 = racional(1, 2);
    /*double n5 = 1.23;
    double n6 = 4.56;
    string n7 = "ab";
    string n8 = "cd";*/
    token t1(n3);
    token t2(n4);
    /*token t3(n3);
    token t4(n4);
    token t5(n5);
    token t6(n6);
    token t7(n7);
    token t8(n8);
    token t9(token::SUMA);
    token t10(token::MULTIPLICACIO);
    token t11(token::CT_E);*/
    if(t1 == t2)
    {
        cout << "t2 i t3 són iguals: " << t1.valor_enter() << endl;
    }
    /*else
        cout << "t2 i t3 són diferents" << endl;
    
    if(t4 < t5)
    {
        cout << "t4 és més petit que t5" << endl;
    }
    else
        cout << "t4 és igual/més gran que t5" << endl;*/
    
    return 0;
}