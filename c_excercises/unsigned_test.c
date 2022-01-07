#include<stdio.h>

int main(){
    unsigned int x = 0xFFFFFFFF;
    int y = 0xFFFFFFFF;

    printf("%d, %d", x, y); // -1 ,-1
    printf("%u, %u", x, y); // 4294967295 , 4294967295

    if (x < 0)
        printf("one\n"); 
    else
        printf("two\n"); // x is unsigned hence less > 0
    if (y < 0)
        printf("three\n"); // y is signed hence less < 0
    else
        printf("four\n");


    printf("sizeof(x) = %lu\n", sizeof(x)); // 4
    printf("sizeof(y) = %lu\n", sizeof(y)); // 4
    return 0;
}

