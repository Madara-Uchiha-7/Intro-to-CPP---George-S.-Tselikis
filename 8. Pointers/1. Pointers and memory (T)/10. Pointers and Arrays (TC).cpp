#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
/*
The elements in the array are stored in the successive memory locations.
The type of array defines the distance of its elements in memory.
E.g. In char array the distance will be 1 byte. While in int array the distance equals the size of int (e.g. 4 bytes).
The variable name of the array == pointer to the 1st element of the array.
So, arrayVariableName + 1 will point to the second element.
Below are same:
arr == &arr[0]     similarly *arr == arr[0] 
arr + 1 == &arr[1] similarly *(arr + 1)== arr[1] {For "(*arr + 1) Brackets are important becuase * has higher precedence than +}
arr + 2 == &arr[2] similarly *(arr + 2) == arr[2]
.
.
arr + n == &arr[n] similarly *(arr + n) == arr[n]
----------------------

If the name of the array is used as the pointer then C++ treats it as the constant i.e. const pointer.
So it is not allowed to change its value or make it point somewhere else.  -- Point 1.
----------------------

Array is not the pointer and vice versa.
int a[50] and int *a are quite different. 
int a[50]; -> Allocates memory for 50 integers.
int *a;    -> Allocates memory to store the value of the pointer (typically 4 bytes)
*/

int main()
{
    int *ptr, arr[5];

    // arr works as the pointer to the 1st element, do not use ptr = &arr;
    // because &arr is different. &arr expression evaluates to a pointer to the whole array, whereas,
    // others (check below cout) evaluate to a pointer to its first element.
    // &arr is like pointer to an array of 5 integers, while others are pointer to integer.
    ptr = arr; 

    // Lets print the address where the 1st element of the array will reside.
    cout << "Printing the 1st address of an array in differrent ways: " << endl;
    cout << ptr << " " << &arr[0] << " " << arr << " " << &arr << endl;

    cout << endl << endl;
    cout << "Printing array values in 3 different ways: " << endl;

    int i, arrOne[5] = {10, 20, 30, 40, 50};
    cout << "Using array notation: " << endl;
    for (i = 0; i < 5; i++)
        cout << &arrOne[i] << " : " << arrOne[i] << " ";  // Compiler converts arr[i] to *(arr + i) --> Point 2

    cout << endl << endl;
    cout << "Using name of the array as pointer notation: " << endl; // This approch is hard to read and prone to errors.
    for (i = 0; i < 5; i++)
        cout << arrOne + i << " : " << *(arrOne + i) << " "; 

    cout << endl << endl;
    cout << "Using pointer notation like the array notation: " << endl;
    int *ptrTest = arrOne;
    for (i = 0; i < 5; i++)
        cout << &ptrTest[i] << " : " << ptrTest[i] << " "; 
    /*
    Notice that although arrOne[i] and ptrTest[i] access the same element, 
    the compiler gets there in a different way. For example, to access arr[2], 
    it gets the address of arr, adds 8 (as said, we assume that the size of int is 4 bytes), and 
    goes to the resulting address to get the value. On the other hand, to access ptr[2], it gets the address of ptr, 
    retrieves the value that is stored there, adds 8, and goes to that address to get the value.
    */


    cout << endl << endl;
    cout << "Using another pointer variable to print the above array: " << endl;

    int *ptrOne;
    ptrOne = arrOne; // Points to the first element of the array.

    for (i = 0; i < 5; i++)
    {
        cout << ptrOne << " : " << *ptrOne << " "; 
        ptrOne++; // We can also write ptrOne = &arr[i];
    }

    // Point 1 Reference:
    // We can not do arr++ and arr = &i, like we did for ptrOne = arrOne;

    cout << endl << endl;
    // For more safety when processing an array through pointers, C++11 provides the begin() and end() functions. 
    // Both are declared in the iterator file. begin() returns a pointer to the first element of the array, 
    // while end() returns a pointer to the next place past the end. 
    // You will need to include the iterator library for this. For example: 
    cout << "Example for end() and begin(): Printing same array using these 2 functions." << endl;

    int *cur = std::begin(arrOne);
    int *fin = std::end(arrOne);

    while (cur != fin)
    {
        cout << *cur << " ";
        cur++;
    }
    // This begin and end will make sure that we do not access any memory address outside the allowed limits.
    cout << endl << endl;

    return 0;
}

/*
Point 2 reference:
Just remember that whenever the name of an array is used in an expression, 
the compiler converts it to a pointer to the address of its first element. Always? Not always, there are a few exceptions: 
1. When it is the operand of the sizeof operator. sizeof calculates the size of the entire array. 
Also, when it is the operand of decltype and typeid operators.
2. As discussed, when the & operator is applied to it. 
It is the array’s address that is retrieved.
3. When initialize a reference to an array. (We will see this in Chapter 16)
4. When array is a literal string initializer used in a declaration.
*/