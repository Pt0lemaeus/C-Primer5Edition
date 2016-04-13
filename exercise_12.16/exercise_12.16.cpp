// exercise_12.16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
using std::unique_ptr;

int main()
{
    unique_ptr<int> p1(new int(42));
    //unique_ptr<int> p2(p1);
    //auto p2 (p1);
    unique_ptr<int> p3=p1;
    return 0;
}

