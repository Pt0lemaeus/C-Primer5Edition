#include "stdafx.h"
#include "Account.h"


double Account::interestRate = initRate();

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::initRate()
{
    return 0.0;
}
