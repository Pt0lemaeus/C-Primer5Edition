// exercise_09.24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
   
    try {
        vector<int> v1;
        //v1.at(0);
        //v1.front();
        //v1[0];
        /*cout << **/v1.begin();
    }
    catch (out_of_range e)
    {
        cout << e.what();
    }
    return 0;
}

