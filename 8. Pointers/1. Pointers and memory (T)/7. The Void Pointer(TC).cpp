// The void* pointer
// Sometime you may want to store or pass to a function the memory address of a variable
// whose type you do not know then type void* is used.
// It is a generic pointer -> It can point to a variable of any type.
// void* pointer can be assigned to another void* pointer. 
// non-void* pointer can also be assigned to another void* pointer. 

/*
void *p1, *p2;
int i, j, *p3;
p1 = &i; // Assigning i's address to void p1
p1 = p3; // Assigning int pointer p3's address to void
p2 = p1; // Assigning void pointer to void pointer

Except for void*, in order to assign a pointer of one type to another type pointer, cast is necessary.
e.g.
char *p1;
int *p2;
p2 = (int*)p1;
It is better to avoid this, as the diff sizes of the data types, if for e.g. dereferencing occures, may
cause a serious problems. 
It is better to use cast operator in such case called reinterpret_case. 


To access a variable using a void* pointer, cast is necessary. 
e.g:
*/

#include <iostream>

int main()
{
    void *ptr;
    char s[] = "abcd";
    int i = 10;

    ptr = &i; // ptr -> 10
    
    // *ptr += 20; // Won't work use cast
    *(int*)ptr += 20;
    
    std::cout << i << '\n';

    ptr = s + 2; // 0 1 2 -> c
    (*(char*)ptr)++; // d

    std::cout << s << '\n'; // o/p -> abdd -> How? In chapter strings
    return 0;
}

// Note that any pointer can be cast to void* and back again to the original type without any loss of information.
// Typically, a void pointer is used as a function parameter in order to pass values of different types or 
// as a function’s return type (e.g., memcpy() as we’ll see in Chapter 14).