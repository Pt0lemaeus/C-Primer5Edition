#pragma once
#include <string>

static int ID = 0;
class Employee
{
public:
    Employee() :id(++ID),name(std::string()){}
    Employee(std::string &s):id(++ID),name(s){}
    Employee(const Employee &emp):id(++ID),name(emp.name){}
    Employee& operator= (const Employee &emp){ id = ++ID;name = emp.name; return *this}
private:
    int id;
    std::string name;
};

