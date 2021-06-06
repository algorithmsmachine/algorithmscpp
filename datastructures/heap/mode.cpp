#include <bits/stdc++.h>
using namespace std;

// Given an array of integers , write an algorithm to find  the mode of array which performs better than the brute force implementation which has quadratic cost.
// Note : The mode is the most frequent array element. 
// Provide the time efficiency for your approach . 

// Answer : First sort the array using an efficient sorting algorithm and then we only need to count runs of value. 

// Algorithm PresortMode(A[0...n-1])
// Input : a sorted array A
// Output : mode of array A
    // i ← 0
    // modefrequency ← 0
    // while i < n do
    //     runlength ← 1
    //     runvalue ← A[i]
    //     while i+runlength < n and A[i+runlength] = runvalue do
    //         runlength++
    //     if runlength > modefequency then
    //         modefrequency ← runlength
    //         modevalue ← runvalue
    // return modevalue

// The algorithm runs in linear time without including  the presorting time. 


int findmode(int arr[], int n){
    int modefreq = 0, modevalue=0;  // mode frquency to be calculated
    int i = 0;                      // counter for array index  
      
    while(i<n){
        int currentval = arr[i];    // elelment under inspection
        int run = 0;                // counter for occurance of currentval in array
        while( i+run < n && arr[i+run] == currentval ){
            run++;
        }
        if(run > modefreq){
            modefreq = run;
            modevalue = currentval;
        }
        i++;
    }
    cout<< "mode value "<< modevalue << " mode frequency " << modefreq;
    return modevalue;
}

int main(){
    int arr[]={2,4,5,5,6,8,5,2,3,4}; // mode should be 5
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    cout<< findmode(arr, n);

    // cout << endl;
    // for(int i=0;i<n ;i++)
    //     cout<< arr[i]<< " ";

}