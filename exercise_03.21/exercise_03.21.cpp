// exercise_03.21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{ 10 };
    vector<int> v5{ 10,42 };
    vector<string> v6{ 10 };
    vector<string> v7{ 10,"hi" };

    //v1
    if (v1.cbegin() != v1.cend())
    {
        cout << "v1 elments:";
            for (auto it = v1.cbegin(); it != v1.cend(); ++it)
            {
                cout << *it << " ";
            }
        cout << endl;
    }
    else
    {
        cout << "v1 have no elements!" << endl;
    }

    //v2
    if (v2.cbegin() != v2.cend())
    {
        cout << "v2 elments:";
        for (auto it = v2.cbegin(); it != v2.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "v2 have no elements!" << endl;
    }

    //v3
    if (v3.cbegin() != v3.cend())
    {
        cout << "v3 elments:";
        for (auto it = v3.cbegin(); it != v3.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "v3 have no elements!" << endl;
    }

    //v4
    if (v4.cbegin() != v4.cend())
    {
        cout << "v4 elments:";
        for (auto it = v4.cbegin(); it != v4.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "v4 have no elements!" << endl;
    }

    //v5
    if (v5.cbegin() != v5.cend())
    {
        cout << "v5 elments:";
        for (auto it = v5.cbegin(); it != v5.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "v5 have no elements!" << endl;
    }

    //v6
    if (v6.cbegin() != v6.cend())
    {
        cout << "v6 elments:";
        for (auto it = v6.cbegin(); it != v6.cend(); ++it)
        {
            if (it->empty())
            {
                cout << "(empty string) ";
            }
            else 
            {
                cout << *it << " ";
            }
            
        }
        cout << endl;
    }
    else
    {
        cout << "v6 have no elements!" << endl;
    }

    //v7
    if (v7.cbegin() != v7.cend())
    {
        cout << "v7 elments:";
        for (auto it = v7.cbegin(); it != v7.cend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "v7 have no elements!" << endl;
    }
    return 0;
}


//void printContainerElements()