#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}


Person::~Person()
{
}

std::istream & read(std::istream &is, Person &per)
{
    // TODO: insert return statement here
    is >> per.name >> per.address;
    return is;
}

std::ostream & print(std::ostream &os, const Person &per)
{
    // TODO: insert return statement here
    os << per.name << per.address;
    return os;
}
