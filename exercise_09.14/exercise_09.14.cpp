// exercise_09.14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    list<char*> listCStr = { "abc", "123", "!@#" };
    vector<string> vecStr(20);
    vecStr.assign(listCStr.begin(), listCStr.end());
    for (auto c : vecStr)
    {
        cout << c << endl;
    }
    return 0;
}

