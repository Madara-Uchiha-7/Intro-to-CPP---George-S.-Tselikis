// ptr = ptr + n;
// This increases the pointer's value by n*size of the pointer's data type. 
// This makes the pointer point to the address of Nth element after the one it points to.
// For example, if pointer points to the array element.  arr[i]
// and n is 3 then pointer will point to arr[i + 3]
// If pointer is declared as a pointer to an array of integer or float,
// then its value is increased by n*4, since the size of the both types is four bytes.
// If it is a character array, then its value is increased by n*1 = n,
// While it is a double array, It is increased by n*8.

// This allocation is valid if the pointer points to an element within the array or
// to the next place past the end.

#include <iostream>

int main()
{
    int *ptr, arr[] = {1, 2 ,3};

    ptr = &arr[0];

    *ptr = 10; // Makes arr[0] = 10

    // same can we do using subtraction.
    ptr = ptr + 2; // Points to arr[2]

    *ptr = 20; // Makes arr[2] = 20  
 
    return 0;
}
// This allocation is valid if the pointer points to an element within the array or
// to the next place past the end.
// EG:
// int arr[] = {10 , 20, 30};
// int *p1 = arr + 3; // Valid, the pointer points to the next place past the end.
// int *p3 = arr - 1; // not valid
// Make sure you do not dereference the address using p1 because it is out of bounds.
// For e.g. don't write *p1 = 2; This will make program behave unpredictabally.


// If pointer does not point to an array element, the use of ++ and -- 
// operators produce a valid result. For e.g.

// double *ptr, i;
// ptr = &i;
// std::cout << ptr++; // prints the address 8 places greater.
// std::cout << ptr--; // prints the address 8 places lower.

/*
As we’ll see in next examples, the ++ and -- operators are often combined with the * indirection operator to process array elements. 
The value of the expression depends on the operator precedence. Because these combinations are often used, 
I put them all together for quick reference. For example, 
let’s see the four combinations of * and ++; the same are for --. 
i = (*ptr)++; first the value of *ptr is assigned to i and then *ptr is increased by one.
i = *ptr++; first the value of *ptr is assigned to i and then ptr is increased according to its type.
i = ++*ptr; first the value of *ptr is increased by one and then this value is assigned to i.
i = *++ptr; first the value of ptr is increased according to its type and then the value of *ptr is assigned to i.
*/

/*
Subtracting and Comparing PointersThe result of pointer subtraction is valid only if both pointers point to 
elements of the same array or in the next place right after the end of the array. The result is the number of elements between them. 
If the value of the subtracted pointer is greater, the result would be the same with a negative sign. 
For example, if p1 points to the second element and p2 points to the fifth element of the same array, 
the result of p2–p1 is 3, while the result of p1–p2 is -3. The type of the result is ptrdiff_t, 
which is defined in the cstddef file as an alias of some signed integer type (e.g., int).
The result of comparing two pointers with the == and != operators is reliable. Using the relational operators =, 
the result is valid only if both point to members of the same object (e.g., structure) or 
to elements of the same array including the next place past the end, otherwise it is undefined. 
For example, the result of p2 > p1 is 1.
*/