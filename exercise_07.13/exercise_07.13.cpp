// exercise_07.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sales_data.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Please type in data(ISBN,units_sold,saleprice,sellingprice):" << endl;
    Sales_data total(cin);
    if (cin)
    {
        Sales_data trans(cin);
        do
        {
            if (!cin)
                break;
            if (total.isbn() == trans.isbn())
                add(total, trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        } while (read(cin, trans));
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}

