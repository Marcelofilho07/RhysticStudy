#include "Integer.h"
#include <iostream>

Integer::Integer(): value(0)
{
}

Integer::Integer(int i): value(i)
{
}

Integer::~Integer()
{
    std::cout << "Integer has been destroyed" << std::endl;
}

void Integer::Print() const
{
    std::cout << value << std::endl;
}

int Integer::GetValue() const
{
    return value;
}

void Integer::NonConstPrint()
{
    std::cout << value << std::endl;
}
