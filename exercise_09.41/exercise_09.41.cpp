// exercise_09.41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<char> vc{ ' ',' ',' ' };
    string s(vc.data(), vc.size());
    cout << s << endl;
    return 0;
}

