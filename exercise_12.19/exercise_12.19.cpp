// exercise_12.19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <initializer_list>
using std::initializer_list;

#include <iostream>
using std::cout;
using std::endl;

#include "StrBlob.h"

int main()
{
    StrBlob b2;
    {
        StrBlob b1(initializer_list<string>({ "str1","str2","str3" }));
        b2 = b1;
    }
    StrBlobPtr wp1(b2);

    cout << wp1.deref() << endl;
    wp1.incr();
    cout << wp1.deref() << endl;
    wp1.incr();
    cout << wp1.deref() << endl;

    b2.pop_back();
    StrBlobPtr wp2(b2);
    cout << wp2.deref() << endl;
    wp1.incr();
    cout << wp2.deref() << endl;
    wp1.incr();
    cout << wp2.deref() << endl;
    b2.push_back("str4");
    cout << wp1.deref() << endl;
    wp1.incr();
    cout << wp1.deref() << endl;
    wp1.incr();
    cout << wp1.deref() << endl;
    return 0;
}

