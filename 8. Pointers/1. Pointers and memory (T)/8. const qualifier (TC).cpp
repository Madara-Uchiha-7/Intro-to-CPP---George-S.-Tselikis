// To prevent A pointer To change the value of variable it points to, We add the const Keyword Before its type. 
// However, it is allowed to point To some other variable of same type. 
// Note that the variable does not have to be const.

/*
int j, i = 10;
const int *ptr; // ptr is pointer to const int
ptr = &i; // Allowed
i = 30; // Okay, i is not const.
*ptr = 30; // Wrong, since it is const
ptr = &j;  // Allowed to point to another location.
*/

// To prevent the pointer to point to another variable, we add the const keyword before the variable name.
// Thus we create const pointer. 
// As with Ordinary const Variables, The pointer must be initialized when declared. 
// Now the in below code, the ptr is not allowed to point to address of j.

/*
int i, j;
int *const ptr = &i; // Initialize the pointer. ptr is const pointer to type int.
ptr = &j; // Wrong.
*ptr = 30; // Okay
*/
// Differences :->
// const int *ptr;  -> ptr can point to another variable after getting intialized to different variable.
// int *const ptr = &i; -> ptr must be initialized when declared and not ptr can not point to another variable.

// Does not allow to update the value to whom ptr points to but it is allowed to point to another variable.
// const int *ptr;

// Does allow to update the value to whom ptr points to but it is not allowed to point to another variable.
// int *const ptr = &i; -> Also must be initialized when declared.

// We can combine these both:
// const int* const ptr = &i; 
// ptr = &j; // Wrong.
// *ptr = 30; //Wrong.

/*
const char* const days[] = {"Mon", "Tue", "Wed"};
The outer const prevents the modification of the strings,
while inner const prevents the pointer to point to somewhere else.
*/

/*
const int i = 10;

// Not allowed because
// The address of const variable can only be stored in a pointer to const.
int *p = &i;  
*/