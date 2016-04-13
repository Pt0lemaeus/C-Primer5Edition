// section_14.09.01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdexcept>

class SmallInt
{
public:
    SmallInt(int i = 0) :val(i)
    {
        if (i < 0 || i>255)
            throw std::out_of_range("Bad SmallInt value");
    }
    operator int() const { return val; }
private:
    std::size_t val;
};

int main()
{
    SmallInt si;
    si = 4;
    return 0;
}

