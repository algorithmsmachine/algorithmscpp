// selection sort

#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}


void selectionsort(int arr[], int n){
    for ( int i =0 ; i<=n-2 ; i++){
        cout << "\n n " << arr[i];
        int min = i ;
        for( int j = i+1; j<=n-1 ; j++){
            if(arr[j]< arr[min]){
                cout << "\n new min " << arr[j];
                min = j;
            }
        }
        // swap new min with older min
        cout << "\n swap " << arr[i] << " with " << arr[min]  << endl;
        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        
        printArray(arr, n);
    }
}


int main(){
    int arr[] = {3,5,1,7,3,8};

    // int arr[] = {5,7,3,1,5,6,3,5,1,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6,3,5,1,7,3,8,4,2,7,6,5,3,1,8,9,0,3,4,5,6,7,8,9,3,4,5,6,7,2,3,4,5,2,3,4,8,9,4,5,6,7,4,5,6,3,4,5,6,7,8,9,0,3,4,5,6};

    int n = sizeof(arr)/sizeof(*arr);
    cout << " size of input n "<< n << endl;
    printArray(arr,n);

    auto start = high_resolution_clock::now();
    selectionsort(arr, n);
    auto stop = high_resolution_clock::now();

    cout << "\nSorted array is \n";
    printArray(arr, n);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n duration " << duration.count() << " ms " << endl;

}

// g++ -o selectionsort.out selectionsort.cpp
// ./selectionsort.out 