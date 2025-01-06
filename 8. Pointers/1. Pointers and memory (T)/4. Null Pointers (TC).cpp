// Pointer initially points to the garbage address.
// If you want to show that pointer points nowhere then assign 0 to it.
// Some prefer to use Macro NULL. (This macro NULL is defined in some headers e.g. cstdlib)
// NULL value is also the integer value
// NULL is prefered instead of 0 
// because reader may get confuse and think that pointer variable is integer variable.
// Poiner with 0  or NULL is called Null Pointer.
// Value of pointer variable can be compared with NULL
// if (p != NULL) : same as if(p)
// if (p == NULL) : same as if(!p)


// Its good to use NULL instead of 0.
// There is nullptr constant which is more better to use and which can only be assigned to the pointers.
// e.g. double *p = nullptr;
