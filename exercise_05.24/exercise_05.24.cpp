// exercise_05.24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
 /*       try {*/
            if (b == 0)
            throw runtime_error("divisor must not be zero!");
            cout << a / b << endl;
        //}
        //catch (runtime_error err){
        //    cout << err.what()
        //        << "\nTry Again?";
        //        char c;
        //        cin >> c;
        //        if (!cin || c == 'n')
        //            break;
        //}

    }
    return 0;
}

