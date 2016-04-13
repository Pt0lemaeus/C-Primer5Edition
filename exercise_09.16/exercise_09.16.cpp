// exercise_09.16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    list<int> v1{ 1, 2, 3, 4, 5 };
    vector<int> v2{ 1,2,3,4,5 };
    cout << (v1 == v2) << endl;
    return 0;
}

