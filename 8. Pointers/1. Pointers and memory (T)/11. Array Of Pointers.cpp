///
/// An array of pointers is an array whose elements are pointer to the same data type.
/// Syntax:
/// Add * before its name: E.g.:
/// int *p[3]; // This is the declaration of2 pointers to integers.
/// The elements of array of pointers are treated as the ordinary pointer.
///
/// Do not define it like :
/// int (*p)[3]:
/// This declares the p as a pointer to an array of 3 integers and not as an array of three pointers.

#include <iostream>

int main()
{
    int *p[3], i = 10, j = 30;
    p[0] = &i;
    *p[0] = 20; // Changes the value of i
    p[1] = &j;
    p[2] = p[0]; //p[2] also points to i now.
    
    std::cout << i + *p[1] + *p[2] << std::endl; // 20 + 30 + 30

    return 0;
}

/// Array of pointers is often used in place of a 2-D array to handle strings. 
/// One reason to use this is to save the memory.
/// E.g.
/// char names[][12] = {"First Name", "Second Name", "Third"}; 
/// The above line will allocate the 12 bytes for each row, no matter what the length of the string is.
/// On the other hand if we use the array of pointers.
/// char *names[] = {"First Name", "Second Name", "Third"};
/// The allocated memory matches the length of each string.
/// The elements of the array will be pointers to respective strings.
/// Because of the diverse right-hand ends, this array is often called a ragged string array(Didn't get this). Let’s make a simple question, 
/// what is the size of this names array?
/// Here is the answer. Assuming that each pointer allocates 4 bytes, since the array contains three elements its size is 12 bytes, 
/// regardless of the string lengths.
/// Also apart from memory, the use of array of pointers to handle strings may improve the performance of the program.

/// Exercise:
/// C.8.18
#include <iostream>
int main()
{
    int *p[3], i, num;

    for (i = 0; i < 3; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> num;
        p[i] = &num;
    }
    for (i = 0; i < 3; i++)
    {
        std::cout << p[i] << " ";
    }
    return 0;
}
/// Answer: The statement p[i] = &num; makes each element of p to point to the address of num. 
/// So, since all three pointers point to the same address, their content would be equal to the last value of num. 
/// Thus, the second loop outputs three times the last input value.