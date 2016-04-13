#include "stdafx.h"
#include <allocators>
using std::allocator;
#include <string>
using std::string;
#include <memory>
using std::uninitialized_copy;
using std::uninitialized_fill_n;
#include <utility>
using std::pair;
#include <algorithm>
using std::for_each;
#include "StrVec.h"

allocator<string> StrVec::alloc;
StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
    // TODO: insert return statement here
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}



void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t count)
{
    if (capacity() < count)
        reallocate(count);
}
//
void StrVec::resize(size_t newsize)
{
    size_t oldsize = size();
    if (newsize < size())
        pop_back_n(size() - newsize);
    else if (size() < newsize)
    {
        reserve(newsize);
        uninitialized_fill_n(first_free, newsize - oldsize, "");
    }

}

void StrVec::resize(size_t newsize, string &s)
{
    size_t oldsize = size();
    if (newsize < size())
        pop_back_n(size() - newsize);
    else if (size() < newsize)
    {
        reserve(newsize);
        uninitialized_fill_n(first_free, newsize - oldsize, s);
    }
}

pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);

    return{ data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    if(elements)
    {
        //for (auto p = first_free; p != elements; )
        //    alloc.destroy(--p);
        for_each(elements, first_free, [](std::string& p) {alloc.destroy(&p);});
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t count)
{

    auto newdata = alloc.allocate(count);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + count;
}

void StrVec::pop_back_n(size_t n)
{
    for (auto p = first_free; p != first_free - n; )
        alloc.destroy(--p);
    alloc.deallocate(first_free - n, cap - first_free + n);
    first_free = cap = first_free - n;
}