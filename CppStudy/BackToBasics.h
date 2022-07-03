#pragma once

void UniforInitialization();

void Pointers();

void Reference();

int ConstKeyword();

int LSum(int& a, int& b);

int RSum(const int& a, const int& b);

void AutoKeyword();

void FunctionOverload();

int Sum(int& a, int& b);

int Sum(const int& a, const int& b);

void DefaultFunctionArguments();

int MultiplyThreeNumbers(const int& a, const int& b = 8, const int& c = 5);

void InlineFunctions();

inline int InlineSum(int a, int b) { return a + b; }

void FunctionPointer();


