/// C.8.8 : Find the output of the follwing program.
/*
#include <iostream>
int main()
{
    int i = 5, *p = &i;
    p[0] = 1; // Since p is the address of i and we can say p[0] is like array of single element which is i. So, i becomes 1.
    std::cout << i + p[0] << '\n';  // This will print 2.
    return 0;
}
*/
/*
/// C.8.10 : What is the output of the follwing program.
#include <iostream>
int main()
{
    int i, *ptr1, *ptr2, arr[] = {10, 20, 30, 40, 50, 60, 70};

    ptr1 = &arr[2];
    ptr2 = &arr[4];

    for (i = ptr2 - ptr1; i < 5; i += 2)
    {
        std::cout << ptr1[i] << ' ';
    }

    return 0;
}
// when two pointers that point to the same array are subtracted, the result is the number of elements between them, 
// not their distance in memory
// Since both, ptr1 and ptr2 points to same array "ptr2 - ptr1" works.
// ptr2 - ptr1 : makes 4 - 2 = 2
// ptr1 is already arr[2] which is a starting point for ptr1. So, ptr1[i] i.e. ptr[2] is arr[4].
// So, first it prints 50 and then second time it prints 70 due to i += 2.
*/ 

/// C.8.11 : Write a program that reads the grades of ten students, stores them in an array, and displays the best and the 
/// worst grade and the positions of their first occurrences in the array. The program should force the user to enter grades within
/// [0, 10]. Use pointer arithmatic to process the array.
/*
#include <iostream>
int main()
{
    const int TOTAL_STUDENTS = 10;
    int i, max_pos, min_pos;
    float *p, max, min, arr[TOTAL_STUDENTS];

    // Grades will be in the range of 0 to 10.
    max = -1; 
    min = 11;

    for (i = 0; i < TOTAL_STUDENTS; i++)
    {
        p = arr + i; // Set the pointer to array from arr[0] to arr[n] one by one.

        // Get the grade for student i + 1
        do
        {
            std::cout << "Enter the grades: ";
            std::cin >> *p;
        } while (*p >10 || *p <0);

        if (*p > max)
        {
            max = *p;
            max_pos = i;
        }
        if (*p < min)
        {
            min = *p;
            min_pos = i;
        }
    }
    return 0;
}
*/

/// C.8.12 : Use the ptr pointer and complete the following program to read and 
/// store the grades of 50 students into arr and then display the array’s values in reverse order. 
/// Use pointer arithmetic to process the array.
/*
#include <iostream>
int main()
{
    const int SIZE = 100;
    float *ptr, arr[SIZE];

    ptr = arr;

    // He has used arr + SIZE.
    // So arr is pointing to the 1st place of the array.
    // adding size 50 will sort of make it 51, so we have use < not <=
    while (ptr < arr + SIZE)
    {
        std::cout << "Enter grade:";
        std::cin >> *ptr;
        ptr++;
    }
    ptr--;
    while (ptr >= arr)
    {
        std::cout << *ptr << " ";
        ptr--;
    }
    return 0;
}
*/
/// C.8.13
/// Use the ptr pointer and complete the following program to read 50 integers and 
/// store into arr those with a value within [30, 40]. The program should display how many values are 
/// stored in the array. The program should set the value -1 to the remaining elements. Use pointer 
/// arithmetic to process the array.
/*
#include <iostream>
int main()
{
    const int SIZE = 50;
    int *ptr, i, arr[SIZE];

    ptr = arr;

    for (i =0; i < SIZE; i++)
    {
        std::cout << "Enter the number: ";
        std::cin >> *ptr;

        if (*ptr >= 30 && *ptr <= 40)
        {
            ptr++;
        }
    }

    std::cout << ptr - arr << " Elements are stored\n";
    for (; ptr < arr + SIZE; ptr++)
    {
        *ptr = -1;
    }
    for (i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
*/
/// C.8.14
/// How many erros you see?
/*
#include <iostream>
int main()
{
    int i, arr[5] = {10, 20, 30, 40,50};

    for (i = 0; i < 5; i++)
    {
        std::cout << i[arr] << std::endl;
    }

    std::cout << 2[arr] - 3[arr];
}
/// The compiler converts i[arr] to *(i+arr), which is equivalent to *(arr+i), 
/// equivalent to arr[i]. That is: arr[i] = *(&arr[0]+i) = *(arr+i) = *(i+arr) = i[arr]. Thus, 2[arr] 
/// is equivalent to arr[2]. Therefore, the program is compiled successfully and displays the values 
/// of the array’s elements, as well as the difference of arr[2] and arr[3], that is, -10.
/// So if you do:
/// int *ptr = arr + 4;
/// cout << ptr[-2];
/// This will become *(ptr - 2), which is equivalent to *(arr + 4 -2),
/// that is arr[2], and program outputs 30.
/// Similarly, ptr[-2] = 10 will assign the value 10 i.e.  (arr + 4 -2) = 10.
/// Teacher does not recommend this style. 
*/
/// C.8.17 
/// What is the output?
/*
#include <iostream>
using std::cout;
int main()
{
    // Look at the array definition. No number is provided in [] which is allowed.
    // In above code we provided the code.
    int a[] = {0, 0, 1, 2, 3}, b[] = {0, 0, 0, 4, 5, 6};
    int *ptr1 = a, *ptr2 = b;

    while (!*ptr1++ && !(*++ptr2))
    ;

    cout << *(b + (ptr1 - a)) << ' ' << *(a + (ptr2 - b)) << '\n';
}
/// In the first iteration, since ptr1 points to a[0], *ptr1 is equal to a[0], that is, 0. 
/// Thus, the value of !*ptr1 is 1. Next, ptr1 is increased and points to a[1]. Since ptr2 points to b[0], 
/// the ++ptr2 makes it point to b[1], so the value of *++ptr2 is b[1], that is, 0. Thus, the value 
/// of !(*++ptr2) is 1. Since both terms are true, the loop continues.Like before, in the second iteration, 
/// both terms are true; ptr1 points to a[2] and ptr2 points to b[2]. In the third iteration, since a[2] is 1, 
/// the value of !*ptr1 is 0 and when increased it points to a[3]. Pay attention now, here is the key to the 
/// answer. Recall from Chapter 4 and the description of the && operator that if an operand is false the 
/// rest operands are not evaluated and the value of the expression becomes 0. Therefore, the condition 
/// becomes false and the loop terminates. Since ptr2 is not increased, it still points to b[2].
/// Since ptr1 points to a[3], the result of ptr1-a is 3. Therefore, the expression *(b+(ptr1-a)) 
/// is equivalent to *(b+3), that is, b[3]. Similarly, since ptr2 points to b[2] the expression 
/// *(a+(ptr2-b)) is equivalent to *(a+2), that is, a[2]. Therefore, the program outputs: 4 1  
*/
