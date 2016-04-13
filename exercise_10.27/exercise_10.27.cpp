// exercise_10.27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <algorithm>
using std::unique_copy;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::inserter;

int main()
{
    vector<int> vi{ 1,1,2,2,3,4,5,565,4,3,12,2,3,3,565,56,23,1,2,4 };
    vector<int> vi1;
    unique_copy(vi.cbegin(), vi.cend(), inserter(vi1, vi1.begin()));
    for (auto c : vi1)
    {
        cout << c << endl;
    }
    return 0;
}

