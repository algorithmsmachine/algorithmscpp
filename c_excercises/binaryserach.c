// binary serach

#include<stdio.h>
#include<stdlib.h>


int binarySerach(int arr[], int l, int r , int num){

    int mid = (l+r)/2;

    if(l>r){
        return -1;
    }

    if(num == arr[mid]){
        return mid;
    }

    if(num > arr[mid]){
        return binarySerach(arr,mid,r,num);
    }

    if(num < arr[mid]){
        return binarySerach(arr,l,mid-1,num);
    }

}

int main(){
    
int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = binarySerach(arr,0,n-1,10);

    if(result == -1){
        printf("Number not found\n");
    }else{
        printf("Number found at %d\n",result);
    }

    return 0;
    
}