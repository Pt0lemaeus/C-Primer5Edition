// exercise_04.25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = ~'q' << 6;

    cout << i << endl;
    cout << (i >> 8) << endl;
    cout << (~'q' << 6) << endl;;;
    cout << to_string(i) << endl;
   // cout << stoi("-7296", nullptr, 2) << endl;
    return 0;
}

