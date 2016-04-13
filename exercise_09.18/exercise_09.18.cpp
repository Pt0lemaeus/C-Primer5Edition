// exercise_09.18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    deque<string> dq1;
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

