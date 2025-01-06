// To find the address of any varibale use below syntax:
// pointer_variable_name = &variable;
// & is '& address operator'.

#include <iostream>
int main ()
{
    int *ptr, a;
    ptr = &a;
    std::cout << ptr << ' ' << &ptr << '\n';
    return 0;
}

// ptr points to the memory address of a
// Code outputs the address of a and ptr in hex.
// If type is T, then the type of &T is "Pointer to T"

// Assignment of integer value to pointer will cause compilation error.
// However, in applications that need direct access to hardware addresses (e.g., embedded systems), 
// type cast can be used to allow the assignment.
// ptr = reinterpret_cast<int*>(10000);

// int a, b, *ptr = &a; This is allowed because a is declared before the declaration of pointer variable.

// Author likes to declare pointer variable on the different line.

// & can not be applied to constants like &20 or *(a + b) and on bits fields.
// It can be applied on objects in memory such as variables, arrays, functions.
