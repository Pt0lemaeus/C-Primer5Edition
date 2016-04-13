// exercise_11.16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
using std::map;

#include <iostream>
using std::cout;
using std::endl;


int main()
{
    map<int, int> imap{ {1,1},{2,2},{3,3} };
    for (auto iter = imap.begin();iter != imap.end(); ++iter)
    {
        iter->second = 0;
    }
    for (auto w : imap)
    {
        cout << w.first << " " << w.second << endl;
    }
    return 0;
}

