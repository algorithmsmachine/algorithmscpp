// HeapSort
// heapify procedure calls itself recursively to build heap in top down manner. 
// find the max at mtop abd place it ar end , repeat for all 
//
// Created by @altanai on 31/03/21.
//

// Time complexity 
// best case upper bound : O(nLogn)
// avg case upper bound : O(nLogn)
// worst case upper bound : O(nLogn)

// space complexity 
// worst : O(1)

#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l] > arr[largest]) largest= l;
    if(r<n && arr[r] > arr[largest]) largest= r;
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,l);
    }
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    cout<<endl;
}

void heapsort(int arr[], int n ){
    for(int i=(n/2-1);i>=0;i--){
        heapify(arr,n,i); // build heap
    }
    cout << "Heapified "<<endl ;
    printArr(arr,n);

    for(int i=(n-1);i>=0;i--){
        swap(arr[0],arr[i]); // push max( current root) to the end 
        heapify(arr,i,0);    // heapify the remainig elements
        printArr(arr,n);
    }
}

int main(){
    // int arr[]={1,2,3,6,4,7,5};
    // int arr[]={2,9,7,6,5,8};
    int arr[]={1, 8, 6, 5, 3, 7, 4};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, n);
    cout << "Heapsort result "<<endl ;
    printArr(arr,n);

    return 0;
}

// g++ heapsort.cpp -o heapsort.out
// ./heapsort.out 
// Heapified 
// 7612435
// 6512437
// 5412367
// 4312567
// 3214567
// 2134567
// 1234567
// 1234567
// Heapsort result 
// 1234567