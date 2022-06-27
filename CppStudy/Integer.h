#pragma once

class Integer
{
public:
    int a;

    Integer();

    void Print() const;

    int GetValue() const;

    void NonConstPrint();
};
