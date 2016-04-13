// exercise_12.26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <memory>
using std::unique_ptr;

#include <string>
using std::string;

#include <iterator>
using std::begin;
using std::end;

#include <allocators>
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_copy_n;
using std::uninitialized_fill_n;
unique_ptr<char[]> concate_string(const string &str1, const string &str2)
{
    unique_ptr<char[]> up(new char[str1.size() + str2.size()]);
    size_t i = 0;
    for (auto it = str1.begin(); it != str1.end();++it)
    {
        up[i] = *it;
        ++i;
    }

    for (auto it = str2.begin(); it != str2.end();++it)
    {
        up[i] = *it;
        ++i;
    }

    return up;
}
int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    allocator<char> alloc;
    auto const p = alloc.allocate(s1.size()+s2.size()+1);
    //auto beg1 = s1.begin(), end1 = s1.end(),beg2 = s2.begin(),end2 = s2.end();

    auto q = uninitialized_copy(s1.begin(), s1.end(), p);
    auto q2 =uninitialized_copy(s2.begin(), s2.end(), q);
    uninitialized_fill_n(q2, 1, 0);
    //unique_ptr<char[]> up(concate_string(s1, s2)), eof;
    //for (size_t i = 0;i != end;++i)
    //{
    //    cout << up[i];
    //}
    cout << p << endl;
    while (q2 != p)
        alloc.destroy(--q);
    alloc.deallocate(p, (s1.size() + s2.size() + 1));
    return 0;
}

