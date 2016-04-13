// exercise_08.06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sales_data.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "No file" << endl;;
        return - 1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open the file!" << endl;
        return -1;
    }
    Sales_data total;
    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
        {
            if (total.isbn() == trans.isbn())
                //add(total, trans);
                total.combine(trans);
            else
            {
                print(cout, trans) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}

