// Question from lecture 13
// C.8.27 
// Use pointer p to create the program in which create an identity 5 *5 matrix. In math, an identity matrix has 1s on the main
// digonal's element and 0s at other places. 
// I am trying to print the array using same for loop.
#include<iostream>
int main()
{
    const int SIZE = 5;
    int *p, arr[SIZE][SIZE] = {0}, i;

    for (p = &arr[0][0], i = 0; p < &arr[SIZE][SIZE]; p++)
    {
        if ((p - &arr[0][0]) % (SIZE + 1) == 0)
        {
            *p = 1;
        }
        std::cout << *p << " ";
        if (p == &arr[i][SIZE] - 1)
        {
            std::cout << std::endl;
            i++;
        }
    }
    return 0;
}