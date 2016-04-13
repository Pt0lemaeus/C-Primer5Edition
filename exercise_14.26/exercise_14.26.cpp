// exercise_14.26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "StrBlob.h"

int main()
{
    std::vector<int> vi = { 1,2,3,4,4 };
    std::vector<int>* p = &vi;
    std::cout << (*p)[1];
    return 0;
}

