#include<stdio.h>
void try_to_change(int *, int *);

int main()
{
    int x = 10, y = 20;

    printf("Initial value of x = %d\n", x);
    printf("Initial value of y = %d\n", y);

    printf("\nCalling the function\n");

    try_to_change(&x, &y);

    printf("\nValues after function call\n\n");

    printf("Final value of x = %d\n", x);
    printf("Final value of y = %d\n", y);

    // signal to operating system everything works fine
    return 0;
}

void try_to_change(int *x, int *y)
{
    (*x)++;
    (*y)++;

    printf("\nValue of x (inside function) = %d\n", *x);
    printf("Value of y (inside function) = %d\n", *y);
}