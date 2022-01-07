#include<stdio.h>
#include<stdlib.h>

    
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    // find the minimum element and put it at the begining of the array
    //Time Complexity: O(N2)
    void selectionsort(int arr[], int n){
        int min;
        //iterate through the array
        for(int i=0;i<n;i++){
            // find the minimum element in the unsorted array
            min=i;
            for(int j=i+1;j<n;j++){
                if(arr[min]>arr[j]){
                    min=j;
                }
            }
            //swap the minmum element we found with the first element
            swap(&arr[min],&arr[i]);
        }
    
    }

    // repeatedly swap adjecent elemnts if they are in wrong order
    void bubblesort(int arr[], int n){
        for(int i=0;i<n;i++){
            // last n elements are alfready in place
            for(int j=0;j<n-i;j++){
                if(arr[j]>arr[j+1]){
                    swap(&arr[j],&arr[j+1]);
                }
            }
        }
    }

    void printArray(int *arr, int size){
        for(int i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    void main(){
        // int *arr = (int *)malloc(sizeof(int)*5);
        int arr[5] = {5,4,3,2,1};
        int n = sizeof(arr)/sizeof(arr[0]);

        // selectionsort(arr, n);
        bubblesort(arr, n);
        printArray(arr, n);
    }