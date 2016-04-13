// exercise_11.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <vector>
using std::vector;

#include <iostream>
using std::endl;

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    string s;
    int v;

    vector<pair<string, int>> vs;
    while (in >> s && in >> v)
    {
        vs.push_back({ s,v });
    }

    for (const auto &w : vs)
    {
        out << w.first << " " << w.second << endl;
    }
    return 0;
}

