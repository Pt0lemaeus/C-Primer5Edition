// exercise_14.37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>

class Equality
{
public:
    bool operator()(int a, int b) 
    {
        return a == b;
    }
};

int main()
{
    std::vector<int> vi;
    std::for_each(vi.begin(), vi.end(), Equality());
    return 0;
}

