// exercise_08.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "PersonInfo.h"
#include <functional>
using namespace std;
bool valid(const string&);
string format(const string&);
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
    vector<PersonInfo> people;
    while (getline(in, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
       
    }
    
    ostringstream os;
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            os << entry.name << " "
            << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << "invalid number(s)" << badNums.str() << endl;
    }
    cout << os.str();
    return 0;
}

bool valid(const string &s)
{
    if (s.empty())
        return false;
    else
        return true;
}

string  format(const string &s)
{
    string r("Phone number:");
    return (r += s);
    // TODO: insert return statement here
}
