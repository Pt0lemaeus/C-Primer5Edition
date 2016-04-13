// exercise_12.27.cpp : Defines the entry point for the console application.
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
    QueryResult qr(tq);
    while (true)
    {
        cout << "enter word to look for, or q to quit: " << endl;
            string s;
        if (!(cin >> s) || s == "q") break;

        qr.print(cout, tq.query(s)) << endl;
    }
    return 0;
}

