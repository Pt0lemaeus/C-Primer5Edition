// exercise_16.04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include "template.h"

int main()
{
    vector<int> vi{ 10,20,30,40,50,60 };
    auto it = vi.begin();
    //vector<int>::value_type
    /*vector<int>::iterator*/auto it2 = findo(it, 20, vi);
    list<string> ls{ "ab","what","hello", "world" };
    auto it3 = ls.begin();
    auto it4 = findo(it3, "what", ls);
    auto it5 = findo(it3, "what1", ls);
    if(it5 == ls.end())
    {
        cout << "Yes, got it;" << endl;
}
    return 0;
}

