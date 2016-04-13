// exercise_08.04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string ifile = "next.txt";
    ifstream in(ifile);
    string s;
    vector<string> vs;
    if (in)
    {
        while (getline(in, s))
        {
            vs.push_back(s);
        }
    }
    for (auto c : vs)
    {
        cout << c << endl;
    }
    return 0;
}

