// exercise_07.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data sd;
    print(std::cout, sd) << std::endl;
    Sales_data sd1("111");
    print(std::cout, sd1) << std::endl;
    Sales_data sd2("222", 3, 3.3);
    print(std::cout, sd2) << std::endl;
    Sales_data sd3(std::cin);
    print(std::cout, sd3) << std::endl;
    return 0;
}

