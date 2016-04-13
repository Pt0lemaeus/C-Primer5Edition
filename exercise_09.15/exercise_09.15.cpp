// exercise_09.15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{ 1,2,3,4,5 };
    cout << (v1 == v2) << endl;
    return 0;
}

