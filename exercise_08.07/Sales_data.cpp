#include "stdafx.h"
#include "Sales_data.h"

Sales_data & Sales_data::combine(const Sales_data &rhs)
{
    // TODO: insert return statement here
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
        discount = saleprice / sellingprice;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::ostream & print(std::ostream &os, const Sales_data &item)
{
    // TODO: insert return statement here
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

std::istream & read(std::istream &is, Sales_data &item)
{
    // TODO: insert return statement here
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
