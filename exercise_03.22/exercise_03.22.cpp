// exercise_03.22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
int main()
{
    string word;
    vector<string> para;
    while (getline(cin, word))
    {
        para.push_back(word);
    }

    //print all
    for (auto it = para.cbegin(); it != para.cend(); ++it)
    {
        if (!it->empty())
        {
            cout << *it;
        }
        else
        {
            cout << endl;
        }    
    }
    cout << endl;

    //print first 
    for (auto it = para.cbegin(); it != para.cend() && !it->empty(); ++it)
    {

            cout << *it;
    }
    cout << endl;

    //upadate first para to uppercase
    for (auto it = para.begin(); it != para.end() && !it->empty(); ++it)
    {
        for (auto its = it->begin(); its != it->end(); ++its)
        {
            *its = toupper(*its);
        }
    }

    //print all
    for (auto it = para.cbegin(); it != para.cend(); ++it)
    {
        if (!it->empty())
        {
            cout << *it;
        }
        else
        {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}

