#include<stdio.h>
#include<stdlib.h>

struct Student{
    int age;
    int marks;
    char name[20];
};

int comparator(const void*p, const void* q){
    return ((struct Student*)p)->marks - ((struct Student*)q)->marks;

    // if Return value 
    // >0 p goes after q
    // 0 same 
    // <0 p goes before q
}


 void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
 }

int main(){

    int arr[]={1,4,6,7,8,2,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    
    qsort((void*)arr, size, sizeof(arr[0]), comparator);
    // void qsort(void *base , size_t num , size_t size, int (*comparator)(const void*, const void*))
    printArray(arr, size);

    return 0;

}