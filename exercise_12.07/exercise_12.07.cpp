// exercise_12.07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <new>
#include <memory>
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> factory()
{
    return make_shared<vector<int>>();
}

shared_ptr<vector<int>> readin(shared_ptr<vector<int>> vi)
{
    int i;
    while (cin >> i)
    {
        vi->push_back(i);
    }
    return vi;
}

void printout(shared_ptr<vector<int>> vi)
{
    for (auto iter = vi->cbegin(); iter != vi->cend();++iter)
    {
        cout << *iter << endl;
    }
}
int main()
{
    printout(readin(factory()));
    return 0;
}

