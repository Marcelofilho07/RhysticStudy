#include "MemoryDeluge.h"

#include <functional>
#include <iostream>
#include <ostream>
#include <cstring>

void NewAndDeleteOperator()
{
    /*
     * new operator is responsible for allocating memory on the heap.
     * delete operator is responsible for deallocating memory on the heap.
     * <type> *<variable> = new <type>(args);
     * delete <variable>;
     *
     * Size is asserted from the type
     * allocate and initialize memory
     * call constructors of type
     * returns a pointer
     * can be overloaded
     * throws exception on failure
     * after deleting the pointer, it might still hold empty data, so it's recommended to pass a nullptr value to it.
     * 
     * For Arrays we use new[] and delete[]
     * <type> *<variable> = new <type>[size];
     * delete[] <variable>;
     *
     * For strings(char array) always allocate one extra space for it to be null terminated
    */
    int* x = new int(10);

    int* p = new int[*x];
    for (int i = 0; i < *x; ++i)
    {
        p[i] = i;
    }

    delete x;
    x = nullptr;
    delete[] p;

    char* str = new char[4];
    strcpy_s(str, 4, "C++");
    std::cout << str << std::endl;
}

void Array2D()
{
    /*
     * 2D Arrays
     */
    int** p1 = new int*[2];
    
    for(int i = 0; i < 2; ++i)
    {
        p1[i] = new int[3];
    }
    
    for(int i = 0; i < 2; ++i)
    {
        delete[] p1[i];
    }
    
    delete[] p1;
}


void SmartPointers()
{
    /*
     * Smart Pointers are a special kind of pointers provided by C++ standard library to help avoiding memory leaks.
     * The Smart Pointers are objects with a lifetime that have a proper constructor and destructor to handle deletion.
     * There are 3 types of Smart Pointers.
     * Unique Pointers
     * Shared Pointers
     * Weak Pointers
     */
}

void UniquePointer()
{
    /*
     * Unique Pointers should be used whenever you don't want it resources to be shared.
     * IT HAS A UNIQUE OWNERSHIP!
     * It has all copy operators deleted and it's content can only be moved if necessary.
     *
     * std::unique_ptr<Integer> p(new Integer);
     *
     * [C++14 Feature]
     * or
     * 
     * std::unique_ptr<Integer> p = std::make_unique<Integer>();
     *
     * Passing the unique pointer to a function by reference is useful if you don't want to use the move function.
     * 
     */
}

void SharedPointer()
{
    /*
     * Shared pointers should be used whenever you want it resources to be shared.
     * It has a reference counter inside it that is added whenever a new reference/copy of it is created.
     * Whenever this reference counter reaches zero, it memory is released and it is destroyed.
     *
     * std::shared_ptr<Integer> p (new Integer);
     *
     * [C++14 Feature]
     * or
     *
     * std::shared_ptr<Integer> p = std::make_shared<Integer>();
     * 
     */
}

void WeakPointer()
{
    /*
     * Weak Pointers are a way to access Shared Pointers without changing the reference count.
     * A Weak Pointer need a Shared pointer. When a Weak Pointer is assigned to a Shared Pointer,
     * it will point towards its memory block and will visualize the reference count.
     * To access the Weak Point you need to check if reference count isn't 0 so we use "expired"
     *
     * std::shared_ptr<Integer> shr{new Integer()};
     *
     * std::weak_ptr<Integer> w = shr;
     *
     * if(!w.expired)
     * {
     *
     * After checking if the reference count isn't zero we can "lock" the weak pointer to return a shared_ptr<>,
     * then access it. This shared_ptr<> will add the reference count.
     *      auto wShr = w.lock;
     *      std::cout << *wShr;
     * }
     *
     * 
     */
}

void CircularReference()
{
    /*
     * When two classes reference each other via a shared_ptr it may cause a circular reference,
     * where the reference count never reach zero even when the pointers get out of scope.
     *
     * To avoid this we can simple use a weak_ptr in one or both of the classes.
     */
}

void Deleter()
{
    /*
     * We can create a custom deleter for smart pointers, this can be useful whenever handling with legacy code.
     * To do this create a class and overload the () operator.
     *
     * class NewDeleter
     * {
     * public:
     *      void operator()(int *p)
     *      {
     *          free(p);
     *      }
     * }
     *
     * std::unique_ptr<int, NewDeleter> p{(int*) malloc(4), NewDeleter{}};
     *
     * Since we're using malloc, we need to free the memory with "free".
     * Now, when the unique pointer call the destroyer it will call the object "NewDeleter"
     * and uses its overloaded operator ();
     *
     * you can also use directly a function:
     *
     * void NewMallocFree(int *p)
     * {
     *      free(p);
     * }
     *
     *
     * std::unique_ptr<int, void(*)(int*)> p{(int*) malloc(4), NewMallocFree}; //NewMallocFree is a global function, if it where a local function it would need an scope.
     *
     * but using objects deleter are preferable.
     *
     * for shared pointers, you don't have to specify the type of deleter
     * 
     * std::unique_ptr<int> p{(int*) malloc(4), NewDeleter{}};
     * 
     * std::unique_ptr<int> p{(int*) malloc(4), NewMallocFree};
     */
}

void DynamicArrays()
{
    /*
     * to use dynamic arrays with smart points use [] with the template type
     * 
     * std::unique_ptr<int[]> p(new int[5]{0,1,2,3,4});
     *
     * for shared ptr only C++17
     *
     * but we should avoid dynamic array and use some std container
     */
}



