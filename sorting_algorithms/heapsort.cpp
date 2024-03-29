// Heap Sort 

//
// Created by altanai on 09/08/20.
//

#include<iostream>
using namespace std;

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapify(int A[], int n, int i){
    int l = left(i);
    int r = right(i);
    int largest(0);
    if (l <= (n-1) && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= (n-1) && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

/*
 * build the heap
 */
void buildMaxHeap(int A[], int n){
    for(int i = n/2-1;i >= 0;i--)
        maxHeapify(A, n, i);

}

/*
 * heapsort
 */
void heapsort(int A[], int n)
{
    buildMaxHeap(A, n);
    for(int i = n-1;i > 0;i--)
    {
        swap(A[0],A[i]);
        maxHeapify(A, --n, 0);
    }
}

void print(int A[], int n)
{
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
    cout << endl;

}

int main(){
    int A[10] = {16,14,10,8,7,9,3,2,4,1};
    heapsort(A, 10);
    print(A, 10);
    return 0;
}
