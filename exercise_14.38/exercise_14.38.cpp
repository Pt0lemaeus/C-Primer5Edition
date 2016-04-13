// exercise_14.38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
using std::ifstream;
#include <iostream>
#include <vector>
using std::vector;
#include<string>
using std::string;
#include <algorithm>
using std::count_if;

class Boundry
{
public:
    bool operator()(const string &s) const
    {
        return ((s.size() < 10) && (s.size() > 1));
    }
};

int main(int argc, char* argv[])
{
    ifstream file(argv[1]);
    string word;
    vector<string> text;
    while (file >> word)
    {
        text.push_back(word);
    }
    auto n = count_if(text.cbegin(), text.cend(), Boundry());
    std::cout << n << std::endl;
    return 0;
}

