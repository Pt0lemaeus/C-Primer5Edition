// exercise_12.20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;

#include "StrBlob.h"

int main(int argc, char* argv[])
{
    ifstream in(argv[1]);
    string line;
    StrBlob b;
    
    while (getline(in, line))
    {
        b.push_back(line);
    }

    //StrBlobPtr wp1(b);

    for (auto it = b.begin(); neq(it, b.end()); it.incr())
    {
        cout << it.deref() << endl;
    }

    return 0;
}

