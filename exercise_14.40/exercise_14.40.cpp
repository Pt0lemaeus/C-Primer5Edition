// exercise_14.40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using std::string;

class Less
{
public: 
    bool operator()(const string &s1, const string &s2)const
    {
        return s1.size() < s2.size();
    }
};

class BigThan
{
public:
    BigThan(size_t n):sz(n){}
    bool operator()(const string &s)
    {
        return s.size() > sz;
    }
private:
    size_t sz;
};
int main()
{
    return 0;
}

