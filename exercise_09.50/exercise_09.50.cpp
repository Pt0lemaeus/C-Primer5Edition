// exercise_09.50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> v{ "101","23.2fi","130o","4Eh",".9f","-.43","re" };
    for (auto s : v)
    {
        cout << stoi(s,0,2)<< endl;
    }
    return 0;
}

