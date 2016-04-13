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

String & String::operator=(String && rhs) noexcept
{
    // TODO: insert return statement here
    cout << "move assigment" << endl;
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

String::String(const char *c) :elements(nullptr), first_free(nullptr), cap(nullptr)
{
    cout << "copy char constructor" << endl;
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

std::ostream &print(std::ostream &os, const String &s)
{
    auto p = s.begin();
    while (p != s.end())
        os << *p++;
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free && lhs.cap == rhs.cap;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    //std::cout << s;
    //return os;

    auto p = s.begin();
    while (p != s.end())
        os << *p++;
    return os;

}
//std::ostream & String::operator<<(const String &s)
//{
//
//    // TODO: insert return statement here
//
//
//    return 
//}

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


