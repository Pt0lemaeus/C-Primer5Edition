#pragma once
#include <iostream>
#include <iterator>
//#include <cstddef>
template<typename T, unsigned N> void print(const T(&p)[N])
{
    for (const T* iter = std::begin(p); iter != std::end(p); iter++)
    {
        std::cout << *iter << std::endl;
    }
    //for (size_t i = 0; i != N; ++i)
    //{
    //    std::cout << p[i] << std::endl;
    //}
}