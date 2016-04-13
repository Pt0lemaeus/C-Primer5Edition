// exercise_10.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include "Sales_data.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    vector<Sales_data> sds;
    Sales_data sd;
    while (read(in, sd))
        sds.push_back(sd);

    sort(sds.begin(), sds.end(), [](Sales_data&a, Sales_data&b) {return a.isbn() < b.isbn();});

    for (const auto&s : sds)
    {
        print(cout, s) << endl;
    }
    return 0;
}

