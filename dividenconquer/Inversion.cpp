#include <iostream>
#include <math.h>
using namespace std;

// Count inversions using merge Sort 
// Time Complexity : O(nlog n)
// submitted by altanai

int merge(int arr[], int l, int m, int r) {
    int ci=0; // count of inversions 
    // Create 2 temporary array
    int n1 = m-l+1; // temp array 1 size
    int n2 = r-m;   // temp array 2 size 
    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    int i=0; // index of first/left array
    int j=0; // index of second/right array
    int k=l; // index of merged arr 

    // counting inversions 
    while(i<n1 && j<n2 ){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
            ci=ci+(n1-i);
        }
        k++;
    }
    if(k>=n1){ // done need last step merge 
        // one of the list is now exhausted, so append the remainder to C
        while (i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    return ci;
}

void mergesort(int arr[], int l, int r, int &count){
    if(l>=r) return;
    int m = l+ ceil((r-l)/2);
    mergesort(arr, l, m, count);
    mergesort(arr, m+1, r, count);
    count += merge(arr, l, m, r );
}

int countInversions(int arr[], int n){
    int count = 0; 
    mergesort(arr ,0, n-1, count);
    return count;
}

int main(){
    // int arr[] = {5}; // 0
    // int arr[] = {5,6}; // 0
    // int arr[] = {6,5}; // 1
    int arr[] = {3,5,1,7,2,8}; // 5
    // int arr[] = {1,3,5,2,4,6}; // 3 
    // int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};  // 2056
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Inversion count "<< countInversions(arr, n) << endl;
}

// To Run 
// g++ -o inversion.out Inversion.cpp -ansi -pedantic -Wall -Werror -std=c++11
// ./inversion.out 