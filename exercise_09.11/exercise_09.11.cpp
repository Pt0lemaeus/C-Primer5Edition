// exercise_09.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b(10);
    vector<int> c(10, 1);
    vector<int> d{ 1,2 };
    vector<int> e = { 1,2 };
    vector<int> f(e);
    vector<int> g(e.begin(), e.end());
    return 0;
}

