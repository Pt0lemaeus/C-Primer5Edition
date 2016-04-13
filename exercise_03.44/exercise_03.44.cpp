// exercise_03.44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    int arr[3][4] = { 1,2,3,4,5,6,7,8,9,0,1,2 };

    using int_array = int[4];

    for (int_array &i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int_array *p = begin(arr); p != end(arr); ++p)
    {
        for (int *q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }


    return 0;
}

