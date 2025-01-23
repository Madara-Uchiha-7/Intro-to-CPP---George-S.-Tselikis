// Syntax e.g:
// int **p;
// This declares the pointer to another pointer that points to int.
// To use a pointer to a pointer variable, the single * provides access to the address 
// of the second pointer, while the double ** provides access to the content of the address 
// that the second pointer points to. For example:

#include <iostream>
int main()
{
    int *p, **pp, i = 20;

    p = &i;
    pp = &p;

    std::cout << **pp << std::endl; // Displays 20

    return 0;
}

// The most common use of a pointer to a pointer variable is when we want a function to change the value of an 
// argument which is pointer. We’ll discuss such examples in Chapter 11. In general, it is allowed to declare a 
// pointer to a pointer to another pointer variable and so on (e.g., int ***p;), but, in practice, it is rarely 
// needed to exceed a depth of two.

// One note :
// Assume m is an integer. p is array of pointers (int *p[] = {...}). 
// **(p + m + 1) is p[m + 1]
// How ? :-> Lets say m is 1 then 
// **(p + 2) -> This will make the address of p moved to location 2 i.e. *p[2]
// Now p[2] holds the address, now to get the value of address which p[2] points we used pointer 
// to pointer.

/// Note : To keep running the for loop, use for(;;){} 

