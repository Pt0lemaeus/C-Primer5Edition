// exercise_04.22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0;
    while (cin >> i)
    {
        string finalgrade = (i > 90) ? "hign pass"
           : (i < 60) ? "fail" 
            :(i<75)?"low pass":"pass" ;
        cout << finalgrade << endl;
    }  
    return 0;
}

