// exercise_10.29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::copy;

int main(int agrc, char* argv[])
{
    ifstream in(argv[1]);
    istream_iterator<string> it(in), eof;
    vector<string> vs(it, eof);

    ostream_iterator<string> out(cout, " ");
    copy(vs.begin(), vs.end(), out);
    cout << endl;
    return 0;
}

