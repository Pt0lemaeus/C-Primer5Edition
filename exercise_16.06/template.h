#pragma once
template<typename T, unsigned N>
const T* begina( const T(&p)[N])
{
    //T* p1 = p;
    return &p[0];
}

template<typename T, unsigned N>
const T* enda( const T(&p)[N])
{
    //T* p1 = p;
    return &p[0] + N;
}