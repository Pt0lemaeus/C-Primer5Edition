// exercise_10.28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <algorithm>
using std::unique_copy;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::inserter;
using std::front_inserter;
using std::back_inserter;

#include <list>
using std::list;

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    list<int> vi1;
    list<int> vi2;
    list<int> vi3;

    copy(vi.cbegin(), vi.cend(), inserter(vi1, vi1.begin()));
    copy(vi.cbegin(), vi.cend(), front_inserter(vi2));
    copy(vi.cbegin(), vi.cend(), back_inserter(vi3));
    for (auto c : vi1)
    {
        cout << c << " ";
    }
    cout << endl;
    for (auto c : vi2)
    {
        cout << c << " ";
    }
    cout << endl;
    for (auto c : vi3)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}

