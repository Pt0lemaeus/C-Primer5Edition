// exercise_04.29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    return 0;
}

