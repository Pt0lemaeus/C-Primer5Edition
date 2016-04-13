// exercise_06.35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void PrintSomething(int i,int j)
{
    cout << i << endl;
    cout << j << endl;
}

int main()
{
    int i = 10;
    int j = 11;
    PrintSomething(--i,j--);
    return 0;
}

