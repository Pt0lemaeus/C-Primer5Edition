// exercise_3.20.cpp : Defines the entry point for the console application.
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

    for (decltype(data.size()) ix = 0; ix < data.size(); ++ix)
    {
        cout << data[ix] + data[data.size() - 1 - ix] << endl;
    }

    for (decltype(data.size()) ix = 0; ix < data.size()-1; ++ix)
    {
        cout << data[ix] + data[ix+1] << endl;
    }
    return 0;
}

