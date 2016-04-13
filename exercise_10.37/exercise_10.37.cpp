// exercise_10.37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iterator>
using std::inserter;
using std::ostream_iterator;

#include <algorithm>
using std::copy;

#include <iostream>
using std::cout;

int main()
{
    vector<int> vi{ 1,2,3,4,5,6,7,8,9,0 };
    list<int> li;
    ostream_iterator<int> oiter(cout, " ");
    vector<int>::reverse_iterator rend(vi.begin() + 2), rbeg(vi.begin() + 7);
    copy(rbeg, rend, inserter(li, li.begin()));
    copy(li.begin(), li.end(), oiter);
    return 0;
}

