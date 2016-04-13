// exercise_15.07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <cstddef>
using std::size_t;
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_bulk_qutoe.h"

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main()
{
    Quote basic("AAA-111", 2.00);
    Bulk_quote bulk("AAA-112", 2.00, 9, 0.8);
    Limited_bulk_qutoe limited_bulk("AAA-113", 2.00, 9, 0.8);

    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    print_total(cout, limited_bulk, 20);
    return 0;
}

