#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("%d\n", arr[1][2]);

    // top row
    //*(arr + i) points to the address of the 0th element of the 1-D array. So,
    // *(arr + i) + 1 points to the address of the 1st element of the 1-D array
    // *(arr + i) + 2 points to the address of the 2nd element of the 1-D array
    printf("%d\n", *(arr + 1));
    printf("%d\n", *(arr + 1) + 1);
    printf("%d\n", *(arr + 1) + 2);
    // *(arr + i) + j points to the base address of jth element of ith 1-D array.
    // So, derefernece *(arr + i) + j to get the value of jth element of ith 1-D array.
    printf(" derefernece *(arr + i) + j %d\n", *(*(arr + 1) + 1));
    for (int i = 0; i < 3; i++)
    {
        printf("Address of %d th array %u  and %p \n", i, arr + i , *(arr + i));
        for (int j = 0; j < 4; j++)
        {
            printf("arr[%d][%d]=%d\n", i, j, *(*(arr + i) + j));
        }
        printf("\n\n");
    }

    // Assigning 2-D Array to a Pointer Variable
    int(*ptr)[3]; // p is a pointer to an array of 3 integers.
    ptr = arr;

    //  dereference (p+i) then we will get the base address of ith 1-D array
    // which itself is (*int) pointer to int
    printf("%d\n", *(*(ptr + 1) + 1));
    //*(*(p + i) + j) gives the value of jth element of ith 1-D array.
    for (int i = 0; i < 3; i++)
    {
        printf("Address of %d th array %u  and %p \n", i, ptr + i, *(ptr + i));
        for (int j = 0; j < 4; j++)
        {
            printf("arr[%d][%d]=%d\n", i, j, *(*(ptr + i) + j));
        }
        printf("\n\n");
    }
    return 0;
}