#pragma once
#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const Quote& rhs):bookNo(rhs.bookNo),price(rhs.price){ std::cout << "============== Quote Copy Construct ===============" << std::endl; }
    Quote(Quote&& rhs):bookNo(std::move(rhs.bookNo)),price(std::move(rhs.price)){ std::cout << "============== Quote Move Construct ===============" << std::endl; }
    Quote& operator=(const Quote &rhs) { bookNo = rhs.bookNo; price = rhs.price;  std::cout << "============== Quote Copy Assignment ===============" << std::endl; return *this; }
    Quote& operator=(Quote &&rhs) noexcept { bookNo = std::move(rhs.bookNo); price = std::move(rhs.price); std::cout << "============== Quote Move Assignment ===============" << std::endl; return *this; }

    Quote(const std::string &book, double sales_price):
        bookNo(book),price(sales_price){}
    std::string isbn()const { return bookNo; }
    virtual double net_price(std::size_t n) const
    {
        return n*price;
    }
    virtual ~Quote() { std::cout << "============== Quote Destructor ===============" << std::endl; }
    virtual void debug() const
    {
        std::cout << "bookNo: " << bookNo << std::endl;
        std::cout << "price: " << price << std::endl;
        std::cout << "=============================" << std::endl;
    }
    
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

