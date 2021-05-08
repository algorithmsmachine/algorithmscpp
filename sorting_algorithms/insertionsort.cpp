// Insertion Sort

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}


void insertionsort(int arr[], int n){
    for ( int i =1 ;i<=n-1;i++){
        int key = arr[i];
        cout << "\n key " << key << endl;
        int j=i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1]=arr[j]; // move everything > key up by one place 
            j--;
        }
        arr[j+1]=key; // put key in its lowest correct place
        printArray(arr,n);
    }
}


int main(){
    int arr[] = {3,5,1,7,3,8};
    // int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};

    int n = sizeof(arr)/sizeof(*arr);
    cout << " size of input n "<< n << endl;
    printArray(arr,n);

    auto start = high_resolution_clock::now();
    insertionsort(arr, n);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, n);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

}

// g++ -o insertionsort.out insertionsort.cpp
// ./insertionsort.out 