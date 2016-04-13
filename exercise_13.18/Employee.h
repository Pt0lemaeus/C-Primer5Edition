#pragma once
#include <string>

static int ID = 0;
class Employee
{
public:
    Employee() :id(++ID),name(std::string()){}
    Employee(std::string &s):id(++ID),name(s){}
private:
    int id;
    std::string name;
};

