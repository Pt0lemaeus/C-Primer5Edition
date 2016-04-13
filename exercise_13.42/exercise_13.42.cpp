// exercise_13.42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "TextQuery.h"

int main(int argc, char* argv[])
{
    ifstream infile(argv[1]);
    TextQuery tq(infile);

    while (true)
    {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;

        print(cout, tq.query(s)) << endl;
    }
    return 0;
}

