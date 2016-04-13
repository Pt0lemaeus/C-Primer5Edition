// section_15.06_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

struct Base
{
    Base():mem(0)
    {
        int* p = &mem;
    }
protected:
    int mem;
};

struct Derived :Base
{
    Derived(int i):mem(i)
    {
        int* q = &mem;
    }
    int get_mem()
    { 
        int* r = &mem; 
        return Base::mem; }
protected:
    int mem;
};
int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;
    return 0;
}

