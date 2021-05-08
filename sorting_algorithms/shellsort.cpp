// shell Sort

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


void shellsort(int arr[], int n){
    for (int gap = n/2; gap=>0; gap/=2){
        for(int i = gap; j<=n; j++){
            // TBD for(int j=i j>=gap )
        }
    }
}


int main(){
    // int arr[] = {3,5,1,7,3,8};
    int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};

    int n = sizeof(arr)/sizeof(*arr);
    cout << " size of input n "<< n << endl;
    printArray(arr,n);

    auto start = high_resolution_clock::now();
    shellsort(arr, n);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, n);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

}

// g++ -o shellsort.out shellsort.cpp
// ./shellsort.out 