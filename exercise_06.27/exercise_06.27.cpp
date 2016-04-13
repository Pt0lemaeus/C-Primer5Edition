// exercise_06.27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int SumOfInitList(initializer_list<int> il)
{
    int sum{0};
    for (auto i : il)
        sum += i;
    return sum;
}
int main()
{
    initializer_list<int> il{1, 2 , 3};
    cout << SumOfInitList(il);
    return 0;
}

