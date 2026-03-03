#pragma once
#include <iostream>

class test
{
public:
    test() : var1(3.0), var2(5) {}
    void printVar() { std::cout << "vars are " << var1 << " " << var2 << std::endl; }

private:
    double var1;
    int var2;
};