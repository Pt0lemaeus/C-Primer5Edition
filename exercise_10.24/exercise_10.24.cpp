// exercise_10.24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <functional>
using namespace std::placeholders;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::find_if;

bool greater(int i, const string &s)
{
    return i > s.size();
}

//auto wc = bind(greater, _1)
int main()
{
    vector<int> vi{ 1,2,3,4,5,6,7,8,9 };
    string s;
    while(cin>>s)
    {
       auto iter = find_if(vi.begin(), vi.end(), bind(greater, _1, s));
       cout << *iter << endl;
    }
    return 0;
}

