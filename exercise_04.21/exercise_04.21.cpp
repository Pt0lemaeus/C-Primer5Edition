// exercise_04.21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = { 1,23,54,-32,56,78,24,-23,11,123,-13123,3345345,2324,1231,324,23423,23423,232,123 };
    for(auto i:vec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto &c : vec)
    {
       c % 2 ? c *= 2 : c;
    }
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

