// exercise_09.04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

using vitor = vector<int>::iterator;

bool find(vitor&, vitor&, int);

int main()
{
    return 0;
}

bool find(vitor &beg, vitor &end, int i)
{
    while (beg != end)
    {
        if (*beg == i)
            return true;
        ++beg;
    }
    return false;
}
