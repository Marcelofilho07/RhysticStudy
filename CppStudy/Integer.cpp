#include "Integer.h"
#include <iostream>


Integer::Integer(int i): value(i), valuePtr(new int(i))
{
}

Integer::~Integer()
{
    delete valuePtr;
    valuePtr = nullptr;
    std::cout << "Integer has been destroyed" << std::endl;
}

Integer::Integer(const Integer& obj)
{
    valuePtr = new int(*obj.valuePtr);
}

Integer& Integer::operator=(const Integer& obj) noexcept
{
    if(this == &obj)
    {
        return *this;
    }
    
    delete valuePtr;
    valuePtr = new int(*obj.valuePtr);
    return *this;
}

Integer::Integer(Integer&& obj) noexcept
{
    valuePtr = obj.valuePtr;
    obj.valuePtr = nullptr;
}

Integer& Integer::operator=(Integer&& obj) noexcept
{
    if(this == &obj)
    {
        return *this;
    }

    delete valuePtr;
    valuePtr = obj.valuePtr;
    obj.valuePtr = nullptr;
    return *this;
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

void Integer::SetValue(int a)
{
    value = a;
}
