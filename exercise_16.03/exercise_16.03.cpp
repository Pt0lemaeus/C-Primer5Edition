// exercise_16.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
#include "template.h"
#include "Sales_data.h"

int main()
{
    //cout << "compare(\"c1\", \"c22\") = " << compare("c1", "c22") << endl;
    //cout << "compare(\"c22\", \"c1\") = " << compare("c22", "c1") << endl;
    //cout << "compare(\"c2\", \"c1\") = " << compare("c2", "c1") << endl;
    //cout << "compare(\"c22\", \"c22\") = " << compare("c22", "c22") << endl;
    //cout << "compare(\"c1\", \"c2\") = " << compare("c1", "c2") << endl;
    Sales_data d1, d2;
    compare(d1, d2);
    return 0;
}

