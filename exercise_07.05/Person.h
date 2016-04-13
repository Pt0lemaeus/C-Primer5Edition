#pragma once
#include <string>

class Person
{
public:
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    Person();
    ~Person();

private:
    std::string name;
    std::string address;
};

