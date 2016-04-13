#include "stdafx.h"
#include "Limited_bulk_qutoe.h"

double Limited_bulk_qutoe::net_price(std::size_t cnt) const
{
    if (cnt >= quantity)
    { if(cnt <= limit)
        return cnt*(1 - discount)* price;
    else
        return limit*(1 - discount)* price + (cnt -limit)*price;
    }

    else
        return cnt*price;
}
