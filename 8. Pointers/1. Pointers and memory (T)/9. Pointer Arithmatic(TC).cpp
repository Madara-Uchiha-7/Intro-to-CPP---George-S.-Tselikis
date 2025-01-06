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


