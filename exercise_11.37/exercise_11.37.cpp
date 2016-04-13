// exercise_11.37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iterator>
using std::istream_iterator;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;
using std::getline;

#include <unordered_map>
using std::unordered_map;

#include <set>
using std::set;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    unordered_map<string, size_t> word_count;
    set<string> exclude = { "The", "But", "And", "Or", "A"
        "the", "but", "and", "or", "a" };
    set<char> exclude_char = { '.','|',',' };
    string  word;
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    while (in >> word)
    {
        for (auto i = word.begin(); i != word.end(); ++i)
        {
            if (exclude_char.find(*i) != exclude_char.end())
                i = word.erase(i);
            if (i == word.end())
                break;
        }
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto&w : word_count)
        out << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    in.close();
    out.close();
    return 0;
}

