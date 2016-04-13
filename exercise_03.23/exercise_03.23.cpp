// exercise_03.23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> data;
    while (cin >> n)
    {
        data.push_back(n);
    }

    for (auto i = data.begin(); i != data.end();++i)
    {
        *i *= *i;
    }

    for (auto i = data.cbegin(); i != data.cend(); ++i)
    {
        cout << *i << " ";
    }
    return 0;
}

