// exercise_09.26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
    vector <int> vi(ia, ia+11);
    list<int> li(ia, ia + 11);

    auto it = li.begin();
    while (it != li.end())
        if (*it % 2)
            it = li.erase(it);
        else
            ++it;

    auto it2 = vi.begin();
    while (it2 != vi.end())
        if (*it2 % 2)
            ++it2;
        else
            it2 = vi.erase(it2);


    for (auto c : vi)
    {
        cout << c << endl;
    }

    for (auto c : li)
    {
        cout << c << endl;
    }
    return 0;
}

