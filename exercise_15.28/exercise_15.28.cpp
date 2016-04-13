// exercise_15.28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <cstddef>
using std::size_t;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include "Quote.h"
#include "Bulk_quote.h"
//#include "Limited_bulk_qutoe.h"

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    item.debug();
    return ret;
}
int main()
{
    Quote basic("AAA-111", 1.00);
    //Quote test_cp(basic);
    //Quote test_cp2 = basic;
    //Quote test_cpas;
    //test_cpas = basic;
    //Quote test_move(std::move(test_cp));
    //Quote test_mvas = (std::move(test_cp2));
    //Quote test_mvas2;
    //test_mvas2 = std::move(test_cpas);
    //cout << "======================================================================" << endl;
    Bulk_quote bulk("AAA-112", 2.00, 8, 0.7);
    //Limited_bulk_qutoe limited_bulk("AAA-113", 3.00, 9, 0.8);
    //Bulk_quote test_cp_bk(bulk);
    //Bulk_quote test_cp2_bk = bulk;
    //Bulk_quote test_cpas_bk;
    //test_cpas_bk = bulk;
    //Bulk_quote test_move_bk(std::move(test_cp_bk));
    //Bulk_quote test_mvas_bk = (std::move(test_cp2_bk));
    //Bulk_quote test_mvas2_bk;
    //test_mvas2_bk = std::move(test_cpas_bk);
    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("AAA-111", 1.00));
    basket.push_back(make_shared<Bulk_quote>("AAA-112", 2.00, 8, 0.7));
    for (auto c : basket)
    {
        cout << c->net_price(20) <<endl;
    }

    vector<Quote> basket1;
    basket1.push_back(Quote("AAA-111", 1.00));
    basket1.push_back(Bulk_quote("AAA-112", 2.00, 8, 0.7));
    for (auto c : basket1)
    {
        cout << c.net_price(20) << endl;
    }

    // print_total(cout, limited_bulk, 20);
    return 0;
}

