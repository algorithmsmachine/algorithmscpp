//
// Created by altanai on 09/08/20.
//
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;


// approach 1 : iterative binary serach 
// int binarysearch(int arr[], int n ,int T){
//     int l = 0;
//     int r = n ;

//     while(l<=r){
//         cout << "\n l " << l << " r "<< r; 
//         int m = floor((l+r)/2);

//         cout << " m " << m << " value " << arr[m];

//         if(T < arr[m]){ 
//             r = m-1;           // Goto left
//         }else if (T > arr[m]){
//             l = 1+m;            // Goto right
//         }else{
//             return m;
//         }
//     }
    
//     return -1; // not found
// }

// approach 2 : recurssive binary serach 
int binarysearch(int arr[], int l ,int r, int T){

    if(l<=r){
        cout << "\n l " << l << " r "<< r; 
        int m = floor((l+r)/2);
        cout << " m " << m << " value " << arr[m] ;
        if(T < arr[m]){
            return binarysearch(arr, l, m-1, T); // going to left 
        }else if(T > arr[m]){
            return binarysearch(arr, m+1, r, T);  // going to right 
        }else{
            return m;
        }
    }else{
        return -1;  
    }    

}


int main(){
    
    int arr[]={2,5,6,7,9,10,24,27,29,31,35,38,39,41,43,47,48,52,55,57,58,59,63,64,66,69,71,75,78,80,84,85,89,91,92,93,94,95,97,100}; 
    // int arr[]={2,5,6,7,9,10}; // input element to biniary search should be ordered 

    int n = sizeof(arr)/sizeof(arr[0]);
    cout << " size of array "<< n << endl;
    
    int T= 95; //element to find

    auto start = high_resolution_clock::now();
    // int p= binarysearch(arr,n-1,T);
    int p= binarysearch(arr, 0, n-1, T);
    auto stop = high_resolution_clock::now();

    if(p ==-1 ) cout<< " \n Element not found in arr ";
    else cout<< " \n position of element found in arr "<<p << " where element is "<<  arr[p];

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

    return 0;
}

 // g++ binarysearch.cpp -o binarysearch -ansi -pedantic -Wall -Werror -std=c++11 
 // ./binarysearch

