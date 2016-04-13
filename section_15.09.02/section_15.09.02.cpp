// section_15.09.02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class B
{
    friend void f();
protected:
    int i;
    ~B() = default;
private:
    int j;
};

class D :private B
{
private:
    int k;
};


int main()
{
    D d;
    B b;
    
    return 0;
}

void f()
{
    B b;
    b.i;
    b.j;
    D d;
    d.i;
    d.j;
    
    //d.k;
    //D::j;
}
