// exercise_09.49.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
        return -1;

    ifstream in(argv[1]);
    if (!in)
        return -1;
    string s, longest_word;
    unsigned max_length = 0;
    while (in >> s)
    {
        if (s.find_first_of("bdfghjklpqty-ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!$") != string::npos)
            continue;
        cout << s << " ";
        if (max_length < s.size())
        {
            max_length = s.size();
            longest_word = s;
        }      
    }
    cout << endl << "longgest word: " << longest_word << endl;
    return 0;
}

