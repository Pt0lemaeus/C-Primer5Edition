// section_03.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int ia[3][4] = { {0},{4},{8} };
    //ia[0][0] = 0;
    //for (size_t n = 0; n < 3; ++n)
    //{
    //    for (size_t m = 0; m < 4; ++m)
    //    {
    //        cout << ia[n][m] << " ";
    //    }
    //    cout << endl;
    //   
    //}

    for (auto &row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}

