// exercise_08.10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "No input file!" << endl;
        return -1;
    }
    
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open input file!" << endl;
        return -1;
    }
    string line, word;
    vector<string> vs;
    while (getline(in, line))
    {
        vs.push_back(line);
    }

    
    for (auto s : vs)
    {
        istringstream record(s);
        //record.open()
        while (record >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}

