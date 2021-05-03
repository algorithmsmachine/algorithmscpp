// Permutations 
 // Algorithm : HeapPermute (n)
 // input : positive int n and a global arra A[1..n]
 // output: all permutatios of elements of A

//  if n=1  write A
//  else
//     for int i <- t to n do
//     {
//         HeapPermute(n-1)
//         if n is odd swap A[1] and A[n]
//         else swap A[i] and A[n] 
//     } 

#include<iostream>
using namespace std;

// UTILITY FUNCTIONS to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

void permute(int arr[],int size,int n){
    if(n==1){  
        printArray(arr,size);
        cout << endl;
    }
    for( int i =1; i<=n ;i++){
        permute(arr, size, n-1);
        if(n%2!=0){
            int temp = arr[1];
            arr[1]=arr[n];
            arr[n]=temp;
        }else{
            int temp = arr[i];
            arr[i]=arr[n];
            arr[n]=temp;
        } 
    }

}

int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 4;
    permute(arr,n,i);
    return 0;
}
// g++ -o permutations.out permutations.cpp 
// ./permutations.out