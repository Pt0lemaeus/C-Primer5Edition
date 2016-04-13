#pragma once
#include <iostream>
#include <cstddef>
#include "Quote.h"
class Bulk_quote :
    public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
        Quote(book, p), min_qty(qty),discount(disc){}
    //Bulk_quote(const Bulk_quote& rhs):Quote(rhs),min_qty(rhs.min_qty),discount(rhs.discount){ std::cout << "============== Bulk_quote Copy Construct ===============" << std::endl; }
    //Bulk_quote(Bulk_quote&& rhs):Quote(std::move(rhs)),min_qty(std::move(rhs.min_qty)),discount(std::move(rhs.discount)){ std::cout<<"============== Bulk_quote Move Construct ===============" << std::endl; }
    //Bulk_quote& operator=(const Bulk_quote &rhs) { Quote::operator=(rhs); min_qty = rhs.min_qty; discount = rhs.discount; std::cout << "============== Bulk_quote Copy Assignment ===============" << std::endl; return *this;    }
    //Bulk_quote& operator=(Bulk_quote &&rhs)noexcept { Quote::operator=(std::move(rhs)); min_qty = std::move(rhs.min_qty); discount = std::move(rhs.discount);  std::cout << "============== Bulk_quote Move Assignment ===============" << std::endl; return *this;}
    double net_price(std::size_t) const override;
    //~Bulk_quote(){ std::cout << "============== Bukk_quote Destructor ===============" << std::endl; }
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};