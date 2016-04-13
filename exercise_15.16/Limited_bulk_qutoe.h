#pragma once
#include <cstddef>
#include <iostream>
#include "Disc_quote.h"
class Limited_bulk_qutoe :
    public Disc_quote
{
public:
    Limited_bulk_qutoe() = default;
    Limited_bulk_qutoe(const std::string& book, double p, std::size_t qty, double disc, std::size_t limit=10):
        Disc_quote(book,p,qty,disc),limit(limit){}
    double net_price(std::size_t) const override;
    void debug() const override
    {
        
        std::cout << "limit: " << limit << std::endl;
        Disc_quote::debug();
    }
private:
    std::size_t limit = 0;
};

