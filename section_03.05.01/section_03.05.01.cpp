// section_03.05.01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n[20] = {9};
    n[0] = 9;
    n[2] = 7;
    n[5] = 2;
    for (auto m : n)
    {
        cout << m << " ";
       
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << n[1];
    //cout << endl << "test: ";
    //int test;
    //cout << test;
    return 0;
}

