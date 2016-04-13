// exercise_13.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

struct Y
{
    Y() { std::cout << "Y()" << std::endl; }
    Y(const Y&) { std::cout << "Y(const Y&)" << std::endl; }
    Y& operator=(const Y&) { std::cout << "Y& operator=(const Y&)" << std::endl; return *this; }
};
struct X {
    X() { std::cout << "X()" << std::endl;}
    X(const X& org) { std::cout << "X(const X&)" << std::endl; 
    tets = new Y(*org.tets); }
    X& operator=(const X&org) { std::cout << "X& operator=(const X&)" << std::endl; 
    auto newps = new Y(*org.tets);
    //delete tets;
    tets = newps;return *this; }
    ~X(){ std::cout << "~X()" << std::endl; }
    Y *tets;
};

void noreference(X x)
{
    std::cout << "void noreference(X x)" << std::endl;
}

void reference(X& x)
{
    std::cout << "void noreference(X& x)" << std::endl;
}

int main()
{
    std::cout << "declare x y z begin" << std::endl;
    X x, y,z;
    std::cout << "declare x y z end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "call noreference begin" << std::endl;
    noreference(x);
    std::cout << "call noreference end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "call reference begin" << std::endl;
    reference(y);
    std::cout << "call reference end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "dynamical memory begin" << std::endl;
    X* d = new X();
    X* e;
    delete d;
    //delete e;
    std::cout << "dynamical memory end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "vector begin" << std::endl;
    std::vector<X> v;
    std::cout << "vecor end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "vector push begin" << std::endl;
    v.push_back(z);
    std::cout << "vector push end" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "assignment begin" << std::endl;
    x = y;
    std::cout << "assignment end" << std::endl;
    return 0;
}

