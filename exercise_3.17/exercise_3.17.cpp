// exercise_3.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    string word;
    vector<string> words;

    while (cin>>word)
    {
        words.push_back(word);
    }

    for(auto &var:words)
    {
        for (auto &c : var)
        {
            c = toupper(c);
        }
    }

    for (decltype(words.size()) ix = 0; ix != words.size(); ++ix)
    {
        cout << words[ix] << " ";
        if ((ix+1) % 8 == 0)
            cout << endl;
    }
    return 0;
}

