// exercise_03.24.cpp : Defines the entry point for the console application.
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

    for (auto ix = data.begin(); ix != data.end(); ++ix)
    {
        cout << *ix + *(data.end()-1-ix+data.begin()) << endl;
    }

    for (auto ix = data.begin(); ix != data.end() - 1; ++ix)
    {
        cout << *ix + *(ix + 1) << endl;
    }
    return 0;
}

