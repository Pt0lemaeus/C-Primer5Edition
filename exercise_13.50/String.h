#pragma once
#include <memory>
#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream&, const String&);
    friend std::ostream &print(std::ostream&, const String&);
public:
    String():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const String&);
    String(String&& s) noexcept
        :elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elements = s.first_free = s.cap = nullptr;
        cout << "move constructor" << endl;
    }
    String &operator=(String &&rhs) noexcept;
    String(const char*);
    //String(std::initializer_list<char>);
    String &operator=(const String&);
    //std::ostream &operator<<(const String&);
    ~String() { free(); };
    void push_back(const char);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    //void reserve(size_t);
    //void resize(size_t);

private:
    static std::allocator<char> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity()) reallocate();
    }
    std::pair<char*, char*> alloc_n_copy
        (const char*, const char*);
    void free();
    void reallocate();
    //void reallocate(size_t);
    char *elements;
    char *first_free;
    char *cap;
};

