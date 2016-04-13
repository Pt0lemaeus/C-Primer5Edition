// section_15.05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Base
{
    friend void base_friend(Base&);
    friend void base_friend(int);
private:
    int privated;
protected:
    int proteced;
public:
    void test_privated()
    {
        privated = 1;
    }

    void test_protected()
    {
        proteced = 1;
    }

};

class Drived:public Base
{
    friend void d_friend(Base&);
    friend void d_friend(Drived&);
    friend void d_friend(int);
public:
    //void test_privated()

    void test_protected()
    {
        proteced = 1;
    }
};
class SecondDrived:public Drived
{
public:
    //void test_privated()
    //{
    //    privated = 1;
    //}

    void test_protected()
    {
        proteced = 1;
    }
};
int main()
{
    Base base;
    //base.
    Drived derived;

    derived.
    return 0;
}

void base_friend(Base &s)
{
    s.proteced;
    s.privated;
}

void base_friend(int)
{
    Base s;
    s.privated;
    s.proteced;
}

void d_friend(Base &s)
{
    s.proteced;
}

void d_friend(Drived &s)
{
    s.proteced;
}

void d_friend(int)
{
    Base s;
    s.proteced;
    Drived d;
    d.proteced;
    
}
