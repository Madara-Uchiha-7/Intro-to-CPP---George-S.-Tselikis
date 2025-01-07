/*
C.8.6 
Use the p1, p2, and p3 pointers and complete the following program to read the grades of a student in three tests. 
If all grades are greater than or equal to 5, the program should display them in ascending order. 
Otherwise, the program should display their average. The variables i, j, and k should be used only once.
*/
/*
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    float *p1, *p2, *p3, i , j, k;
    const int totalSubjects = 3;

    p1 = &i;
    p2 = &j;
    p3 = &k;

    cout << "Enter the grades: ";
    cin >> *p1 >> *p2 >> *p3;
    cout << endl;

    float allMarksInAscOrder[totalSubjects] = {*p1, *p2, *p3};
    bool isGreaterThanFive = false;

    if (*p1 >=5 && *p3 >=5 && *p3 >=5 )
    {
        isGreaterThanFive = true;
        for (int i = 0; i < totalSubjects; i++)
        {
            for (int j = i + 1; j < totalSubjects; j++)
            {
                if (allMarksInAscOrder[i] > allMarksInAscOrder[j])
                {
                    float tempMarkHolder = allMarksInAscOrder[i];
                    allMarksInAscOrder[i] = allMarksInAscOrder[j];
                    allMarksInAscOrder[j] = tempMarkHolder;
                }
            }
        }
    }
    for (int j = 0; j < totalSubjects && isGreaterThanFive; j++)
    {
        cout << allMarksInAscOrder[j] << " ";
    }

    float average;
    for (int j = 0; j < totalSubjects && !isGreaterThanFive; j++)
    {
        average += allMarksInAscOrder[j];
    }
    if (!isGreaterThanFive){
        cout << "The average is: " << (average / 3);
    }
    
    return 0;
}
*/