// exercise_10.21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
using std::cout;
using std::endl;

void mutable_lamabda(void)
{
    int i = 5;
    auto f = [i]()mutable->bool { if (i > 0) { --i;return false; } else return true; };
    for (int j = 0; j < 6; j++)
        cout << f() << " ";
    cout << endl;

}

int main()
{
    mutable_lamabda();
    return 0;
}

