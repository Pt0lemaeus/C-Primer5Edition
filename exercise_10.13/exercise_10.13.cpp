// exercise_10.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool isShorter5(const string&);
int main()
{
    string s;
    vector<string> vs;
    while (cin >> s)
    {
        vs.push_back(s);
    }
    auto p = partition(vs.begin(), vs.end(), isShorter5);
    vs.erase(p, vs.end());
        for (auto s : vs)
        {
            cout << s << endl;
        }
    return 0;
}

bool isShorter5(const string &s)
{
    return s.size() < 5;
    return false;
}
