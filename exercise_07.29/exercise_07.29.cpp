// exercise_07.27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Screen.h"

int main()
{
    int a;
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
    return 0;
}


