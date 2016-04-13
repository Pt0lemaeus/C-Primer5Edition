// exercise_09.28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void insert_string(forward_list<string>&, const string&, const string&);
int main()
{
    forward_list<string> flst = { "Hello","!","How","are","you"};
    for (auto str : flst)
    {
        cout << str << " ";
    }
    cout << endl;
    insert_string(flst, "Hello", "World");
    insert_string(flst, "How", "Old");
    insert_string(flst, "You", "?");
    for (auto str : flst)
    {
        cout << str << " ";
    }
    return 0;
}

void insert_string(forward_list<string>&flst, const string &str1, const string &str2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr == str1)
        {
            flst.insert_after(curr, str2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    flst.insert_after(prev, str2);
    return;
}
