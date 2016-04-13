// exercise_12.23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <memory>
using std::unique_ptr;

#include <string>
using std::string;

#include <iterator>
using std::begin;
using std::end;

unique_ptr<char[]> concate_string(const string &str1,const string &str2)
{
    unique_ptr<char[]> up(new char[str1.size() + str2.size()]);
    size_t i = 0;
    for (auto it = str1.begin(); it != str1.end();++it)
    {
        up[i] = *it;
        ++i;
    }

    for (auto it = str2.begin(); it != str2.end();++it)
    {
        up[i] = *it;
        ++i;
    }

    return up;
}
int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    unique_ptr<char[]> up (concate_string(s1, s2)),eof;
    //for (size_t i = 0;i != end;++i)
    //{
    //    cout << up[i];
    //}

    return 0;
}

