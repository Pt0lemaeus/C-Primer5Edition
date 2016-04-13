// exercise_05.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
    int sum = 0, val = 1;
    while (val++ <= 10)
        sum += val - 1;
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;
    return 0;
}

