// exercise_16.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "template.h"

int main()
{
    int ia[5]{ 1,2,3,4,5 };
    const int *beg = begina(ia), *end = enda(ia);

    while (beg != end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }

    return 0;
}

