// exercise_14.39.cpp : Defines the entry point for the console application.
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
    Boundry(size_t n):sz(n){}
    bool operator()(const string &s) const
    {
        return (s.size() == sz);
    }
private:
    size_t sz;
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
    for (auto i = 0; i < 50;++i)
    {
        if(auto n = count_if(text.cbegin(), text.cend(), Boundry(i)))
        std::cout << i << " length words has" << n << "." << std::endl;
    }

    return 0;
}

