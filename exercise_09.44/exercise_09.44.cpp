// exercise_09.44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <functional>

using namespace std;

void replace_string(string& s, const string& oldVal, const string& newVal);

int main()
{
    string s{ "tho thru tho!" };
    replace_string(s, "thru", "through");
    cout << s << endl;

    replace_string(s, "tho", "though");
    cout << s << endl;

    replace_string(s, "through", "");
    cout << s << endl;
    return 0;
}

void replace_string(string& s, const string& oldVal, const string& newVal)
{
    size_t p = 0;
    while ((p = s.find(oldVal, p)) != string::npos)
    {
        s.replace(p, oldVal.size(), newVal);
        p += newVal.size();
    }
}