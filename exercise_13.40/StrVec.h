#pragma once
#include <string>
#include <allocators>
#include <utility>
#include <initializer_list>

class StrVec
{
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

