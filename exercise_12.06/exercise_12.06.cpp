// exercise_12.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <new>

vector<int>* factory()
{
    return new vector<int>;
}

vector<int>* readin(vector<int>* vi)
{
    int i;
    while (cin >> i)
    {
        vi->push_back(i);
    }
    return vi;
}

void printout(vector<int>* vi)
{
    for (auto iter = vi->cbegin(); iter != vi->cend();++iter)
    {
        cout << *iter << endl;
    }
    delete vi;
}
int main()
{
    printout(readin(factory()));
    return 0;
}

