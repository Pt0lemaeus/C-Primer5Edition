// exercise_03.35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstddef>
#include <iterator>
using namespace std;
int main()
{
    const int n = 10;
    int arr[n];

    for (auto val : arr)
    {
        cout << val << endl;
    }

    auto b = begin(arr), e = end(arr);
    while(b != e)
    {
        *b = 0;
        cout << *b++ << endl;
    }
    return 0;
}

