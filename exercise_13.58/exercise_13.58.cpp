// exercise_13.58.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
class Foo {
public:
    Foo();
    Foo(const Foo&) {};
    //Foo sorted() const &;
    //Foo sorted() && ;
};

//Foo Foo::sorted() const & 
//{
//    std::cout << "left sorted!" << std::endl;
//    return Foo(*this).sorted();
//}
//
//Foo Foo::sorted() &&
//{
//    std::cout << "right sorted!" << std::endl;
//    return *this;
//}


int main()
{
    //Foo fo;
    //try{ fo.sorted(); }
    //catch (std::overflow_error e)
    //{
    //    std::cout << e.what() << std::endl;
    //}


    return 0;
}

