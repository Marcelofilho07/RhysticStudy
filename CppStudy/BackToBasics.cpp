#include "BackToBasics.h"
#include <string>
#include <iostream>
#include "Integer.h"

void UniforInitialization()
{
    /*
     * C++11 Feature. Uses {} to initialize all types
     * For object types there are 3 types of initialization
     * 1. Value initialization. T obj{}; Initialize to default value
     * 2. Direct initialization. T obj{v};
     * 3. Copy initialization T obj = v;
     */

    //int i1;
    int i2 = 0;
    int i3{}; //Value initialization.
    int i4{4}; //Direct Initialization.
    
    std::string str1;
    std::string str2 = "this is a string";
    std::string str3{"this is also a string"};

    //char c1[8];
    char c2[8] = {'0'};
    char c3[8]{"Hello"};
}

void Pointers()
{
    /*
     * Pointers are variables that holds a memory address.
     * We can declare using a type(T) or void and the * operator: T* ptr;
     * & operator is used to get the memory address value of a variable.
     * Since pointers hold an address we use & in a normal variable to give it address to a pointer variable
     * To access variables inside pointers we use the dereference operator *
     */
    
    int x = 10;
    int* ptr = &x;
    
    std::cout << "Pointer address: " << ptr << std::endl;
    std::cout << "Value inside pointer: " << *ptr << std::endl;

    *ptr = 5;
    
    std::cout << "Value inside pointer after reassign: " << *ptr << std::endl;
    
    /*
    * nullptr is a C++11 Macro to initialize pointer as a null value;
    * Will throw an exception if try to read or write(read/write access violation);
    */
    
    int* nullPointer = nullptr;
}

void Reference()
{
    /*
     * Reference type is an alias for a variable.
     * Defined using & operator during declaration.
     * Always need a initializer called Referent and it is (almost) always a lvalue(variable).
     * can be a rvalue if used with the const qualifier. More on that later.
     * It is not a new variable. It's an alias!
     * No storage required.
     * Must be initialized! Instead of pointers, won't compile if passing nullptr so it's better for safety!
     */

    //x and ref are now bounded. If I change the value in ref it also changes in x. The opposite is also true.
    int x = 10; //Referent
    int &ref = x; //Reference
}

int ConstKeyword()
{
    /*
     * Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class it prevents that specific object/method()/variable to modify its data items value
     * const variables MUST be initialized
     * useful for keeping your code safe and preventing other programmers to change values that should not be changed.
     * can be "changed" using const_cast<T>()
     */
    
    const int c1 = 10; // cInteger can not be changed afterwards.

    //Just some random examples.
    int x = 20;
    const int c2 = x;

    // For pointers there are 3 ways we can assign the const qualifier:

    //Here ptr1 points to a const-int type so we can't change it storage value, but we can change the pointer itself to point to a new memory address.
    int p1{1};
    const int* ptr1 = &p1;
    //*ptr1 = 2; not allowed since *ptr1 is supposed to be a const int type;
    ptr1 = &x;
    p1 = 2; //since p1 is a integer there is no problem in changing it value directly;
    
    //Here ptr1 points to a int type so we can change the value inside using the pointer dereference operator, but we can not change the pointer address value, because the pointer itself is const. 
    int p2{1};
    int* const ptr2 = &p2;
    //ptr2 = &x; not allowed since ptr2 is a const pointer;
    *ptr2 = 2;
    p2 = 3;

    //Here ptr1 points to a const-int type so we can't change it storage value and we also can't change the pointer address value, because the pointer itself is const.
    int p3{1};
    const int* const ptr3 = &p3;
    //ptr3 = &x; not allowed since ptr3 is a const pointer;
    //*ptr3 = 2; not allowed since *ptr3 is supposed to be a const int type;
    p3 = 4; // but as usual we can change the value directly without problem;

    /* For references we can use the const qualifier to pass a r-value(literals) to it instead of a l-value;
     * this is useful to pass rvalues to functions
     * as for examples a function LSum(int &a, int &b) would only accept lvalues;
     * but a function RSum(const int &a, const int &b) accept both.
     */
    const int& ref = 30;

    //int return1 = LSum(10, 30); not allowed since we're passing rvalues;
    int return1 = LSum(p1, p2); 
    int return2 = RSum(10, 30);


    /*
     * As for objects we can declare then the same way other as other types: const T obj
     * When declaring an object as const we can't change any of it's member variables and we can only access const member functions.
     * const member functions should be declared as: T MyFunction() const;
     */
    const Integer myObj;

    myObj.Print();
    //myObj.a = 10; not allowed to change any member variable.
    //myObj.NonConstPrint(); trying to access no const member function.
    
    return RSum(myObj.GetValue(), *ptr1);
}

int LSum(int& a, int& b) //Using pass by reference only accepts l-values
{
    return a + b;
}

int RSum(const int& a, const int& b) //Using pass by reference accepts l-values and r-values
{
    return a + b;
}
