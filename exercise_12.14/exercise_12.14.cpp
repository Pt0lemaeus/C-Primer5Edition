// exercise_12.14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::shared_ptr;

#include <stdexcept>
using std::runtime_error;

struct destination{};
struct connection{};

connection connect(destination* pd)
{
    cout << "Open the connection!" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "Disconnect the connection!" << endl;
}

void end_connection(connection *p) { disconnect(*p); }

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    throw runtime_error("throw exception!");
}

int main()
{
    try {
        destination d;
        f(d);
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

