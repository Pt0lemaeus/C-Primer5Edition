// exercise_10.04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<double> vd{ 1.1,2.2,3.4,5.5 };
    cout << accumulate(vd.cbegin(), vd.cend(), 0) << endl;
    return 0;
}

