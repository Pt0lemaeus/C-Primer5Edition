// section_05.04.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };

    //for (auto beg = v.begin(), end = v.end(); beg != end; ++beg)
    //{
    //    auto &r = *beg;
    //    *beg *= 2;
    //    cout << r << ' ';
    //}
    for (auto r : v)
    {

    }
    return 0;
}

