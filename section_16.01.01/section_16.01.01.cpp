// section_16.01.01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    int i,j;
    const int & v = i;
    v = &j;
    v = 2;
    i = 2;
    return 0;
}

