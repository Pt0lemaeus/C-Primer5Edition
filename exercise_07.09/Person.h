#pragma once
#include <string>

class Person
{
public:
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    Person() = default;
    Person(const std::string &name, const std::string &add):name(name),address(add){}
    Person(std::istream &is) {is >> *this}
    ~Person();

public:
    std::string name;
    std::string address;
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);