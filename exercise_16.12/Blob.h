#pragma once
#include <vector>
#include <initializer_list>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>
        (const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(T &&t) { data->push_back(t); }
    // move version
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& front();
    T& back();
    T& at(size_type);
    T& operator[](size_type i);

    const T& front() const;
    const T& back() const;
    const T& at(size_type) const;
    const T& operator[](size_type i) const;

    void swap(Blob& b) { data.swap(b.data); }
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {};

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
    data(std::make_shared<std::vector<T>>(il)) {};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front(); 
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& at(size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& at(size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

// operator
template <T> 
std::ostream& 
operator<<(std::ostream& os, const Blob<T> a)
{
    os << "<";
        for (size_t i; i < a.size(); ++i)
        {
            os << a[i] << " "
        }
    os << ">";
    return os;
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    if (rhs.size() != lhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

template <typename T> class BlobPtr
{
public:
    BlobPtr(): curr(0){}
    BlobPtr(Blob<T> &a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    // increment and decrement
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr operator+(int);
    BlobPtr operator-(int);
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    // store a weak_ptr, whichmeans the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}