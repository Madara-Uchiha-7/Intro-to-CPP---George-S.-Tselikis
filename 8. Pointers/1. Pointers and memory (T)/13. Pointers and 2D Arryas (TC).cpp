// When 2D arrays are declared its elements are stored in successive memory locations, starting with the 
// elements of the first row, followed by the elements of the second row, and so on. 

// C++ treats a 2D array as 1D array, where each element is an array.
// For e.g. int a[2][3] :-> The elemets of a are a[0], a[1], a[2], where each one holds the array
// I.e. Inside the a[0] we will have a[0][0], a[0][1], a[0][2] and same for a[1] and a[2].
// If we write the sizeof(a[0]), the program will give 12.

// a[0] can be used as a pointer to a[0][0]. So *a[0] will be equal to a[0][0] which is same as **a.
// a[0] + 1 is same as a[0][1]. 
// So, a[0] + j is same as &a[o][j] and *(a[0] + j) is same as a[0][j].

// We can use i at the place of 0. 
// We also know that a[i] is converted to *(a + i), So we have
// *(a + i) + j is same as &a[i][j].
// *(*(a + i) + j) is same as a[i][j].

// Lets see the 3 ways to display the 2D array elements:

#include <iostream>

int main()
{
    int i, j, a[2][3] = {10, 20, 30, 40 ,50 ,60};

    for (i = 0; i < 2; i++)
    {
        // In below line *(a + i) and a[i] are giving the address 
        // So, *(a + i) + j will give the address, we again used * to get the value from it on line 35.
        std::cout << "a[" << i << "] : " << *(a + i) << std::endl;
        for (j = 0; j < 3; j++)
        {
            std::cout << "a[" << i << "][" << j << "] : " << a[i][j] << " || ";
            std::cout << "a[" << i << "][" << j << "] : " << *(a[i] + j) << " || ";
            std::cout << "a[" << i << "][" << j << "] : " << *(*(a + i) + j) << std::endl;
        }
        std::cout << std::endl;
        std::cout << "----------------" << std::endl;  
    }
    std::cout << std::endl;
    // Checking what will *(a + i) will give of 1D array -->Related to line 28 and 29.
    int arr[] = {1, 2, 3};
    for (i = 0; i < 3; i++)
    {
        std::cout << *(arr + i) << " "; 
    }
    // It returns value for 1D array but for 2D array it will return the address because in 2D array
    // a[i] points to the a[i][j] address i.e. it points to another array present at the i th row.
}

// Lets say there are 2 arrays
// int a[2][3], b[10];
// My question is: As we say that b can be used as a pointer to b[0], 
// is it correct to say that a can be used as a pointer to a[0][0]?
// Because C++ treats a as a one-dimensional array, the answer is no, a can be used as a pointer to the first element, 
// that is, a[0]. Therefore, if we want to assign a to a pointer variable, what should be the type of the pointer? 
// It should be pointer to an array. For example:
// int (*p)[3]; // Brackets are necessary, o.w. compiler will think it as an array of 3 pointers to integer.
// p = a; // This will make p point to the first row of the array i.e. a[0][0].
// Remember, in a declaration such as int x[5], x “decays” to a pointer, while in a declaration such as int y[5][3], 
// y does not “decay” to a pointer to a pointer, but to a pointer to array.
// Make a note of that: the type of the expression &x is a pointer to an array of five inetegrs, while the type of the expression 
// &y is a pointer to an array of five arrays where each array contains three integers.
// where will p point to? Applying pointer arithmetic and because its type is pointer to an array, it will be incremented by the 
// size of the row and point to the first element of the next row. E.g.

int main()
{
    int i, a[2][3] = {10, 20, 30, 40, 50, 60}, (*p)[3];
    
    // Since P points to the rows we can use it in outer for loop
    for (p = a; p < (a + 2); p++) // We can also do : p < &a[2]
    {
        for (i = 0; i < 3; i++)
        {
            std::cout << (*p)[i] << " "; // Displays elements from each row.
        }
        std::cout << std::endl;
    }
    // We can also create the array of pointers which points to the each row.
    int *p[4] = {a[0], a[1], a[2], a[3]};
    // Using this above line we can skip outer for loop and keep only inner for loop and 
    // print using std::cout << *(p[i] + 1) << " "; 
    // Where i will start from 0, in place of 1 you can use i, 1 will make is start from index 2.
    return 0;
}

/// Equivalent pointer expression to access an element of up to 4D array are:
// arr[i] = *(arr + i);
// arr[i][j] = *(*(arr + i) + j);
// arr[i][j][k] = *(*(*(arr + i) + j) + k);
// arr[i][j][k][l] = *(*(*(*(arr + i) + j) + k) + l);

