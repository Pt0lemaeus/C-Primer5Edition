#include "stdafx.h"
#include <memory>
using std::allocator;
using std::uninitialized_copy;
#include <utility>
using std::pair;
#include <iostream>
using std::cout;
using std::endl;

#include "String.h"

allocator<char> String::alloc;

String::String(const String &s)
{
    cout << "copy constructor" << endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(const char *c)
{
    auto p = c;
    while (*p != '\0')
    {
        push_back(*p);
        ++p;
    }


}

String & String::operator=(const String &s)
{
    cout << "copy assignment" << endl;
    // TODO: insert return statement here
    if (capacity() < s.size())
    {
        auto newcapacity = s.size();
        auto newdata = alloc.allocate(newcapacity);
        free();
        elements = first_free = newdata;
        cap = elements + newcapacity;
    }
    uninitialized_copy(s.begin(), s.end(), elements);
    first_free = elements + s.size();
    return *this;
}

std::ostream & String::operator<<(const String &)
{

    // TODO: insert return statement here
}

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);

    return{ data, uninitialized_copy(b, e, data) };
}

void String::push_back(const char c)
{
    chk_n_alloc();
    alloc.construct(first_free++, c);
}

void String::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void String::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, *elem++);
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}


