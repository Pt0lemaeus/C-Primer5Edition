// exercise_10.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int,10> si;
    fill_n(si.begin(), si.size(), 11);
    for(auto c:si)
    {
        cout << c << endl;
    }
    return 0;
}

