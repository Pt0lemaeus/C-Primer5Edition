// exercise_14.42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
    std::vector<int> vi = { 1,2222,333,23232,43445,343 };
    //std::greater<int> Great;
    auto n = std::count_if(vi.begin(), vi.end(), std::bind2nd(std::greater<int>(),1024));
    std::transform(vi.begin(), vi.end(), vi.begin(), std::bind2nd(std::multiplies<int>(), 2));

    std::vector<std::string> vs = { "as", "ss", "es", "wsss" };
    auto s = std::find_if(vs.begin(), vs.end(), std::bind2nd(std::equal_to<std::string>(), "pooh"));
    return 0;
}

