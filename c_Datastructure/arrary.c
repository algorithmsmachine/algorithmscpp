#include<stdio.h>


void test(){
    int *p;        // points to int
    int(*parr)[5]; // points to array of 5 in size
    int myarr[5] ={10,20,30,40,50};

    p = myarr;    // p points to start of int
    parr = myarr; // parr point to start of whole arr

    printf("Address of p = %p\n", p);
    printf("Address of parr = %p\n", parr); // parr's base type is a pointer to an array of 5 integers



    // derreference p and parr
    printf("Value of p = %d\n", *p);
    printf("Value of parr = %d\n", *parr);  // *parr base type is a pointer to int 

    p++;
    parr++; // increments 5 times * 4 ( int size ) = 20 bytes
    printf("Address of p = %p\n", p);
    printf("Address of parr = %p\n", parr);
}

int main()
{
    int my_arr[5] = {10, 20, 30, 40, 50}, i;

    // arr points to the address of the first element
    printf("Address of first element/ arr = %p \n", my_arr);

    // my_arr is same as &my_arr[0]
    // my_arr + 1 is same as &my_arr[1]
    // my_arr + 2 is same as &my_arr[2]
    // my_arr + 3 is same as &my_arr[3]
    // my_arr + 4 is same as &my_arr[4] 
    printf("Address of last element/ arr = %p \n", my_arr+1);

    for(i = 0; i < 5; i++)
    {
        printf("Value of a[%d] = %d \t", i, my_arr[i]); 
        printf("Address of a[%d] = %p \n", i, &my_arr[i]);
    }

    // dereference my_arr then we get the first element of the array i.e *my_arr
    printf("Value of *my_arr = %d \n", *my_arr);
    for(i = 0; i < 5; i++)
    {
        printf("Value of a[%d] = %d\t", i, *(my_arr + i) );
        printf("Address of a[%d] = %p\n", i, my_arr + i );
    }

    int *p;
    p = my_arr;
    printf("Value of first element *p = %d\n", *p);
    printf("Value of second element *p = %d\n", *(++p));
    
    int *q= my_arr;
    for(i = 0; i < 5; i++)
    {
        printf("Value of a[%d] = %d\t", i, *(q + i));
        printf("Address of a[%d] = %p\n", i, q + i );
    }

    // signal to operating system program ran fine
    return 0;
}