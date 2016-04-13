// exercise_09.27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    forward_list<int> flst = { 0, 1, 2,3,4,5,6,7,8,9 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
        if (*curr % 2)
        { 
            prev = curr;
            ++curr;
        }
        else
            curr = flst.erase_after(prev);

    for (auto c : flst)
    {
        cout << c << endl;
    }
    return 0;
}

