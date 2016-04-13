// exercise_14.44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using std::string;
#include <map>
using std::map;
#include<functional>
using std::function;
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) {return i % j;};
struct divide
{
    int operator()(int denominator, int divisor) 
    {
        return denominator / divisor;
    }
};

int main()
{
    map<string, function<int(int, int)>> binops = 
    {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) {return i*j;}},
        {"%",mod}
    };
    string input_operator;
    int a, b;
    while (cin >> a >> input_operator >> b)
    {
        cout << " = " << binops[input_operator](a, b) << endl;
    }
    return 0;
}

