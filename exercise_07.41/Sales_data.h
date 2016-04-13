#pragma once
#include <string>
#include <iostream>

class Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
class Sales_data
{
public:
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {std::cout << "3-arg construtor!" << std::endl;}
    Sales_data() :Sales_data("", 0, 0) { std::cout << "default construtor delegat 3-arg construtor!" << std::endl; };
    explicit Sales_data(const std::string &s) :Sales_data(s, 0, 0) { std::cout << "string construtor delegat 3-arg construtor!" << std::endl; }

    explicit Sales_data(std::istream &is) :Sales_data()
    {
        std::cout << "cin construtor delegat default construtor!" << std::endl;
        read(is, *this);
    };

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
public:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
    double revenue = 0.0;
};

