// section_15.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    int pu = 1;
protected:
    int pr = 2;
};

class Derived:public Base
{};

int main()
{
    Derived d;
    Base b;
    b.pu = 3;
   // b.pr = 4;
    cout << d.pu << endl;
    return 0;
}

