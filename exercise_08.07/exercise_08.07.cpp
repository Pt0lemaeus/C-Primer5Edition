// exercise_08.07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sales_data.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "No file" << endl;;
        return -1;
    }
    ifstream in(argv[1]);
    ofstream out(argv[2],ofstream::app);
    if (!in)
    {
        cerr << "Can not open the input file!" << endl;
        return -1;
    }
    if (!out)
    {
        cerr << "Can not open the output file!" << endl;
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
                print(out, trans) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    in.close();
    out.close();
    return 0;
}

