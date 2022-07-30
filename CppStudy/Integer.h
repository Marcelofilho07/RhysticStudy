#pragma once

class Integer
{
public:
    int value;

    Integer();

    Integer(int i);

    ~Integer();

    void Print() const;

    int GetValue() const;

    void NonConstPrint();
};
