// exercise_03.45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

int main()
{
    int arr[3][4] = { 1,2,3,4,5,6,7,8,9,0,1,2 };

    for (auto &i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    for (auto p = begin(arr); p != end(arr); ++p)
    {
        for ( auto q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    for (auto m = 0; m != 3; ++m)
    {
        for (auto n = 0; n != 4; ++n)
        {
            cout << arr[m][n] << " ";
        }
        cout << endl;
    }

    //differ
    return 0;
}

