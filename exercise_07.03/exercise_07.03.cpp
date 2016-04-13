// exercise_07.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sales_data.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Please type in data(ISBN,units_sold,saleprice,sellingprice):" << endl;
    Sales_data total;
    if(read(cin, total))
    { 
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
                add(total, trans);
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

