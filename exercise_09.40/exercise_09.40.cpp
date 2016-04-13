// exercise_09.40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include<string>
#include<vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])

{
    string s;
    ifstream in(argv[1]);
    vector<string> svec;
    svec.reserve(1024);
    int n{ 0 };
    cout << "At the begining, svec.size() is " << svec.size() << " and svec.capacity() is " << svec.capacity() << "."<< endl;
    while (getline(in,s))
    {
        svec.push_back(s);
        n++;      
    }
    cout << "After push back " << n << " times data, svec.size() is " << svec.size() << " and svec.capacity() is " << svec.capacity() << "." << endl;
    svec.resize(svec.size() + svec.size() / 2);
    cout << "After resize "<<n<<" times data, svec.size() is " << svec.size() << " and svec.capacity() is " << svec.capacity() << "." << endl;

    return 0;
}

