#include "TolarianAcademy.h"

#include "Integer.h"

void ClassAndStruct()
{
    /*
     * A class in C++ is a user-defined type or data structure.
     * it's an expanded concept of data structures:
     * like data structures, they can contain data members, but they can also contain functions as members.
     * it is declared with keyword "class" or "struct"
     * the only difference between "class" and "struct" in C++ is that "class" have their member variable and functions as private by default and "struct" as public.
     * Structs are used to implement function objects.
     * programmers tend to use struct only for data structures data hold only variables and classes for more complex data structures with functions.(this is not a rule)
     *
     * class <name>
     * {
     * <modifiers>:
     *      <member variables>
     *      <member functions>
     * };
     *
     * example:
     *
     * class Car
     * {
     *      int Fuel;
     *
     * public:
     *      int Name;
     *
     * public:
     *      int getFuel();
     *      void setFuel(const int InFuel);
     * private:
     *      void consumeGas();
     * };
     *
     * in this example Fuel is a private member. If we change the keyword class to struct, fuel would be public.
     */

    Integer b;
    b.Print();
    
}

void Constructor()
{
    /*
     * A Constructor is a special function called whenever a new object is created.
     * It is used to initialize new objects.
     * Doesn't have any return type.
     * Can be overloaded.
     *
     * There are five types of constructors:
     * Default
     * Parameterized
     * Copy
     * Delegating
     * Inheriting
     *
     * Default:
     * doesn't accept any arguments.
     * automatically synthesized by the compiler only if NO OTHER USED-DEFINED CONSTRUCTOR EXISTS.
     *
     * Integer(); //Declaration
     *
     * Integer::Integer(): value(0) //Definition using initializer list
     * {
     * }
     * 
     * Integer::Integer() //We can also initialize our variables like this, but I prefer using the initializer list. More on that later.
     * {
     *      value = 0;
     * }
     *
     * Integer x; //Default constructor called;
     *
     * Parameterized:
     * it has one or more arguments.
     * NEVER synthesized by the compiler.
     * Blocks the automatic creation of Default constructor.
     *
     * Integer(int i) //Declaration
     *
     * Integer::Integer(int i): value(i)
     * {
     * }
     * 
     * Integer x(5); //Parameterized Constructor with one argument.
     */
}

void Destructor()
{
    /*
     * A Destructor is a special function called whenever an object is destroyed.
     * It is used for releasing resources that may have been allocated in the constructor.
     * It CAN'T be overloaded.
     * Has no arguments.
     * Compiler synthesizes one if none is given by the user.
     *
     * ~Integer(); //Declaration
     * ~Integer()  //Definition
     * {
     *      std::cout << "Integer has been destroyed" << std::endl;
     * }
     *
     * 
     */
}

void NonStaticDataMemberInitializer()
{
    /*
     * [C++11 Feature]
     * We can initialize member variables inside a class without a constructor to ensure our member variable are always initialized.
     * The compiler generates initialization code and insert it inside constructors.
     * User-defined initializers take precedence.
     * CAN NOT USE AUTO!
     * 
     * Example:
     * class ExampleClass
     * {
     *      int x{0};
     *      int y = 2;
     * }
     */
}

void ThisPointer()
{
    /*
     * this is a keyword.
     * it's a hidden pointer holding the address of the owner object.
     * Need to be used inside a non-static member function
     */
}

void StaticMemberVariables()
{
    /*
     * Member variables qualified with the static keyword are not bounded to class instances.
     * The name of any static data member and static member function must be different from the name of the containing class.
     * Static members of a class are not associated with the objects of the class:
     * they are independent variables with static or thread (since C++11) storage duration.
     * Static Storage duration: Its lifetime is the entire execution of the program and its stored value is initialized only once, prior to program startup.
     *
     * Must be initialized outside of the class.
     * 
     * class X
     * {
     *      static int number;
     * };
     * int X::number = 10;
     *
     * If you want to initialize inside class you can use "inline" [C++17 Feature]
     *
     * Class X
     * {
     *      inline static int number = 10;
     * };
     *
     * or you can use const
     *
     * Class X
     * {
     *      const static int number = 10;
     * };
     *
     * or use constexpr, but it need to be initialized with an initializer in which every expression is a constant expression, right inside the class definition [C++11 Feature]
     *
     * Class X
     * {
     *      constexpr static int number = 10; // OK
     *      constexpr static int arr[] = { 1, 2, 3 }; // OK
     *      constexpr static int number3; // Error: constexpr static requires an initializer
     * };
     * 
     */
}

void StaticMemberFunctions()
{
    /*
     * Similar to static member variables, but for functions
     * Can't access non-static member functions
     * Can be invoked directly through class name
     * They have no 'this' pointer
     * They can NOT be virtual, const, volatile.
     * The address of a static member function may be stored in a regular pointer to function, but not in a pointer to member function.
     *
     * Class X
     * {
     *      static void SayHello();
     * };
     *
     * X::SayHello()
     * {
     *      std::cout << "Hello World!" << std::endl;
     * }
     *
     * To invoke just call it from anywhere in the program:
     * X::SayHello();
     */
}

void CopyConstructor()
{
    //TODO: CONTINUE HERE!
}
