// exercise_08.01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

istream& procces_istream(istream&);
int main()
{
    //int i;
    //while(cin>>i)
    //{

    //    if (cin.good())
    //        cout << "good" << endl;
    //    cout << i << endl;
    //}

    //if (cin.eof())
    //    cout << "eof" << endl;
    //if (cin.fail())
    //    cout << "fail" << endl;
    //if (cin.bad())
    //    cout << "bad" << endl;
    procces_istream(cin);
    return 0;
}

istream & procces_istream(istream & is)
{
    int s;
    // TODO: insert return statement here
    while(!is.eof())
    {
        //if (is.fail()) 
        //{ cout << "fail" << endl; return is; }
        if (is.fail())
            is.clear();
        is >> s;
        cout << s;
    }
    is.clear();
    return is;
}
