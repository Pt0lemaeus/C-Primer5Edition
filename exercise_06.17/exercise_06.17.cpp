// exercise_06.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

bool HasUpper(const string& str)
{
    for (auto c : str)
    {
        if (isupper(c))
            return true;
    }
    return false;
}

void Change2Lower(string& str)
{
    for (auto &c : str)
        c = tolower(c);
}

int main()
{
    string str;
    cin >> str;

    if (HasUpper(str))
    {
        Change2Lower(str);
        cout << str << endl;
    }
    else
        cout << "No Upper." << endl;
    return 0;
}

