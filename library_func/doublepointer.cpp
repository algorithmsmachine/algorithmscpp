#include <stdio.h>
#include <stdlib.h>

void alloc2(int** p) {
    *p = (int*)malloc(sizeof(int));
    **p = 10;
}

void alloc1(int* p) {
    p = (int*)malloc(sizeof(int));
    *p = 10;
}

int main(){
    int *p = NULL;
    alloc1(p);
    //printf("%d ",*p);//undefined
    
    alloc2(&p);
    printf("%d ",*p);//will print 10
    free(p);
    return 0;
}