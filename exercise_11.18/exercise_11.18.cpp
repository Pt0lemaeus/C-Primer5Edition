// exercise_11.18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;


int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    map<string,size_t>::const_iterator map_it = word_count.cbegin();
    while (map_it != word_count.cend())
    {
        cout << map_it->first << " occurs "
            << map_it->second << " times" << endl;
        ++map_it;
    }
    return 0;
}

