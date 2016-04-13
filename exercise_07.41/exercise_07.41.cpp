// exercise_07.41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Sales_data.h"

int main()
{
    std::cout << "3 arg" << std::endl;
    Sales_data sd("111", 2, 2);
    print(std::cout, sd) << std::endl;

    std::cout << "default" << std::endl;
    Sales_data sd1;
    print(std::cout, sd1) << std::endl;

    std::cout << "string" << std::endl;
    Sales_data sd2("222");
    std::string null_book = "999";
    sd2.combine(static_cast<Sales_data>(null_book));
    //sd2.combine("222");
    sd2.combine(Sales_data(std::cin));
    print(std::cout, sd2) << std::endl;

    std::cout << "cin" << std::endl;
    Sales_data sd3(std::cin);
    print(std::cout, sd3) << std::endl;
    //Sales_data sd;
    //print(std::cout, sd) << std::endl;
    //Sales_data sd1("111");
    //print(std::cout, sd1) << std::endl;
    //Sales_data sd2("222", 3, 3.3);
    //print(std::cout, sd2) << std::endl;
    //Sales_data sd3(std::cin);
    //print(std::cout, sd3) << std::endl;
    return 0;
}

