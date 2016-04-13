// exercise_10.42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    list<int> list1{ 1,3,5,7 };
    list<int> list2{ 2,4,6,8 };
    list1.merge(list2);
    for (auto c : list1)
    {
        cout << c << " ";
    };
    cout << endl;
    for (auto c : list2)
    {
        cout << c << " ";
    };
    cout << endl;
    return 0;
}

