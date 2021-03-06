#pragma once
#include <string>
#include <allocators>
#include <utility>

class StrVec
{
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec&);
    ~StrVec() {free();};
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, std::string&);
    void pop_back_n(size_t);
    std::string& operator[](std::size_t n)
    {
        return elements[n];
    }
    const std::string& operator[](std::size_t n) const
    {
        return elements[n];
    }
private:
    static std::allocator<std::string>alloc;
    void chk_n_alloc()
    {
        if (size() == capacity()) reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();
    void reallocate(size_t);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

bool operator==(const StrVec &lhs, const StrVec &rhs);