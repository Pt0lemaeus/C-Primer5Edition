// exercise_09.05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

using vitor = vector<int>::iterator;

bool find(vitor&, vitor&, int);

int main()
{
    vector<int> ilist = { 3, 2,3 ,4 ,5 };
    vitor beg = ilist.begin();
    vitor end = ilist.end();
    cout << find(beg, end, 2) << *beg <<endl;
    cout << *beg << endl;
    return 0;
}

bool find(vitor &beg, vitor &end, int i)
{
    while (beg != end)
    {
        if (*beg == i)
            return true;
        ++beg;
    }
    return false;
}


