// C 8.1
/*
    Use p1 and p2 pointers
    Use 2 float variables i and j. Use it only once.
    Swap them using those pointer.
    Use those pointer to disply absolute result of the difference of these values.
    Absolute difference : Difference in variables. 
*/
/*
#include <iostream>
using std::cout;
using std::cin;
int main()
{
    float *p1, *p2, i, j, temp;
    
    // If you want to use pointers to take the input from user for i and j, initialize them.
    // Since we can use i and j only once as per condition we will use pointers to take input.

    p1 = &i;
    p2 = &j;

    cout << "Enter the values";
    cin >> *p1 >> *p2; // *p1 and *p2 will put values in i and j, So we used *

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    if ((*p1 - *p2) > 0)
    {
        cout << *p1 - *p2 << std::endl;
    }
    else
    {
        cout << -(*p1 - *p2) << std::endl;
    }
}
*/

// -----------------------------------------------------------------------------------------------------
// C 8.2
/*
    What is the output 
*/
/*
int *ptr1, *ptr2, *ptr3, i = 0, j = 1, k = 2; 
ptr1 = &i; 
i = *ptr1 ? 3 : 4;  0 ? 3 :4 -> i = 4

ptr2 = &j; 
j = *ptr2 + *ptr1; 4 + 1 -> j = 5

ptr3 = &k; 
k = *ptr3 + *ptr2; 5 + 2 -> k = 7

std::cout << *ptr1 << ' ' << *ptr2 << ' ' << *ptr3 << '\n'; 
return 0;

*/

// -----------------------------------------------------------------------------------------------------
// C 8.3
/*
    Use p pointer and while to display the integer from 1 to 10.
    The variable i should be used only once.
*/
/*
#include <iostream>
int main()
{
    int *p, i;
    p = &i;
    *p = 1;
    while (*p <= 10)
    {
        std::cout << *p << std::endl;
        (*p)++; // Use () for priority reasons.
    }
    return 0;
}
*/

// -----------------------------------------------------------------------------------------------------
// C 8.4

// The ptr2 = ptr1 statemenet will make the ptr2 point to the location of ptr1
// So ptr1 and ptr2 points to the same location now.


// -----------------------------------------------------------------------------------------------------
// C 8.5

/*
    Use p2 pointer and complete the following program to read student grades continuously until
    user enters -1. 
    Use p1 pointer to display how many students got grade in between [5,10] and p3 pointer to display the best grades.
    The variable sum, max and grade should be used only once. 
*/
/*
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int *p1, *p2, *p3;
    int sum, max, grade;

    p1 = &sum;
    *p1 = 0;

    p2 = &grade;

    p3 = &max;
    *p3 = 0;

    while (*p2 != -1)
    {
        cout << "Enter grades: ";
        cin >> *p2;
        if (*p2 == -1)
        {
            break;
        }
        if (*p2 >= 5 && *p2 <=10)
        {
            (*p1)++;  
            
            if(*p2 > *p3)
            {
                *p3 = *p2;
            }  
        }
    }
}
*/