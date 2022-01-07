// initialize and access structs emmebrs 
#include <stdio.h>
struct Point{

    int x;  // 4 
    int y; // 4
    double z; // 8
};

int main(){
    struct Point p={10,20};
    printf("The coordination of point are: %d,%d", p.x, p.y); // 10 , 20 
    printf("sizeof(p) = %lu\n", sizeof(p)); // 8
    return 0;
}