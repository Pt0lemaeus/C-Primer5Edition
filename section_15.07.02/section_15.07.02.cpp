// section_15.07.02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <utility>
class B
{
public:
    B() = default;;
    //B(const B&) = default;
    //B(B&&) = default;
    
    virtual ~B() = default;
    //B mem;
};

class D: public B{};
int main()
{
    B e;
    B b = std::move(e);
    B h ,j;
    h = j;
    B f(b);
    D d;
    D d2(d);
    D d3(std::move(d));
    return 0;
}

