// exercise_09.33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{ 1,2,3,4,5 };

    auto begin = v.begin();

    while (begin != v.end())
    {
        ++begin;
        v.insert(begin, 42);
        ++begin;
    }

    for (auto c : v)
    {
        cout << c << endl;
    }
    return 0;
}

