#pragma once
#include <iostream>
#include "Quote.h"
class Bulk_quote :
    public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
        Quote(book, p), min_qty(qty),discount(disc){}
    double net_price(std::size_t) const override;
    void debug() const override
    {
        
        std::cout << "min_qty: " << min_qty << std::endl;
        std::cout << "discount: " << discount << std::endl;
        Quote::debug();
    }
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

