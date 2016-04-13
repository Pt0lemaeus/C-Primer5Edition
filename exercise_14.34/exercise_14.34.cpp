// exercise_14.34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Test
{
public:
    int operator()(int a, int b, int c) { return a ? b : c; }
};

int main()
{
    return 0;
}

