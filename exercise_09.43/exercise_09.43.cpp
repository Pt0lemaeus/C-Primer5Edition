// exercise_09.43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void replace_string(string&, const string&, const string&);

int main()
{
    //string s{ "Hello world!" };
    //auto iter = s.begin();
    //cout << *(iter) << endl;
    //string a{ "s"};

    ////s.s
    //do{
    //    s.insert(1, a);
    //    cout << s << endl;
    //    //cout << *(iter) << endl;
    //} while (iter == s.begin());
    string s{ "tho thru tho!" };
    replace_string(s, "thru", "through");
    cout << s << endl;

    replace_string(s, "tho", "though");
    cout << s << endl;

    replace_string(s, "through", "");
    cout << s << endl;

    return 0;
}

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    if (oldVal.size() == 0 /*|| newVal.size() == 0*/)
    {
        return;
    }

    auto oldValSize = oldVal.size();
    auto oldIterCur = oldVal.begin();
    auto newIter = newVal.begin();
    auto sIterPrev = s.begin();
    auto sIterCur = sIterPrev;
    while (sIterPrev <= s.end() - oldValSize)
    {
        oldIterCur = oldVal.begin();
        sIterCur = sIterPrev;
        while (oldIterCur != oldVal.end() && *oldIterCur == *sIterCur)
        {
            ++oldIterCur;
            ++sIterCur;
        }
        if (oldIterCur == oldVal.end())
        {
            sIterPrev = s.erase(sIterPrev, sIterCur);
            if (newVal.size())
            {
                sIterPrev = s.insert(sIterPrev, newVal.begin(), newVal.end());
                sIterPrev += newVal.size();
            }
        }
        else
            ++sIterPrev;
    }

}
