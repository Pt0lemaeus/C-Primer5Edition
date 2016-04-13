// exercise_03.41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;
int main()
{
    int arr[] = { 1,2,3,5,8 };
    vector<int> vec(begin(arr), end(arr));
    for(auto v:vec)
    {
        cout << v << endl;
    }
    return 0;
}

