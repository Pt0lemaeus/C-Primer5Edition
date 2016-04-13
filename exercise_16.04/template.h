#pragma once
//#include <algorithm>
template <typename T, typename U, typename V>
T findo(const T& t, const U& u, const V& v)
{
    T it = t;
    while (true)
    {
        if (it == v.end()||*it == u )
            break;
        else
            ++it;
    }
   return it;
}