// exercise_11.14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


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

#include <utility>
using std::pair;

int main(int agrc, char* argv[])
{
    ofstream out(argv[1], ofstream::app);
    string line, lastname, name, birthday;
    map<string, vector<pair<string,string>>> familily;
    while (getline(cin, line))
    {
        istringstream record(line);
        record >> lastname;
        while (record >> name >> birthday)
            familily[lastname].push_back({ name,birthday });
    }
    for (const auto &w : familily)
    {
        out << w.first;
        for (const auto &s : w.second)
        {
            out << " " << s.first << " "<<s.second;
        }
        out << endl;
    }
    return 0;
}