// Exercise :
// C.8.24 What does the code do: 
/*
int main ()
{
    int i, arr[2][5] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (i = 0; i < 2 ; i++)
    {
        *(arr[i] + 3) = 0; // Makes arr[0][3] and arr[1][3] 0.
    }
}
*/

// C.8.25 What does the code do:
int main()
{
    int *ptr, arr[2][5] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 20};
    for (ptr = arr[1] + 2; ptr < arr[1] + 5; ptr++)
    {
        *ptr = 0;
    }
}
/*
ptr = arr[1] + 2; makes the pointer point to arr[1][2].
Since *ptr is equal to arr[1][2], *ptr = 0 will make arr[1][2] = 0.
ptr++ will make ptr point to arr[1][3].
The program will make last elements 0. 
*/

// C.8.26 What will happen if we write below for loop for above question
// for (ptr = arr[0] + 4; ptr < arr[0] + 7; ptr++)
// arr[0] + 4 means arr[0][4]. So, 50 will become 0.
// Since array elements are stored in successive memory locations. 
// ptr++ will be (arr[0] + 5 i.e. arr[0][5]) i.e. arr[1][0] i.e. second row's first element.
// Then it ptr will move to (arr[0] + 6 i.e. arr[0][6]) i.e. arr[1][1].
// So code will make last element from 1st row 0 and makes 0 for first 2 from second row.


// C.8.27 
// Use pointer p to create the program in which create an identity 5 *5 matrix. In math, an identity matrix has 1s on the main
// digonal's element and 0s at other places.

int main()
{
    const int SIZE = 5;
    int *p, arr[SIZE][SIZE] = {0};

    for (p = &arr[0][0]; p < &arr[SIZE][SIZE]; p++)
    {
        if ((p - &arr[0][0]) % (SIZE + 1) == 0)
        {
            *p = 1;
        }
    }
    return 0;
}

// E.g. address strats from 1
// (1 - 1) % 6 == 0  -- arr[0][0] becomes 1
// (2 - 1) ^ 6 != 0  -- arr[0][1]
// (3 - 1) ^ 6 != 0  -- arr[0][2]
// (4 - 1) ^ 6 != 0  -- arr[0][3]
// (5 - 1) ^ 6 != 0  -- arr[0][4]

// (6 - 1) ^ 6 != 0  -- arr[1][0]
// (7 - 1) ^ 6 == 0  -- arr[1][1] becomes 1
// (8 - 1) ^ 6 != 0  -- arr[1][2]
// (9 - 1) ^ 6 != 0  -- arr[1][3]
// (10 - 1) ^ 6 != 0  -- arr[1][4]

// (11 - 1) ^ 6 != 0  -- arr[2][0]
// (12 - 1) ^ 6 != 0  -- arr[2][1]
// (13 - 1) ^ 6 != 0  -- arr[2][2] becomes 1

// And so on..incredible
// condition is based on the observation that the number of elements between two successive diagonal’s 
// elements is SIZE. For example, in the 5×5 array, the elements of the diagonal are in positions 0, 6, 12, 18, 
// and 24.
// So, we do not have i and j here. So we can not know what are the current indexs.
// From above obervation we know that, if [0][0] is location 1 then [1][1] will be 5 locations away from it.
// I.e. If 0 is our location then 0 -> 1,2,3,4,5 -> 6.
// Here p will start from 0. So (p - &arr[0][0]) will automatically yeild 0 for [0][0]. i.e. 0 - 0 = 0
// Then P will go to 6, i.e. 0 -> 1,2,3,4,5 -> 6
// so 6 - 0 = 6. To make it 0, we used modulo for making == 0 condition work.
// Then 6 -> 7,8,9,10,11 -> 12

// C.2.28 
// Write a program that assigns random integers to a 3*5 array and displays the minimum and the maximum
// value of each row and column. Use pointer arithmatic to process the array.

#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::setw;
int main()
{
    const int ROWS = 3;
    const int COLS = 5;

    int i, j, min, max, arr[ROWS][COLS];

    srand(time(NULL)); // Somehow this line is not compiling  even using right libraries.

    for (i = 0; i < ROWS; i++)
    {
        min = max = *arr[i] = rand();
        
        for (j = 1; j < COLS; j++)
        {
            *(arr[i] + j) = rand();
            if (*(arr[i] + j) < min)
            {
                min = *(arr[i] + j);
            }
            if (*(arr[i] + j) > max)
            {
                max = *(arr[i] + j);
            }
        }
        cout << "Row_" << i + 1 << ":Min=" << min << "\nMax=" << max << std::endl;
    }
    // Display the result
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            cout << setw(10) << *(arr[i] + j); 
        }
        cout << std::endl;
    }
    return 0;
}