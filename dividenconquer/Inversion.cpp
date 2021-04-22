// inversion count
// Given a sequence of n numbers 1..n (assume all numbers are distinct). Define a measure that tells us how far this list is from being in ascending order.  

#include <iostream>
#include <math.h>
using namespace std;


// Approach 1 : Count inversions linearly 
// Time Complexity: O(n^2)
// Space Complexity:O(1)
int countinversion_linear(int arr[], int n){
    int count=0;
    for(int i =0; i<=n; i++){
        for ( int j=i+1; j<=n ; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}


// UTILITY FUNCTIONS to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Approach 2 : Count inversions using merge Sort 
// Time Complexity : O(nlog n)

int countInversions(int arr[], int l, int m, int r) {
    int ci=0;
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

    cout << "\n L arr ";
    printArray(L,n1);

    cout << "\n R arr ";
    printArray(R,n2);

    // one way to count inversions 
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
    cout << " \n k " << k << " n1 " << n1;
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

        cout << " \n Arr ";
        printArray(arr,k+1);
    }
    // cout << "\n inversion count  "<< ci;
    return ci;
}

void countinversion_mergesort(int arr[], int l, int r, int &count){

    if(l>=r){
        return;
    };
    
    cout << "\n  countinversion from l=" << l << " to r=" << r ;
    int m = l+ ceil((r-l)/2);
    cout << " m=" << m ;

    countinversion_mergesort(arr, l, m, count);
    countinversion_mergesort(arr, m+1, r, count);

    count = count + countInversions(arr, l, m, r );

    cout << "\n inversion count  "<< count;
}

int main(){
    int arr[] = {3,5,1,7,2,8}; // 5
    //  int arr[] = {1,3,5,2,4,6}; //3 
    // int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};
    // 2056

    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);
    
    cout << "\n Linearly calcuated Inversion count "<< countinversion_linear(arr, n-1);

    int count = 0; 
    countinversion_mergesort(arr ,0, n-1, count);

    // cout << "\nSorted array is \n";
    // printArray(arr, n);

    cout << "\n Inversion count "<< count;

}

// g++ -o inversion.out Inversion.cpp -ansi -pedantic -Wall -Werror -std=c++11
// ./inversion.out 