// Merge Sort 

// array is recursively divided in two halves till the size becomes 1
// merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.  

#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;
using namespace std::chrono;

//----------------------------------------------------------------------------------------
// MergeSortbyfactor3(arr[], l,  r)
// If r > l
//     1. Find the third point to divide the array into 4 one thirds:  
//             t = l+ (r-l)/3
//     2. Call mergeSort for first portion:   
//             Call mergeSort(arr, l, t)
//     3. Call mergeSort for second portion:
//             Call mergeSort(arr, t+1, r)
//     4. Call mergeSort for third portion :
//             Call mergeSort(arr, 2t+1, r)
//     5. Merge all 3 portions sorted in step 2 , 3 and 4:
//             Call merge(arr, l, m, r)

void mergefactor3(int arr[],int l,int t, int r){

    cout << "\n mergefactor3 size  l " << l << " t " << t << " r " <<r ;

    int a1 = t-l+1; // temp array 1 size
    int a2 = 2*t-a1;   // temp array 2 size
    int a3 = r-a2;   // temp array 2 size

    int A[a1], B[a2], C[a3];

    for(int i=0;i<a1;i++){
        A[i]=arr[l+i];
        if(a2>i)
            B[i]=arr[t+1+i];
        if(a3>=i)
            C[i]=arr[2*t+1+i];
    }
       
    cout << "\n array size  a1 " << a1 << " a2 " << a2 << " a3 " <<a3 ;

    int a=0; // index of first/left array
    int b=0; // index of second/right array
    int c=0; // index of third array
    int k=l; // index of merged arr 

    while(a<a1 && b<a2 && c<a3){
        if(A[a] <= B[b] && A[a]<=C[c]){
            arr[k]=A[a];
            a++;
        }else if(B[b] <=A[a] && B[b] <= C[c]){
            arr[k]=B[b];
            b++;
        }else{
            arr[k]=C[c];
            c++;
        }
        k++;
    }

    // copy the remaning elemenst of A array , if any 
    while (a<a1){
        arr[k]=A[a];
        a++;
        k++;
    }

    // copy the reminaing elements of B array , if any 
    while(b<a2){
        arr[k]=B[b];
        b++;
        k++;
    }

    // copy the reminaing elements of C array , if any 
    while(c<a3){
        arr[k]=C[c];
        c++;
        k++;
    }
}

// params : arr - array of integers 
// l - left index 
// r - right index 
void mergeSortbyfactor3(int arr[],int l, int r){
    cout << "\n mergefactor3 between " << l << " to " << r ;

    if(l>=r || r-l==0){
        return;
    };
    int t = l+ceil((r+1-l)/3);
    cout << "\n one third  t - " << t;
    
    // if( t==0){
    //     return;
    // };

    mergeSortbyfactor3(arr,l,t);
    mergeSortbyfactor3(arr,t+1,2*t+1);
    mergeSortbyfactor3(arr,2*t+2,r);
    mergefactor3(arr,l,t,r);
}

//----------------------------------------------------------------------------------------
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


// Time complexity T(n)=2T(n/2) + θ(n)
// case II of Master Method and the solution of the recurrence is θ(nLogn) 
// Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) 
// as merge sort always divides the array into two halves and takes linear time to merge two halves.
// Auxiliary Space: O(n)
void mergefactor2(int arr[], int l , int m , int r){

    // Create 2 temporary array
    int a1 = m-l+1; // temp array 1 size
    int a2 = r-m;   // temp array 2 size
    int L[a1], R[a2];

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
void mergeSortbyfactor2(int arr[],int l, int r){
    if( l>=r){
        return;
    };
    int m = l + (r-l)/2;
    mergeSortbyfactor2(arr,l,m);
    mergeSortbyfactor2(arr,m+1,r);
    mergefactor2(arr,l,m,r);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

//----------------------------------------------------------------------------------------
// Driver code
int main()
{
    int arr[] = { 4,2,6,8,2,7,9,3,6 };
    // int arr[] = {2,7,3,4,6,1,8,4,6,7};
    // int arr[] = { 23,566,243,78,123,4354,354,13,535,35,53,45345,35,2345,3,67,867,432,324,4,23,566,243,78,123,4354,354,13,535,35,53,45345,35,2345,3,67,867,432,324,4,23,566,243,78,123,4354,354,13,535,35,53,45345,35,2345,3,67,867,432,324,4,23,566,243,78,123,4354,354,13,535,35,53,45345,35,2345,3,67,867,432,324,4,23,566,243,78,123,4354,354,13,535,35,53,45345,35,2345,3,67,867,432,324,4};
    int arr_size = sizeof(arr) / sizeof(*arr);

    cout << "Given array is \n";
    // printArray(arr, arr_size);
    cout<< "size " << arr_size << std::endl;
    
    // auto start = high_resolution_clock::now();
    // mergeSortbyfactor2(arr, 0, arr_size - 1);
    // auto stop = high_resolution_clock::now();

    auto start = high_resolution_clock::now();
    mergeSortbyfactor3(arr, 0, arr_size - 1);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

    return 0;
}
 
 // g++ mergesortbyfactorn.cpp -o mergesort.out -ansi -pedantic -Wall -Werror -std=c++11
 // ./mergesort