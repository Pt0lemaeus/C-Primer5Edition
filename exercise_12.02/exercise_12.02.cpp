// exercise_12.02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
#include <initializer_list>
using std::initializer_list;
#include <string>
using std::string;
#include "StrBlob.h"

int main()
{
    StrBlob b2;
    {
        StrBlob b1( initializer_list<string>({"str1","str2","str3"}) );
        b2 = b1;
    }
  
    cout << b2.back() << endl;
    b2.pop_back();
    cout << b2.back() << endl;
    b2.push_back("str4");
    cout << b2.back() << endl;

    return 0;
}

