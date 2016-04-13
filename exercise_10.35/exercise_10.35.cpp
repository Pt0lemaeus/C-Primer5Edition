// exercise_10.34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> vi{ 1,2,3,4,5,6,7 };
    for (auto i = vi.cend(); i != vi.cbegin();)
    {
        cout << *(--i) << endl;
    }

    return 0;
}

