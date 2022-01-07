#include<stdlib.h>
#include<stdio.h>

int main(){
    int num =10;
    int *ptr1;
    int **ptr2;
    ptr1 = &num;
    ptr2 = &ptr1;

    //print the values
    printf("%d\n", num);
    printf("%d\n", &ptr1);
    printf("%d\n", **ptr2);
    
    //change the values
    num = 20;
    *ptr1 = 30;
    **ptr2 = 40;
    
    //print the values
    printf("%d\n", num);
    printf("%d\n", *ptr1);
    printf("%d\n", **ptr2);

    return 0;

}