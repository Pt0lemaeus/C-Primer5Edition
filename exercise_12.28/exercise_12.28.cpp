// exercise_12.28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cctype>

void low_case_all(std::string&);
void delete_symbol(std::string&);

int main(int argc, char* argv[])
{
    ifstream infile(argv[1]);
    std::shared_ptr<std::vector<std::string>> text;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> result;
    text = std::make_shared<std::vector<std::string>>();
    result = std::make_shared<std::map<std::string, std::set<size_t>>>();
    size_t line_No = 0;
    std::string  line;
    while (std::getline(infile, line))
    {
        text->push_back(line);
    }
    while (true)
    {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;
        low_case_all(s);
        size_t line_No = 0;
        std::string word;
        if (text->size() == 0)
            throw std::runtime_error("Query in a null file!");
        if (result->find(s) == result->end())
        {
            for (const auto &line1 : *text)
            {
                std::istringstream is(line1);
                while (is >> word)
                {
                    low_case_all(word);
                    delete_symbol(word);
                    if (word == s)
                        result->operator[](word).insert(line_No);
                }
                ++line_No;
            }
        }


        auto ret = result->find(s);
        if (ret != result->end())
        {
            cout << ret->first << " occurs " << ret->second.size() << " time" << ((ret->second.size() > 1) ? "s." : ".") << std::endl;
            for (auto c : ret->second)
            {
                cout << "(line" << c << ")" << text->operator[](c) << std::endl;
            }
        }
        else
        {
            cout << s << " occurs 0 time." << std::endl;
        }
    }
    return 0;
}

void low_case_all(std::string& word)
{
    for (auto &c : word)
    {
        c = std::tolower(c);
    }
}

void delete_symbol(std::string& word)
{
    const static std::set<char> exclude_char = { '.','|',',','?','!',':','(',')' };
    for (auto i = word.begin(); i != word.end(); ++i)
    {
        if (exclude_char.find(*i) != exclude_char.end())
            i = word.erase(i);
        if (i == word.end())
            break;
    }
}