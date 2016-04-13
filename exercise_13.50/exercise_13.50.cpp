// exercise_13.50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
#include <utility>
#include "String.h"

int main()
{
    String s = "abc";
    String s1 = std::move(s);
    //String s2;
    //s2 = s1;
    //cout << "vector define" << endl;
    std::vector<String> vS;
    //cout << "pushback" << endl;
    //cout << s << endl;
    //cout << s1 << endl;
    //cout << s2 << endl;
    //vS.push_back(std::move(s));
    vS.push_back("bc");
    //vS.push_back(s);
    //vS.push_back(s);
    //vS.push_back(s1);
    //vS.push_back(s);
    //vS.push_back(s2);
    //vS.push_back(s2);
    //vS.push_back(s2);
    //vS.push_back(s);
    //vS.push_back(s1);
    return 0;
}


