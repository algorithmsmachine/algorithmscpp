// Minmax algorithm
// divide-and-conquer algorithm for finding values of both the largest and smallest elements in an array of n numbers.

//
// Created by altanai on 09/08/20.
//
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// 1. Linear Approach 
// best case : arr is sorted in increasing order run once for min and once for max hence 2(n-1)
// worst case : arr is sorted in decreasing order or all eeleemnst are equal 3(n-1)

int findMinimum(int a[], int n)
{
    int mn = a[0]; //initializing minimum
    for (int i = 0; i < n; i++) // complexity O(n)
    {
        mn = min(mn, a[i]); //everytime storing the minimum among the current minimum and the current element
    }
    return mn;
}

int findMaximum(int a[], int n)
{
    int mx = a[0]; //initializing maximum
    for (int i = 0; i < n; i++) // complexity O(n)
    {
        mx = max(mx, a[i]); //everytime storing the maximum among the current maximum and the current element
    }
    return mx;
}

// 2. Approach using simple divide and conquer

// void compareminmax(int arrl, int arrr, int &min, int &max){
//     cout << "\n Compare l " << arrl << " and r "<< arrr << " against existing min "<< min << " and max " << max;
//     if(min > arrl)
//         min = arrl; 
//     if(max < arrr)
//         max = arrr;
// }
// Finds the values of the smallest and largest elements in a given subarray using divide and conquer
// void minmax(int arr[], int l, int r, int &min, int &max){
//     if (r == l){ // if arr contains only 1 element 
//         compareminmax(arr[l],arr[r],min, max);
//         return;

//     }else if ((r-l) == 1){ // if arr contains 2 elements
//         if(arr[l] <= arr[r]){
//             compareminmax(arr[l],arr[r],min, max);
//         }else{ 
//             compareminmax(arr[r],arr[l],min, max);
//         }
//         return;

//     }else {//r − l > 1  if arr contains more than 1 elements

//         int m = floor((l + r)/2);
//         minmax(arr, l, m, min, max); // recur for the left subarray
//         minmax(arr, m+1, r, min, max ); // recur for the right / 2nd subarray
//     }
// }


// Approach 3 : find min and max in array using pairs ( divide ad conquer )
// handle cases of even and odd number seprately 
// minimize the number of comparisions 




// Approach 4 : using optimized divide and conquer
// Tournament Method
// D&C like merge sort and recusively finidnig max and min in the parts .
// find max in min in those smaller parts and 

//Algorithm MinMax (A[l..r], minval, maxval)
//Finds the values of the smallest and largest elements in a given subarray
//Input: A portion of array A[0..n − 1] between indices l and r (l ≤ r)
//Output: The values of the smallest and largest elements in A[l..r]
//assigned to minval and maxval, respectively
// if r = l
//     minval ← A[l]; maxval ← A[l]
// else if r − l = 1
//     if A[l] ≤ A[r]
//         minval ← A[l]; maxval ← A[r]
//     else minval ← A[r]; maxval ← A[l]
// else //r − l > 1
//     MinMax(A[l..(l + r)/2], minval, maxval)
//     MinMax(A[(l + r)/2 + 1..r], minval2, maxval2 )
//     if minval2 < minval
//         minval ← minval2
//     if maxval2 > maxval
//         maxval ← maxval2
// O(n)
int* minmax(int arr[], int l, int r){

    //C++ does not allow to return an entire array as an argument to a function. However, 
    // we can return a pointer to an array by specifying the array's name without an index.

    int* mmarr = new int[2];
    int min,max;

    if (r == l){                // if arr contains only 1 element 
        min = arr[r];
        max = arr[r];

    }else if ((r-l) == 1){      // if arr contains 2 elements
        if(arr[l] <= arr[r]){
            max = arr[r];
            min = arr[l];
        }else{ 
            max = arr[l];
            min = arr[r];
        }

    }else {                     //r − l > 1  if arr contains > than 1 elements

        int m = floor((l + r)/2);
        int *arr1 = minmax(arr, l, m);      // recur for the left subarray
        int *arr2 = minmax(arr, m+1, r);    // recur for the right / 2nd subarray
        // cout << "\n Compare arr1 " << arr1[0] << " and  "<< arr1[1] << " against arr2  "<< arr2[0] << " and  " << arr2[1];
        if ( arr1[1] > arr2[1] )
            max = arr1[1];
        else
            max = arr2[1];

        if ( arr1[0] < arr2[0] )
            min = arr1[0];
        else
            min = arr2[0];

    }
    // mmarr[0,1] ={min, max};
    mmarr[0] =min;
    mmarr[1] =max;
    return mmarr;
}


int main(){
	// int arr[] = {1,4,3,2,-6,-200,5,1,6,1,4};
    int arr[] = {1,4,3,2,-6,-200,5};
	// int arr[] = {1,4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    //Calling a method to find the smallest element
    // cout << "\n minimum via Linear serach " << findMinimum(arr, n);
    //Calling a method to find the largest element
    // cout << "\n maximum via Linear serach " << findMaximum(arr, n);

    // 2. Driver for approach 2
    // int max = INT_MIN, min = INT_MAX;
    // array , size , left posiition , right posistion
	// minmax(arr,0, n-1, min, max);
    // cout << "\n Minimum " << min;
    // cout << "\n Maximum " << max;

    // 3. Driver for approach 3
    int *arrmm = minmax(arr,0, n-1);
    cout << "\n Minimum " << arrmm[0];
    cout << "\n Maximum " << arrmm[1];
	return 0;
}


//ref : https://sureshvcetit.files.wordpress.com/2018/04/solu4.pdf

// g++ minmax.cpp -o minmax
// ./minmax