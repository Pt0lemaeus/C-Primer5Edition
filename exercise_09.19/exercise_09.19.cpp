// exercise_09.19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    list<string> dq1;
    while (cin >> s)
    {
        dq1.push_back(s);
    }
    for (auto &c : dq1)
    {
        cout << c << endl;
    }
    return 0;
}

