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
