// exercise_11.19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
using std::multiset;

#include <fstream>
using std::ifstream;

#include<iostream>
using std::cout;
using std::endl;

#include "Sales_data.h"

int main(int argc ,char*argv[])
{
    ifstream in(argv[1]);
    Sales_data sd;
    multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

    while (in >> sd)
    {
        bookstore.insert(sd);
    }
    typedef bool(*pf)(const Sales_data &, const Sales_data &);
    for (multiset<Sales_data, pf>::iterator iter = bookstore.begin(); iter != bookstore.end();++iter)
    {
        cout << iter->isbn() << " " << iter->avg_price() << endl;
    }
    return 0;
}

