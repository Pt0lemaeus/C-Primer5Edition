// exercise_12.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
using std::shared_ptr;

void process(shared_ptr<int> ptr)
{

}

int main()
{   
    auto p = new int();
    process(new int());
    return 0;
}

