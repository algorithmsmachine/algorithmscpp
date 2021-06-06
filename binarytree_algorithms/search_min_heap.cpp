// Search min in MaxHeap 

// Since heap is balanced binary tree with parental dominance , the min element will be in leaf nodes
// start from ceil(n/2) to n 
// Time complexisty O(n) as 1/2 doesnt affect asymptotic complexity 


// same process can be used to find the maximum element in min heap

#include<bits/stdc++.h>
using namespace std;

int findmin(int heap[], int n){
    int minelm = heap[n/2];
    for(int i=1+n/2; i<n;i++){
        minelm = min(minelm,heap[i]);
    }
    return minelm;
}

int main(){
    int heap[] = { 20, 18, 10, 12, 9, 9, 3, 5, 6, 8 };
    int n = sizeof(heap)/sizeof(heap[0]);
    cout << " min element "<< findmin(heap,n);
    return 0;
}