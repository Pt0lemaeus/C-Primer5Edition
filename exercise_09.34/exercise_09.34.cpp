// exercise_09.34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{ 1,2,3,4,5 };

    auto iter = v.begin();

    while (iter != v.end())
    {
       if(*iter%2)
       iter =  v.insert(iter, *iter);
        ++iter;
    }

    for (auto c : v)
    {
        cout << c << endl;
    }
    return 0;
}
