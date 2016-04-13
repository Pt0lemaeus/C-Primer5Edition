// section_10.03.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;

int main()
{
    //void fun1();
    {
        int v1 = 42;
        int *p1 = &v1;
        auto f = [p1] {return *p1;};
        v1 = 0;
        cout <<f();
    };
    //f();
    return 0;
}

