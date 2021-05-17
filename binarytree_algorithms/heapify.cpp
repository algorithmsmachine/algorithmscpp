// Heapify 
//
// Created by @altanai on 31/03/21.
//
// If the parent node is stored at index I, 
// the left child can be calculated by 2 * I + 1 and right child by 2 * I + 2 (assuming the indexing starts at 0). 

#include <iostream>
using namespace std;


void printarray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<< endl;
}

// arrange array by parental dominance for max heap
void maxheapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i +1 ;
    int r = 2*i +2 ;

    if( l<n && arr[l]>arr[largest]) largest=l;
    if( r<n && arr[r]>arr[largest]) largest=r;
    if(largest !=i ) {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

// arrange array by parental dominance
void minheapify(int arr[], int n, int i){
    int smallest = i;
    int l = 2*i +1 ;
    int r = 2*i +2 ;

    if( l<n && arr[l]<arr[smallest]) smallest=l;
    if( r<n && arr[r]<arr[smallest]) smallest=r;
    if(smallest !=i ) {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}


int main(){
    // int arr[]={6,4,5,3,1,2}; 
    int arr[]={1,2,3,6,4,7,5}; 
    int n= sizeof(arr)/sizeof(arr[0]);
    printarray(arr, n);

    for(int i = (n/2-1); i>=0; i--){
        maxheapify(arr, n,i);    
    } 
    cout << "After Max Heapify "<< endl;
    printarray(arr, n);


    for(int i = (n/2-1); i>=0; i--){
        minheapify(arr, n,i);    
    } 
    cout << "After Min Heapify "<< endl;
    printarray(arr, n);

    return 0;
}

// g++ heapify.cpp -o heapify.out
// ./heapify.out 

// output
// 1 2 3 6 4 7 5 
// After Max Heapify 
// 7 6 5 2 4 3 1 
// After Min Heapify 
// 1 2 3 6 4 7 5