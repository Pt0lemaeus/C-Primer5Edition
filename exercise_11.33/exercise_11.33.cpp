// exercise_11.33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
using std::map;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <exception>
using std::runtime_error;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

map<string,string> buildMap(ifstream&map_file)
{
    map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string& transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input, ofstream &output)
{
    auto trans_map = buildMap(map_file);
        string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                output << " ";
            output << transform(word, trans_map);

        }
        output << endl;

    }
}
int main(int argc, char* argv[])
{
    ifstream rulesfile(argv[1]);
    ifstream textfile(argv[2]);
    ofstream outfile(argv[3]);
    word_transform(rulesfile, textfile, outfile);
    return 0;
}

