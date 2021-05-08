// Merge Sort 

// array is recursively divided in two halves till the size becomes 1
// merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.  

// MergeSort(arr[], l,  r)
// If r > l
//     1. Find the middle point to divide the array into two halves:  
//             middle m = l+ (r-l)/2
//     2. Call mergeSort for first half:   
//             Call mergeSort(arr, l, m)
//     3. Call mergeSort for second half:
//             Call mergeSort(arr, m+1, r)
//     4. Merge the two halves sorted in step 2 and 3:
//             Call merge(arr, l, m, r)

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Time complexity T(n)=2T(n/2) + θ(n)
// case II of Master Method and the solution of the recurrence is θ(nLogn) 
// Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) 
// as merge sort always divides the array into two halves and takes linear time to merge two halves.
// Auxiliary Space: O(n)
void merge(int arr[], int l , int m , int r){

    // Create 2 temporary array
    int a1 = m-l+1; // temp array 1 size
    int a2 = r-m;   // temp array 2 size 
    // int L[a1], R[a2];
    int *L = new int[a1];
    int *R = new int[a2];

    for(int i=0;i<a1;i++)
        L[i]=arr[l+i];

    for(int j=0;j<a2;j++)
        R[j]=arr[m+1+j];

    int i=0; // index of first/left array
    int j=0; // index of second/right array
    int k=l; // index of merged arr 

    while(i<a1 && j<a2){
        if(L[i] <= R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    // copy the remaning elemenst of L array , if any 
    while (i<a1){
        arr[k]=L[i];
        i++;
        k++;
    }

    // copy the reminaing elements of R array , if any 
    while(j<a2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

// params : arr - array of integers 
// l - left index 
// r - right index 
void mergeSort(int arr[],int l, int r){
    if( l>=r){
        return;
    };
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);

    merge(arr,l,m,r);
}

// UTILITY FUNCTIONS to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    // int arr[] = {3,5,1,7,2,8};
    // int arr[] = { 23,566,243,78,123,4354,354,13,535,35,53,45345,35,234445,3,67,867,432,324,4,34,53,5};
    int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr_size - 1);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

    return 0;
}
 
 // g++ mergesort.cpp -o mergesort -ansi -pedantic -Wall -Werror -std=c++11 
 // ./mergesort