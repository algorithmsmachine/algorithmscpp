// Quick Sort

// Divide and Conquer algorithm 

//partitions the given array around the picked pivot

// versions of picking pivot 
// - Always pick first element as pivot.
// - Always pick last element as pivot (implemented below)
// - Pick a random element as pivot.
// - Pick median as pivot. 

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// UTILITY FUNCTIONS
// print an array
void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
// swap two elements 
void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

// Time complexity analysis 
// T(n) = T(k) + T(n-k-1) + theta(n)
// first two terms are for two recursive calls, the last term is for the partition process
// k is the number of elements which are smaller than pivot. 
// Worst Case θ(n^2)
// Best Case θ(nlogn)

int partition(int arr[], int l , int r){
    int p = arr[r]; // right most pivot
    int i = l-1; // index of smaller element which is right posistion of pivot so far 
    for( int j=l;j<=r-1;j++){
        if(arr[j]<p){
            i++; // increment index of smaller element
            swap(&arr[i],&arr[j]); // swap A[i] and A[j]
        }
    }
    swap(&arr[i+1],&arr[r]); // swap A[i+1] and A[r]
    return (i+1);
}

// Input: A subarray A[l..r] of A[0..n-1], defined by its left and right indices l and r
// Output:Subarray A[l..r] sorted in nondecreasing order
void quicksort(int arr[], int l, int r){
    if(l<r){
        int s = partition(arr, l, r); // split along partition
        quicksort(arr, l, s-1 );
        quicksort(arr, s+1, r);
    }
}

int main(){
    // int arr[] = {3,5,1,7,3,8};
    int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};

    int n = sizeof(arr)/sizeof(*arr);
    cout << " size of input n "<< n << endl;
    printArray(arr,n);

    auto start = high_resolution_clock::now();
    quicksort(arr, 0, n-1);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, n);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

}

// g++ -o quicksort.out quicksort.cpp
// ./quicksort.out 


