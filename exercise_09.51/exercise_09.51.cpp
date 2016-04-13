// exercise_09.51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
const string month_list{ "JanFebMarAprMayJunJulAugSepOctNovDec" };

class My_date 
{
public:
    My_date(const string&);
private:
    unsigned year;
    unsigned month;
    unsigned day;
};

int main()
{
    try{
        My_date date1("January 1,1900");
        My_date date2("1/1/1900");
        My_date date3("Jan 1,1900");
        My_date date4("Dec 30, 201");
        My_date date5("1990/1/1");
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

My_date::My_date(const string &s)
{
    string::size_type p;
    if ((p = s.find_first_of("0123456789")) == string::npos)
        throw invalid_argument("no numeric, invalid date");
    if (p > 0)
    {
        month = month_list.find(s.substr(0, 3))/3 + 1;
        if (month > 12 || month < 1)
            throw invalid_argument("invalid month");
        day = stoi(s.substr(s.find_first_of("0123456789")));
        if (day > 31 || day < 1)
            throw invalid_argument("invalid day");
        year = stoi(s.substr(s.find_last_not_of("0123456789")+1));
    }
    else
    {
        month = stoi(s);
        if (month > 12 || month < 1)
            throw invalid_argument("invalid month");
        day = stoi(s.substr(s.find('/') + 1));
        if (day > 31 || day < 1)
            throw invalid_argument("invalid day");
        year = stoi(s.substr(s.rfind('/') + 1));
    }

    cout << "+==============+" << endl
        << "|THE INPUT DATE|" << endl
        << "+==============+" << endl
        << "|YEAR:     " << year << "|" << endl
        << "+--------------+" << endl
        << "|MONTH:       " << month << "|" << endl
        << "+--------------+" << endl
        << "|DAY:         " << day << "|" << endl
        << "+--------------+" << endl
        << endl;
}
