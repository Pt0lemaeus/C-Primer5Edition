// exercise_13.31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::cout;
using std::endl;

// value-like implementation of HasPtr
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }

    // each HasPtr  has its own copy of the string to which ps points
    HasPtr(const HasPtr &p) :
        ps(new std::string(*p.ps)), i(p.i) { }

    HasPtr& operator=(HasPtr);
    HasPtr& operator=(HasPtr&&);
    bool operator <(HasPtr &rhs) { return i < rhs.i; }
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int    i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

using std::string;
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;    // return this object
}

HasPtr & HasPtr::operator=(HasPtr &&rhs) 
{
    // TODO: insert return statement here
    if (this != &rhs)
    {
        i = std::move(rhs.i);
        ps->clear();
        ps = rhs.ps;
        rhs.ps = nullptr;
    }

    


}

HasPtr f(HasPtr hp)  // HasPtr passed by value, so it is copied
{
    HasPtr ret;
    ret = hp; // copies the given HasPtr
              // process ret
    return ret;      // ret and hp are destroyed
}

int main()
{
    std::vector<HasPtr> nh = { HasPtr({ "Wang Yafu",20 }),HasPtr({ "Qian Ting",3 }),HasPtr({ "Jiao Wei", 4 }),HasPtr({ "Wu Di", 13 }),HasPtr({ "Zha Limin",21 }) };
    sort(nh.begin(), nh.end());
    HasPtr h("hi mom!");  // allocates a new copy of "hi mom!"
    f(h);  // copy constructor copies h in the call to f
           // that copy is destroyed when f exits
}  // h is destroyed on exit, which destroys its allocated memory

