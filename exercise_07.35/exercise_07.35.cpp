// exercise_07.35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

typedef double Money;
typedef std::string Type;
Type initVal() { Type n; return n; };
class Exercise
{
public: 
    typedef double Type;
    Type setVal(Type);
    Type initVal() { Type n = 0;  return n; };
private:
    typedef double Money;
    Money bal;
    int val;
};

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal();
    return val;
}
int main()
{
    return 0;
}

