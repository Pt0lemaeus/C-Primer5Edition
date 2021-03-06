// exercise_11.08.cpp : Defines the entry point for the console application.
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

#include <map>
using std::map;

//#include <set>
//using std::set;
#include<vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find;

int main(int argc, char* argv[])
{
    map<string, size_t> word_count;
    vector<string> exclude = { "The", "But", "And", "Or", "A"
        "the", "but", "and", "or", "a" };
    //vector<char> exclude_char = { '.','|',',' };
    string  word;
    ifstream in(argv[1]);
    ofstream out(argv[2]/*, ofstream::app*/);
    while (in >> word)
    {
        //for (auto i = word.begin(); i != word.end(); ++i)
        //{
        //    if (exclude_char.find(*i) != exclude_char.end())
        //        i = word.erase(i);
        //    if (i == word.end())
        //        break;
        //}

        //if (word[0] >= 'A' && word[0] <= 'Z')
        //    word[0] -= ('A' - 'a');
        if (find(exclude.begin(),exclude.end(),word) == exclude.end())
            ++word_count[word];
    }
    for (const auto&w : word_count)
        out << w.first << " occurs " << w.second
        << ((w.second > 1) ? " times" : " time") << endl;
    in.close();
    out.close();
    return 0;
}

