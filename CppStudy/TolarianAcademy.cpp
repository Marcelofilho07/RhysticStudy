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
    /*
     * A copy constructor of class T is a non-template constructor whose first parameter
     * is T&, const T&, volatile T&, or const volatile T&, and either there are
     * no other parameters, or the rest of the parameters all have default values.
     *
     * The copy of an object is created whenever an object is passed by value in a function,
     * when the function returns the object by value or when you manually create a copy of the variable:
     *
     * initialization: T a = b; or T a(b);, where b is of type T;
     * function argument passing: f(a);, where a is of type T and f is void f(T t);
     * function return: return a; inside a function such as T f(), where a is of type T, which has no move constructor.
     *
     * The compiler can implicit generate a copy constructor to us.
     *
     * This causes 
     * Whenever you're copying an object there are two possible copying outcomes, a shallow copy or a deep copy.
     *
     * Shallow Copy:
     * int* a = new int(10);
     * int* b = a;
     *
     * We're copying the pointer itself, not the value deep inside it. They both point to the same value in memory.
     *
     * Deep Copy:
     *
     * int* a = new int(10);
     * int* b = new int(*a);
     *
     * Now we're copying the value a points to a allocating new memory space for b.
     *
     * Rule of 3:
     *
     * you should define all if you implement any of then:
     * Destructor (free resources)
     * Copy Constructor (Deep Copy)
     * Copy Assignment (Deep Copy)
     * Not implementing this may lead to memory leaks or shallow copy.
     * 
     */
}

void DelegatingConstructors()
{
	/*
	 * [C++11 Feature]
	 *
	 * It's possible to delegate constructors others using the initialization list reuse code.
	 * Check the example below:
	 *
	 * Car()
	 * {
	 *		fuel = 0;
	 *		doors = 0;
	 * }
	 *
	 * Car(float amount)
	 * {
	 *		fuel = amount;
	 *		doors = 0;
	 * }
	 *
	 * Car(float amount, int doorsNum)
	 * {
	 *		fuel = amount;
	 *		doors = doorsNum;
	 * }
	 *
	 * Could be written as:
	 *
	 * Car(): Car(0)
	 * {
	 * 
	 * }
	 *
	 * Car(float amount): Car(amount, 0)
	 * {
	 * }
	 *
	 * Car(float amount, int doorsNum)
	 * {
	 * 		fuel = amount;
	 * 		doors = doorsNum;
	 * 	}
	 */
}

void DefaultAndDeleteKeywords()
{
	/*
	 * By default the compiler synthesize a constructor and destructor for us. But if you declare your own parametrized
	 * constructor, destructor or copy constructor the compiler won't synthesize a constructor. If you still want the compiler
	 * to synthesize a
	 * 
	 * CONSTRUCTOR
	 * DESTRUCTOR
	 * COPY CONSTRUCTOR
	 * ASSIGNMENT OPERATOR
	 *
	 * use must the default keyword:
	 *
	 * Integer() = default;
	 *
	 * ~Integer() = default;
	 *
	 * Integer(const Integer&) = default; (this isn't needed since the compiler will in most cases synthesize one for us,
	 * but there are some cases where this is needed and will see it later)
	 *
	 * The delete keyword would be the opposite of default. When you want the user to be blocked of using certain types of constructor
	 * you can use the delete keyword to block the compiler to synthesize this constructor.
	 *
	 * Integer(const Integer&) = delete; This will forbid the use of copy constructor;
	 *
	 * to forbid this object of being copied we can also delete the assignment operator;
	 *
	 * Integer operator=() = delete;
	 *
	 * delete can be used in any function, for example
	 *
	 * void SetValue(int a);
	 *
	 * void SetValue(float) = delete;
	 *
	 * the user now can't pass a float value to SetValue;
	 */
}




