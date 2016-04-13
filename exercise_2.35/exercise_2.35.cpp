// exercise_2.35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<typeinfo>

int main()
{
    const int i = 42;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    //j2 = 7;
    k2 = 0;
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
    return 0;
}

