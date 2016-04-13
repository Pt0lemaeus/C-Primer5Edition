// exercise_03.31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    constexpr size_t arrary_size = 10;
    int ia[arrary_size];
    for (size_t ix = 0; ix < arrary_size; ++ix)
    {
        ia[ix] = ix;
    }
    return 0;
}

