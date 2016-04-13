// exercise_11.07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
using std::map;

#include <iostream>
using std::cin;
using std::endl;

#include <fstream>
using std::ofstream;

#include<vector>
using std::vector;

#include <string>
using std::string;
using std::getline;

#include <sstream>
using std::istringstream;

int main(int agrc, char* argv[])
{
    ofstream out(argv[1], ofstream::app);
    string line, lastname,name;
    map<string, vector<string>> familily;
    while (getline(cin, line))
    {
        istringstream record(line);
        record >> lastname;
        while (record >> name)
            familily[lastname].push_back(name);
    }
    for (const auto &w : familily)
    {
        out << w.first;
        for (const auto &s : w.second)
        {
            out <<" "<< s;
        }
        out << endl;
    }
    return 0;
}

