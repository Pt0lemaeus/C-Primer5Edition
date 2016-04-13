// exercise_14.35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Test
{
public:
    Test(std::istream &is = std::cin):is(is){}
    std::string operator()()
    { std::string line; 
    if (!std::getline(is, line))
    {
        line = "";
    }
    return line;
    }
private:
    std::istream &is;
};
int main()
{
    std::vector<std::string> vs;
    Test test;
    while (true)
    {
        std::string line = test();
        if (!line.empty())
        {
            vs.push_back(line);
        }
        else
            break;
    }
    return 0;
}

