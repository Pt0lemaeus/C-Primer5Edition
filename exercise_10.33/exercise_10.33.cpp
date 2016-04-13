// exercise_10.33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
using std::front_inserter;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cerr;
using std::endl;

#include <vector>
using std::vector;

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Open input file failed!" << endl;
    }

    ofstream out1(argv[2]);
    ofstream out2(argv[3]);
    if (!out1||!out2)
    {
        cerr << "Open output file failed!" << endl;
    }

    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> out_iter1(out1, " "), out_iter2(out2, "\n");

    vector<int> vi(in_iter, eof);
    //copy(vi.begin(), vi.end(), [&](int a) {return (a % 2) ? out_iter1 : out_iter2;});
    for (auto c : vi)
    {
        if (c % 2)
            out_iter1 = c;
        else
            out_iter2 = c;
    }
    return 0;
}

