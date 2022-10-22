#include "CyclonicRift.h"

void OperatorOverload()
{
	/*
	 * Overloading an operator to have a custom implementation.
	 *
	 * For local overloading unary operators take no arguments, for global it takes one.
	 * For local overloading binary operator take one argument, for global it takes two.
	 *
	 * Whenever overloading local operator use "this" pointer to reference the other argument besides the one given in the declaration.
	 * Some examples below.
	 *
	 * Integer operator+(Integer a)
	 *
	 * Integer Integer::operator+(Integer a)
	 * {
	 *		Integer Temp;
	 *		*Temp.value = *this.value + *a.value;
	 *		return Temp;
	 * }
	 *
	 * Integer& operator++(); PRE INCREMENT
	 * 
	 * Integer Integer::operator++()
	 * {
	 *		++(*value);
	 *		return *this;
	 * }
	 *
	 * Integer operator++(int); POST INCREMENT, IT HAS AN ARGUMENT
	 * 
	 * Integer Integer::operator++(int)
	 * {
	 *		Integer Temp(*this);
	 *		++(*value);
	 *		return Temp;;
	 * }
	 *
	 * GLOBAL EXAMPLE:
	 *
	* 
	 *
	 * Integer operator+(Integer a, Integer b)
	 * {
	 *		Integer Temp;
	 *		*Temp.value = *b.value + *a.value;
	 *		return Temp;
	 * }
	 */
}

void TypeConversion()
{
	/*
	 * Performed by the compiler of by cast.
	 * The conversion can be between:
	 *
	 * Basic To Basic
	 * Basic To User-defined
	 * User-defined To Basic
	 * User-defined To User-defined
	 *
	 * Basic To Basic:
	 * We can use C-style cast like
	 * int a = 5;
	 *
	 * float f = float(a);
	 *
	 * but it's not recommended in C++ and we should avoid it.
	 * Instead we should use casting functions provided by C++ like:
	 * 
	 * static_cast<T>();
	 *
	 * float f = static_cast<float>(a);
	 *
	 * reinterpret_cast<T>();
	 *
	 * allows conversion between different types even if they are not related.
	 * It maintains the variable qualifiers.
	 *
	 * const_cast<T>();
	 *
	 * convert from a const type to a non-const type. Cast away the const.
	 *
	 * 
	 * Basic To User-defined:
	 *
	 * For this scenario, we should use parametrized constructors and assignment operators.
	 * When using the = operator, the compiler will look for parametrized constructors with the arguments.
	 *
	 * Integer a = 5; //Initialization using the constructor
	 *
	 * a = 6 //Assignment using the = operator and constructor
	 *
	 * So prefer Initialization over assignment.
	 *
	 * If we want to avoid this implicit conversion, we should use the qualifier "explicit" with our parametrized constructor.
	 *
	 *
	 * User-defined To Basic:
	 *
	 * Overload Type Conversion Operator to converse between those types.
	 *
	 * operator <Type>();
	 *
	 * operator <int>();
	 *
	 * Integer::operator <int>()
	 * {
	 *		return *valuePtr;
	 * }
	 *
	 * now we can converse from Integer to int
	 * Integer a = 5;
	 *
	 * int b = a;
	 *
	 * This may cause some confusion, to avoid this you can mark the operator with the explicit keyword to force the user to
	 * use static_cast<T>().
	 *
	 * 
	 * explicit operator <int>();
	 *
	 * Integer::operator <int>()
	 * {
	 *		return *valuePtr;
	 * }
	 *
	 * Integer a = 5;
	 *
	 * int b = static_cast<int>(a);
	 *
	 * User-defined to User-defined:
	 *
	 * same as User-defined to Basic, Overload Type Conversion Operator.
	 *
	 * operator <Type>();
	 *
	 * operator <Integer>();
	 * 
	 */
}