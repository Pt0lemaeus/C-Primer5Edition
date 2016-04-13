// exercise_03.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string word;
    while (getline(cin,word))
    {
        for (auto &c : word)
            c = 'X';
        cout << word << endl;
    }
    return 0;
}

