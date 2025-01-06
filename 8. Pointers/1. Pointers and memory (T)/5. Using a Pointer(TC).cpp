// Basic imp :
// *ptr will hold the address
// ptr will be used to print the address
// &varName to get the address of the variable.
// To access the variable value using that variable's address:
// for eg. int a = 10; 
// int *ptr = &a;
// Now to access the value in a using ptr, we use * behind it
// So, cout << *ptr; will print the value in a.
// This is called dereferencing the pointer.
// * is used multiplication but using operator overloading we can understand which one to use.

// int a = 10; 
// int *ptr = &a;
// *ptr = 20; // Now a will have value 20
// Dereferencing the pointer which does not point to right address will mostly cause the segmentation fault.


// The * and & cancel out each other when used together.
// e.g. *&ptr will print the address which it holds.

// If you are using the pointer in division then add space or add ()
// e.g. a = b / (*ptr); otherwise /* will start the comment.

// sizeof(pointer); // pointer is not needed to be initialized to be used in sizeof
// sizeof will return the size in bytes.

// We can also use sizeof(*pointer); e.g:
// double *p;
// cout << sizeof(*p); 
// Here sizeof() does not need to derefence the pointer, it know that *p is of type double.

// One quick e.g.:
#include <iostream>

int main()
{
    int *ptr1, *ptr2;
    int i = 4, j = 1.78;

    ptr1 = &i;
    ptr2 = &j;

    *ptr1 = i + *ptr2; // 4 + 1.78 -> 5.78 -> Since *ptr1 (i.e. i) is int, the 5.78 becomes 5.

    std::cout << i;
}
