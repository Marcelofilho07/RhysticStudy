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

