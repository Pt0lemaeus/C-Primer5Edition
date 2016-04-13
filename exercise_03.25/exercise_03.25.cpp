// exercise_03.25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> scores(11,0);
    unsigned grade;
    auto begin = scores.begin();
    while (cin >> grade)
    {
        if (grade <= 100)
            ++*(begin + grade / 10);
    }
    for(auto i:scores)
    {
        cout << i << " ";
    }

    return 0;
}

