#include<stdio.h>

int main(){
    int A;
    printf("\n A without assignmen %d",A);  // garbage value -207628336
    printf("\n &A without assignmen %p",&A); // 0x7ffeee76fae4

    int *B;
    printf("\n ptr *B without assignmen %p",B); // 0x55dcf39fd5a0
    printf("\n ptr *B without assignmen %d",*B); // -1991643855
    printf("\n ptr &B without assignmen %p",&B); // 0x7ffe155ab088

    int C=10;
    // printf("\n C with 10 assignmen %p",*C); // C if of type int and *C is inavlid
    printf("\n &C with 10 assignmen %p",&C); //0x7ffe5d1e241c

    int *D=&C;
    printf("\n ptr D with &C assignmen %p",D); // 0x7ffe5d1e241c
    printf("\n ptr *D with &C assignmen %d",*D); // 10
    printf("\n ptr &D with &C assignmen %p",&D); // 0x7ffe5d1e2428


    int **E=&D;
    printf("\n Double ptr E with &D assignmen %p",E);  //0x7ffe5d1e2428
    printf("\n Double ptr *E with &D assignmen %p",*E); // 0x7ffe5d1e241c
    printf("\n Double ptr &E with &D assignmen %p",&E);  // 0x7ffe5d1e2430


    return 0;
}