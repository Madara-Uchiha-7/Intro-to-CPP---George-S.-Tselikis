// Pointer variable holds the memory address of another varibale.
// Syntax : data_type *pointer_name;
// pointer_name is pointer varibale

// int *ptr;
// Since ptr is pointer variable of type int, it can only hold the address of other int varibale.

// T is type and T* is 'pointer to T'.

// int *p, i; Here i is not the pointer varibale.

// int *p and int* p is same. But 1st approch is good. Helps to distingwish in noraml and 
// pointer variable like we did for int *p, i;

// Author prefers to write pointer variables first if any. e.g right -> int *p, i, j; wrong -> int j, *p, i;

// As with ordinary variables, when a pointer variable is declared, 
// the compiler allocates memory to store its value. A pointer variable allocates the same size, 
// no matter what is the data type it points to. This value is system dependent. 
// Typically, it is four or eight bytes (for 32-bit and 64-bit system architectures, respectively). 
// Therefore, either we write char *ptr; or float *ptr; or double *ptr; 
// the compiler allocates the same number of bytes for ptr (e.g., 4). 
// If you want to find out the size of a pointer variable in your system 
// use the sizeof operator (e.g., cout << sizeof(ptr)).