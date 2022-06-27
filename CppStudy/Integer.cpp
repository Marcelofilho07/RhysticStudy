#include "Integer.h"
#include <iostream>

Integer::Integer(): a(0)
{
}

void Integer::Print() const
{
    std::cout << a << std::endl;
}

int Integer::GetValue() const
{
    return a;
}

void Integer::NonConstPrint()
{
    std::cout << a << std::endl;
}
