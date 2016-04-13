// exercise_10.36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
using std::list;

#include <list>
using std::find;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    list<int> li{ 1,2, 3,4,5,6,7,6,0,5,4 };
    //auto iter = find(li.begin(), li.end(), 0);
    //cout << &iter << endl;
    auto iter1 = find(li.rbegin(), li.rend(), 6);
    cout << &iter1 << endl;

    auto l = (++iter1).base();

    int n = 1;
    for (auto iter2 = li.begin();iter2 != l; ++iter2)
    {
        ++n;
    }
    cout << n;
    return 0;
}

