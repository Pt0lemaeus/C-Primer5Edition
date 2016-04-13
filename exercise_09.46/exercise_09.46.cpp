// exercise_09.46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void add_pre_and_suf(string &name, const string &pre, const string& suf);
int main()
{
    string name{ "John" };
    add_pre_and_suf(name, "Mr. ", " III");
    cout << name << endl;
    return 0;
}

void add_pre_and_suf(string & name, const string & pre, const string & suf)
{
    name.insert(0, pre);
    name.insert(name.size(),suf);

}

