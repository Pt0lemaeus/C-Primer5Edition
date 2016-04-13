// section_08.01.03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int s;
    ostream * cin_tie =  cin.tie(&cout);
    ostream * old_tie = cin.tie(nullptr);
    cin.tie(&cerr);
    while (cin >> s)
    {
        cerr;
        cout << "cout in while" << s << endl;;
    }
    cin.tie(old_tie);

    return 0;
}

