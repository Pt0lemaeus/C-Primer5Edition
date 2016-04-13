#pragma once
#include <memory>

#include <vector>

#include <string>

#include <memory>
//#include <initializer_list>

#include <stdexcept>
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob & lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob & lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    explicit StrBlob(std::initializer_list<std::string>il);
    size_type size() const { return data->size(); }
    bool empty()const { return data->empty(); }
    void push_back(const std::string &t) const { data->push_back(t); }
    void push_back(std::string &&t) { data->push_back(std::move(t)); }
    void pop_back() const;
    std::string& front() const;
    std::string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
    std::string& operator[](std::size_t n)
    {
        return (*data)[n];
    }
    const std::string& operator[](std::size_t n) const
    {
        return (*data)[n];
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg)const;
};

bool operator==(const StrBlob & lhs, const StrBlob &rhs);
bool operator!=(const StrBlob & lhs, const StrBlob &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data),curr(sz){}
    std::string& deref() const;
    std::string& deref(size_t n) const;
    StrBlobPtr& incr();
    std::string& operator[](std::size_t n)
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (n >= ret->size())
            throw std::out_of_range("n out of range");
        return (*ret)[n];
    }
    const std::string& operator[](std::size_t n) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (n >= ret->size())
            throw std::out_of_range("n out of range");
            return(*ret)[n];
    }
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+(int);
    StrBlobPtr& operator-(int);
    std::string& operator*()const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string* operator->()const
    {
        return &this->operator*();
    }

private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

StrBlobPtr & StrBlobPtr::operator++()
{
    // TODO: insert return statement here
    check(curr, "increment past end of the container, can't increment it");
    ++curr;
    return *this;
}

StrBlobPtr & StrBlobPtr::operator--()
{
    // TODO: insert return statement here
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+(int n)
{
    // TODO: insert return statement here
    for (int i = 0; i < n; ++i)
    {
        ++(*this);
    }
    return *this;
}

inline StrBlobPtr & StrBlobPtr::operator-(int n)
{
    // TODO: insert return statement here
    for (int i = 0; i < n; ++i)
    {
        --(*this);
    }
    return *this;
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr:: check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string& StrBlobPtr::deref(size_t n) const
{
    auto p = check(curr, "dereference past end");
    return (*p)[n];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
{
}

void StrBlob::pop_back() const
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string & StrBlob::front() const
{
    // TODO: insert return statement here
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string & StrBlob::back() const
{
    // TODO: insert return statement here
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(StrBlob::size_type i, const std::string & msg) const
{
    if (i > data->size())
        throw std::out_of_range(msg);
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

inline bool operator==(const StrBlob & lhs, const StrBlob & rhs)
{
    return lhs.data == rhs.data;
}

inline bool operator!=(const StrBlob & lhs, const StrBlob & rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    auto lb = lhs.data.get()->begin();
    auto le = lhs.data.get()->end();
    auto rb = rhs.data.get()->begin();
    auto re = rhs.data.get()->end();
    while (lb != le && rb != re)
    {
        if (*lb <*rb)
            return true;
        else if (*lb > *rb)
            return false;
        else
            ++lb, ++rb;
    }
}

inline bool eq(const StrBlobPtr  &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}