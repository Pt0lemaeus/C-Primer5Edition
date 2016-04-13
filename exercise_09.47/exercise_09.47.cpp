// exercise_09.47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void find_char(const string &, const string&);
void find_not_char(const string &, const string&);
int main()
{
    string s{ "ab2c3d7R4E6" };
    cout << "find number:" << endl;
    find_char(s, "0123456789");
    find_not_char(s, "abcdefghijklmnopqrstuvwxyz"\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << "find char:" << endl;
    find_char(s, "abcdefghijklmnopqrstuvwxyz"\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    find_not_char(s, "0123456789");
    return 0;
}

void find_char(const string &s, const string &r)
{
    string::size_type p = 0;
    while ((p = s.find_first_of(r, p)) != string::npos)
    {
        cout << "char : " << s[p] << ", position: " << p << endl;
        ++p;
    }
}

void find_not_char(const string &s, const string &r)
{
    string::size_type p = 0;
    while ((p = s.find_first_not_of(r, p)) != string::npos)
    {
        cout << "char : " << s[p] << ", position: " << p << endl;
        ++p;
    }
}