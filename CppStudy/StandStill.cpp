#include "StandStill.h"

void LValueRValues()
{
	/*
	 * l-values have a name.
	 * r-values don't
	 * All variables are l-values
	 * r-values are literals.
	 * Functions can accept and return both.
	 *
	 * l-values persist beyond expressions.
	 * r-values don't persist beyond expressions.
	 *
	 * l-values can be referenced by references
	 * r-value can be referenced by const references
	 * const int& a = 10;(Allowed)
	 * int&a = 10;(Not allowed)
	 *
	 * [C++11 Feature]
	 * In C++11 you can use R-VALUE REFERENCES.
	 * They are defined by T&& var = r-value;
	 *
	 * int&& a = 10;
	 * 
	 * They are useful to detect r-values in function parameters.
	 *
	 * void Print(int& a)
	 *
	 * void Print(const int& a)
	 *
	 * void Print(int&& a)
	 *
	 * int i = 10
	 * Print(i); will invoke the normal constructor 
	 *
	 * Print(10); even though we have declared an "const int& a" function, "int&&" has preference because it's a r-value reference.
	 *
	 * r-value references are important to move semantics.
	 */
}

void CopyAndMoveSemantics()
{
	/*
	 * As has been told before, there are two types of copying:
	 * Deep Copying or Shallow Copying.
	 * Suppose Object01 have a pointer P1 that points to data D1 and we want to copy it to Object02 with P2.
	 * In Deep Copying we would assign D2, where D2 is a copy of D1, to P2.
	 * In Shallow Copy we would assign D1 to P2. This could lead to memory problems where deleting the data in P2 would make
	 * P1 points to unknown data.
	 * To avoid this we could use move semantics.
	 * In move semantics we would assign D1 to P2, then we would assign nullptr to P1, avoiding memory problems.
	 *
	 * This is faster then Deep Copying since we don't need to allocate new memory.
	 * This useful when handling temporary values for example in return statements from functions, instead of copying the temporary value we could
	 * only move this value to a new variable.
	 * 
	 * For this intention we can implement a Move Constructor.
	 * A Move constructor is defined as T(T&& obj);
	 *
	 * Integer(Integer&& obj);
	 *
	 * A Move operation could lead to exceptions when moving a data type inside a smaller size container.
	 * To tell the compiler our move constructor would throw exceptions we can add noexcept to it:
	 *
	 * Integer(Integer&& obj) noexcept;
	 *
	 * More on this here: http://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
	 */
}

void RuleOf5And0()
{
	/*
	 * The Rule of 05 is a guidelines on what types of constructors you should implement. It's a follow up to the Rule of 3.
	 * If a class has a ownership of pointers or data that can persists through it's scope we should implement a:
	 * Destructor
	 * Copy Constructor
	 * Copy assignment operator
	 * Move Constructor
	 * Move assignment operator
	 *
	 * This is to guarantee we are handling all the class resources properly and avoiding any memory leak or dandling pointer.
	 *
	 * In cases where a class has no ownership of pointers or data that can persists through it's scope there is no need to any of
	 * the previous constructors to allow the compiler to synthesize ones for us. We call this the Rule of 0.
	 * If your provide any custom implementation of the Copy Operations or Destructor all Move Operations will be deleted
	 * and needed to be implemented;
	 * If you provide any custom implementation of a Move operations all Copy Operations and the other Move Operations will be deleted.
	 *
	 * In case you need to implement any of those, but not all, remember to use default on the ones that have been deleted.
	 * This can be useful if you want to create a class where you can move it, but not copy, like in a unique pointer.
	 */
}

void CopyAndMoveElision()
{
	/*
	 * Copy Elision is a procedure adopted by many compilers to omit the call of a move or copy constructors.
	 * Most compilers apply this by default.
	 */
}

void stdmove()
{
	/*
	 * [C++11 FEATURE]
	 *
	 * the std::move is a standard library function to force the compiler to use move operations instead of copy operations.
	 * It is always used with L-Values.
	 * 
	 * Integer a(1);
	 * auto b{a};
	 *
	 * in this case, since a is an L-Value we'll be applying a Copy operation between a and b. If we want to make a move operation
	 * we could cast it to a R-Value reference:
	 *
	 * Integer a(1);
	 * auto b{static_cast<Integer&&>(a)};
	 *
	 * But this is not very clear, instead we can simples use std::move:
	 * 
	 * Integer a(1);
	 * auto b{std::move(a)};
	 *
	 * std::move performs the same cast as the example before.
	 *
	 * Remember this apply an move operation, so if move the value to a temporary value in a inner scope, the object will be destroyed when
	 * this inner scope is finished and can't be accessed outside.
	 *
	 * std::move is useful also for objects that can not be copied, but only moved.
	 *
	 * std::move in primitive type is redundant, the primitive type will still be copied.
	 */
}
