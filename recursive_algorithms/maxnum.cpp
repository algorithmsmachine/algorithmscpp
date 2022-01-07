// Finding Maximum number in array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Without recusssion 
// int maxnum(int arr[], int n){
//     int max = INT_MIN;
//     for(int i=0;i<n;i++)
//         if(arr[i]>max) max = arr[i];
//     return max;
// }

// with recussion 
int maxnum(int arr[],int n ,int i ){
    static int max = INT_MIN;
    if(i<n){
        if(arr[i]>max) max =arr[i];
        maxnum(arr,n,++i);
    }
    return max;
}

int main(){
    int arr[]={5,16,19,8,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout << maxnum(arr,n); // without recussion 
    cout <<  maxnum(arr, n, 0); // with recussion 
}