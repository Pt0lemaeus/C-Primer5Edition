// exercise_09.20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <deque>
#include <iostream>

using namespace std;


int main()
{
    list<int> il1{ 1,2,3,4,5,7,8,9,11 };
    deque<int> evenQ;
    deque<int> oddQ;
    for (auto c : il1)
    {
        c % 2 ? oddQ.push_back(c) : evenQ.push_back(c);
    }
    for (auto c : oddQ)
    {
        cout << c << endl;
    }

    for (auto c : evenQ)
    {
        cout << c << endl;
    }
    return 0;
}

