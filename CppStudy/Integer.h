#pragma once

class Integer
{
public:
    int value = 0;

    int* valuePtr = nullptr;

    Integer() = default;

    Integer(int i);

    ~Integer();

    Integer(const Integer& obj);
    
    Integer& operator=(const Integer& obj) noexcept;

    Integer(Integer&& obj) noexcept;

    Integer& operator=(Integer&& obj) noexcept;

    void Print() const;

    int GetValue() const;

    void NonConstPrint();

    void SetValue(int a);
    
    void SetValue(float) = delete;
};
