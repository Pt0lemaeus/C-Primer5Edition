// exercise_09.31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    list<int> li = { 0,1,2,3,4,5,6,7,8,9 };
    auto iter = li.begin();
    while (iter != li.end())
    {
        if (*iter % 2)
        {
            iter = li.insert(iter, *iter);
            ++iter;++iter;
            //iter += 2;
        }
        else
        {
            iter = li.erase(iter);
        }
    }

    for (auto c : li)
    {
        cout << c << " ";
    }
    cout << endl;

    forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.insert_after(curr, *curr);
            prev = curr;
            ++curr;
            //iter += 2;
        }
        else
        {
            curr = flst.erase_after(prev);
        }
    }

    for (auto c : flst)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}

