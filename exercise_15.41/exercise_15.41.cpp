// exercise_15.36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::cout;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include "Query.h"

int main(int argc, char* argv[])
{
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
    Query q = Query("firery") & Query("bird") | Query("");
    //std::cout << q.rep();
    print(cout, q.eval(in));
    //q.eval(in);
    return 0;
}

