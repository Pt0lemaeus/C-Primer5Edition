// exercise_14.09.02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
//struct C{};
struct B{
   // operator C()const;

};
struct A {
    A(int = 0);
    //A(double);
    A(std::string);
    operator int() const;
    //operator double() const;
    operator const char*() const;
    operator B() const;
};

void f2(long double);
void f3(std::string);
void f4(B);
//void f5(C);
void f6(float);
void f7(char);
void f8(std::vector<int>);
int main()
{
    A a;
    std::vector<int> vi (10);
    f2(1);
    f8(vi);
   // f4(1);
    //f8(10);
    f7(a);
    f6(a);
    f2(a);
    std::string s(" ");
    f2(s);
    auto s1 = " ";
    B b;
    f4(b);
    f4(a);
   // f5(b);
//    f5(a);
  //  f3(a);
    return 0;
}

