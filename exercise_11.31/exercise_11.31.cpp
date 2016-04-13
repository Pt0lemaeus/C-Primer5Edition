// exercise_11.31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
using std::multimap;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

int main()
{
    string s;
    multimap<string, string> bookstore{ { "Luo Guanzhong","Shuihu Zhuan" } ,{"Luo Guanzhong","Sanguo Yanyi"},{ "Guan Hanqing","Xi Xiangji" } ,{ "Guan Hanqing","Doue Yuan" },{"Cao Xueqin","Honglopuemeng"},{ "Wuchengen","Xi Youji" } };
    while (getline(cin, s))
    {
        auto n = bookstore.count(s);
            if (n > 0)
            {
                auto iter = bookstore.find(s);
                while (n > 0)
                {
                    iter = bookstore.erase(iter);
                    --n;
                }
            }
            else
                cout << "Opps! no author!" << endl;
    }
    
    for (const auto &w : bookstore)
    {
        cout << w.first << " " << w.second << endl;
    }
    

    return 0;
}

