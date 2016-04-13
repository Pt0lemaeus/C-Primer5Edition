// exercise_16.05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "template.h"

int main()
{
    const int ia[9] = { 1,2,3,4,5,4,21,0 };
    char ic[8]{ 'x','v' };
    auto iter = std::begin(ia);
   print(ia);
    print(ic);
    return 0;
}

