// exercise_09.52.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    stack<string> strStack;
    string s;
    while (getline(cin,s))
    {
        for (auto charactor : s)
        {
            if (charactor != '£©')
            {
                ch
                strStack.push(charactor);
            }
            else
            {
                string strOprator;
                double opa{ 0 };
                double opb{ 0 };
                ostringstream ostr;
                opa = stod(strStack.top());
                strStack.pop();
                strOprator = strStack.top();
                strStack.pop();
                opb = stod(strStack.top());
                strStack.pop();
                if (strOprator == "+")
                {
                    ostr << opa + opb;
                    strStack.push(ostr.str());
                }
                else if (strOprator == "-")
                {
                    ostr << opa - opb;
                    strStack.push(ostr.str());
                }
                else if (strOprator == "*")
                {
                    ostr << opa * opb;
                    strStack.push(ostr.str());
                }
                else if (strOprator == "/")
                {
                    ostr << opa / opb;
                    strStack.push(ostr.str());
                }

            }
        }

    }
        cout << "=" << strStack.top() << endl;
        strStack.pop();
    return 0;
}

