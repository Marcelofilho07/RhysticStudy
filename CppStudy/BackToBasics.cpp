#include "BackToBasics.h"
#include <string>
#include <iostream>
#include <map>

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
     * Once a reference is created, it cannot be later made to reference another object; it cannot be reseated. This is often done with pointers.
     */

    //x and ref are now bounded. If I change the value in ref it also changes in x. The opposite is also true.
    int x = 10; //Referent
    int &ref = x; //Reference

    /*
     * Under the hood, in most compilers, references have the same implementation as a pointer, but the compiler treat then differently.
     * Applying all needed protection whenever you're using a reference.
     * a previously-valid reference only becomes invalid in two cases:
     * 
     * If it refers to an object with automatic allocation which goes out of scope,
     * If it refers to an object inside a block of dynamic memory which has been freed.
     * 
     * The first is easy to detect automatically if the reference has static scoping, but is still a problem if the reference is a member of a dynamically allocated object;
     * the second is more difficult to detect. These are the only concerns with references, and are suitably addressed by a reasonable allocation policy.
     */
}

int ConstKeyword()
{
    /*
     * Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class it prevents that specific object/method()/variable to modify its data items value
     * const variables MUST be initialized
     * useful for keeping your code safe and preventing other programmers to change values that should not be changed.
     * can be "changed" using const_cast<T>()(more on that later)
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

    /*
     * For references, const makes the alias readonly,
     * but you can still change the original variable value;
     */
    const int& ref2 = x;
    x += 10; // allowed since x isn't const;
    //ref2 += 20; not allowed since ref2 is const type
    
    /*
     * [IMPORTANT]
     * Also, we can use the const qualifier to pass a r-value(literals) to it instead of a l-value;
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

void AutoKeyword()
{
    /*
     * In C++11 allows the compiler to infer the data type from the initializer
     * Needs an initializer!
     * Initializing an auto from a const value doesn't makes the auto variable const. It needs to be declared as const.
     * If it is a reference or a pointer for a const value it will hold its constness!
     * But auto will never deduce &(reference)
     * Auto will never perform a conversion, eliminating any accidental conversion! (Great for range based for loops!)
     */

    auto x = 10; //x is a int;

    auto i = Integer{}; // i is an object of type I

	i.SetValue(10);
	//i.SetValue(10.f); deleted function
    auto sum = RSum(x, 2); //

    const int p = 10;
    auto pen1 = p; // a copy! So no constness deduced!
    const auto pen2 = p;
    auto& penRef = p;
    pen1 = 2; //Allowed
    //pen2 = 3; //Cannot assign to readonly type 'const int'
    //penRef = 4; //Cannot assign to readonly type 'const int'
    
    int& funRef = x;

    auto isItaRef = x; //this is a copy

    auto pointer = &x; //a pointer to an int. No Need for *

    auto* pointer2 = &x; // but if * used, the initializer need to be a pointer!

    
    const std::map<std::string, std::string> a;
    
    for(const auto& ele : a)
    {
        /* This is the same as const std::pair<const std::string, std::string>&
         * Usually people may forget the const keyword in the first pair parameter,
         * this will perform a conversion causing more lines of code.
         * So preferring auto in for loops can assure you don't have any accidental conversions.
         * Also remember to use & and const since, & are never deduced and constness will only be deduced from reference or pointers! 
         */
    }
    
    /* In C++20, auto uses the same exact rules as template type parameters
     * So both declaration below are the same.
     * template <typename T> void FunFunction(T param);
     * void FunFunction(auto param);
     */
}

void FunctionOverload()
{
    /* Allows us to create functions with same name, but with different parameters.
     *
     * void func(int x);
     *
     * void func(float x);
     * 
     * For pointers and & qualifiers, as const, participate in overload
     *
     * void func(int& x) this accepts a l-value reference
     * and
     * void func(const int& x)  this accepts a r-value reference
     * are overloaded
     *
     * void func(int* x) this accepts a pointer of type int
     * and
     * void func(const int* x) this accepts a pointer of type const int
     * are overloaded
     * 
     * Return type is ignored!
     * For member functions, qualifiers participate in overload! You can use const to overload functions in this case!
     *
     * The correct implementation is chosen based on the arguments!
     * This is done in compile-time through
     *
     * NAME MANGLING!
     * 
     * Name Mangling generates an unique name for each overload function allowing the linker to link the call with the correct function.
     * for example, our func have 2 different names inside the link map. The first might be func#i and the last func#f.
     *
     */

    int x = 10;
    int y = 15;
    const int z = 20;
    Sum(x, y); // int& a, int& b
    Sum(x, z); // const int& a, const int& b
    Sum(x, 5); // const int& a, const int& b
    Sum(2, 5); // const int& a, const int& b
}

int Sum(int& a, int& b) //Using pass by reference only accepts l-values
{
    std::cout << "int& a, int& b" << std::endl;
    return a + b;
}

int Sum(const int& a, const int& b) //Using pass by reference accepts l-values and r-values
{
    std::cout << "const int& a, const int& b" << std::endl;
    return a + b;
}

void DefaultFunctionArguments()
{
    /*
     * Allows some of all function arguments to have a default value if none is given.
     * Default values must be declared starting from the left.
     * int MultiplyThreeNumbers(const int& a, const int& b = 8, const int& c = 5);
     * here b and c have a default value of 8 and 5;
     * so we can call the function without declaring all parameters as shown in the example below
     */

    std::cout << MultiplyThreeNumbers(3,3,3) << std::endl;
    std::cout << MultiplyThreeNumbers(3,3) << std::endl;
    std::cout << MultiplyThreeNumbers(3) << std::endl;
}

int MultiplyThreeNumbers(const int& a, const int& b, const int& c)
{
    /*
     * this definition doesn't have the default values since it would be a "Redefinition of default argument"
     * we can also declare those default values here instead in the header file declaration,
     * but we would need to place this definition before the function above, since it would be looking for the original
     * declaration without the default values.
     */
    
    return a * b * c;
}

void InlineFunctions()
{
    /*
     * We can use the inline keyword to request the compiler to replace the function call with the body of the function!
     *
     * No need for stack memory for arguments
     * No need to save the return address of the function
     * 
     * Mark functions in the definition of the function in the header file.
     * Remember, this is requesting the compiler, we are not forcing it to avoid the function call. The final decision is up
     * to the compiler!
     *
     * Reasons the compiler might not accept your inline request:
     *  - large function
     *  - too many conditional statements
     *  - recursive function
     *  - function invoked through pointers
     *
     *
     *  Many optimizers already inline functions without the need of using this keyword.
     *  Use inline when you have a header file with multiple translations unity to avoid linking errors TODO: check this!
     */

    std::cout << InlineSum(2, 3) << std::endl;
}

void FunctionPointer()
{
    /*
     * A pointer that holds the address of a function
     * The signature of the pointers is the same as the function.
     * Can be used to invoke functions even without knowing their name.
     * Very useful for observer patterns, subscribing a list of functions to a event.
     *
     * <returnType> (*ptrName)(args) = &func
     * int (*ptrAdd)(int,int) = &Add
     */

    int (*ptrSum)(const int&, const int&) = Sum; //The & is optional!

    // We can invoke the function those two ways.
    
    std::cout << (*ptrSum)(3, 4) << std::endl;
    std::cout << ptrSum(5,10) << std::endl;
}


