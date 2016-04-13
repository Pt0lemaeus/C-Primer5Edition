// exercise_09.38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector <int> v;
    while (v.size() < 100000)
    {
        v.push_back(42);
        cout << v.size() << " " << v.capacity() << endl;
    }

    return 0;
}

