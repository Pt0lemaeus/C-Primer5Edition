// exercise_03.01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Sales_item.h"
#include "Const_item.h"

using namespace std;

int main()
{
    int testExtern = conInt;
    cout << testExtern << " " << conInt << endl;
    //exercise 1.9
    int addNum = 50, addSum = 0;
    while (addNum <= 100)
    {
        addSum += addNum;
        ++addNum;
    }
    cout << "Sum the numbers from 50 to 100 equal " << addSum << endl;

    //exercise 1.10
    int printNum = 10;
    while (printNum >= 0)
    {
        cout << printNum <<" ";
        --printNum;
    }
    cout << endl;

    //exercise 1.11
    long long intRange1, intRange2;
    cout << "Please type two integers."
        << "The program will print ther range specified by those two integers ."
        << endl;
    cin >> intRange1 >> intRange2;
    if (intRange1 >= intRange2)
    {
        for (long long i = intRange1;intRange1 >= intRange2;intRange1--)
            cout << intRange1 << endl;
        //cout << endl;
    }
    else
    {
        for (long long i = intRange1;intRange1 <= intRange2;intRange1++)
            cout << intRange1 << endl;
        //cout << endl;
    }

    //exercise 2.41
    Sales_item saleItem01, saleItem02;
    cout << "Please type here two pieces of transaction: " << endl;
    cin >> saleItem01 >> saleItem02;
    Sales_item saleItemSum01 = saleItem01 + saleItem02;
    cout << saleItemSum01 << endl;

    Sales_item saleItem03, saleItemSum02, tempItem;
    cout << "Please type here some pieces of transaction: " << endl;
    while (cin >> saleItem03)
    {
        if(compareIsbn(saleItem03, saleItemSum02))
        { 
            saleItemSum02 += saleItem03;
        }
        else if (!saleItemSum02.isbn().empty())
        {
            cout << saleItemSum02 << endl;
            saleItemSum02 = saleItem03;
        }
        else
        {
            saleItemSum02 = saleItem03;
        }   
    }
    cout << saleItemSum02 << endl;
    return 0;
}

