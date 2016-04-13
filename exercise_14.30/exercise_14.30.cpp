// exercise_14.30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "StrBlob.h"

int main()
{
    StrBlob a1  { "hi", "bye", "now" };
    StrBlobPtr p(a1);
    *p = "okay";
    std::cout << p->size() << std::endl;
    return 0;
}

