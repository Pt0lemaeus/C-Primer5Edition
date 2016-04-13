// exercise_08.09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "PersonInfo.h"

using namespace std;

istream& procces_istream(istream&);
int main(int argc, char *argv[])
{
    string line, word;
    if (argc != 2)
    {
        cerr << "No file" << endl;;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open the file!" << endl;
        return -1;
    }
    while (getline(in, line))
    {
        //PersonInfo info;
        istringstream record(line);
        procces_istream(record);
    }

    //procces_istream(cin);
    return 0;
}

istream & procces_istream(istream & is)
{
    string s;
    // TODO: insert return statement here
    //while (!is.eof())
    while(is>>s)
    {
        //if (is.fail()) 
        //{ cout << "fail" << endl; return is; }
        if (is.fail())
        {
            cout << "fail" << endl;
            is.clear();
        }
            
        //is >> s;
        cout << s << " ";
    }
    cout << endl;
    is.clear();
    return is;
}

