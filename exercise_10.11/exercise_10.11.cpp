// exercise_10.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
bool isShorter(const string&, const string&);
int main()
{
    string s;
    vector<string> vs;
    while (cin >> s)
    {
        vs.push_back(s);
    }
    cout << "End iput:" << endl;
    cout << vs.size() << endl;
    for (auto s : vs)
    {
        cout << s << " ";
    }
    cout << endl;

    sort(vs.begin(), vs.end());

    cout << "End sort:" << endl;
    cout << vs.size() << endl;
    for (auto s : vs)
    {
        cout << s << " ";
    }
    cout << endl;

    auto end_unique = unique(vs.begin(), vs.end());
    cout << "End unique:" << endl;
    cout << vs.size() << endl;
    for (auto s : vs)
    {
        cout << s << " ";
    }
    cout << endl;

    vs.erase(end_unique, vs.end());
    cout << "End erase:" << endl;
    cout << vs.size() << endl;
    for (auto s : vs)
    {
        cout << s << " ";
    }
    cout << endl;

    stable_sort(vs.begin(), vs.end(), isShorter);

    cout << "After stable sort:" << endl;
    cout << vs.size() << endl;
    for (auto s : vs)
    {
        cout << s << " ";
    }
    return 0;
}

bool isShorter(const string &s1, const string &s2)
{

    return s1.size() < s2.size();
}
