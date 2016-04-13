// exercise_03.43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    int arr[3][4] = { 1,2,3,4,5,6,7,8,9,0,1,2 };

    for(int (&i)[4] : arr)
    { 
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    for (int(*p)[4] = begin(arr); p != end(arr); ++p)
    { 
        for (int *q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    for (int m = 0; m !=3; ++m)
    {
        for (int n = 0; n != 4; ++n)
        {
            cout << arr[m][n] << " ";
        }
        cout << endl;
    }

    return 0;
}

