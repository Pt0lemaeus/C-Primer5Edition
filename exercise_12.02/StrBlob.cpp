#include "stdafx.h"
#include "StrBlob.h"
using std::string;
using std::make_shared;
using std::vector;
#include <initializer_list>
using std::initializer_list;
#include <stdexcept>
using std::out_of_range;

StrBlob::StrBlob():data(make_shared<vector<string>>())
{
}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>> (il))
{
}

void StrBlob::pop_back() const
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
 
string & StrBlob::front() const
{
    // TODO: insert return statement here
    check(0, "front on empty StrBlob");
    return data->front();
}

string & StrBlob::back() const
{
    // TODO: insert return statement here
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const string & msg) const
{
    if (i > data->size())
        throw out_of_range(msg);
}
