// exercise_10.32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::find_if;
using std::copy;

#include <numeric>
using std::accumulate;

#include "Sales_item.h"

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    istream_iterator<Sales_item> iter(in), eof;
    vector<Sales_item> v_sales(iter, eof);

    sort(v_sales.begin(), v_sales.end(), compareIsbn);
    ostream_iterator<Sales_item> out(cout, "\n");
    copy(v_sales.cbegin(), v_sales.cend(), out);

    auto l = v_sales.begin();
    while (l != v_sales.end())
    {
        auto first_item = *l;
        auto r = find_if(l, v_sales.end(), [&first_item](const Sales_item &item) {return item.isbn() != first_item.isbn();});
        cout << accumulate(l+1, r, first_item)<< endl;
        l = r;
    }
    return 0;
}

