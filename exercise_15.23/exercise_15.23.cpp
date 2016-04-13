// exercise_15.23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Base
{
public:
    virtual int fcn();
};

class D1 :public Base
{
public:
    int fcn(int);
    int fcn() override;
    virtual void f2();
};

class D2 :public D1
{
public:
    int fcn(int);
    int fcn();
    void f2();
};
int main()
{
    Base bobj; D1 d1obj; D2 d2obj;
    Base *p1 = &d2obj;
    D1* p2 = &d2obj;
    p2->fcn(42);
    return 0;
}

