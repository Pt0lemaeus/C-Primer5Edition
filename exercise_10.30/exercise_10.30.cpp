// exercise_10.30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
using std::front_inserter;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;
using std::sort;

bool less(int a, int b)
{
    return a < b;
}
int main()
{
    
    istream_iterator<int> it(cin), eof;
    vector<int> vi(it, eof);

    sort(vi.begin(), vi.end(), less);
    ostream_iterator<int> out(cout, " ");
    copy(vi.begin(), vi.end(), out);
    cout << endl;
    return 0;
}

