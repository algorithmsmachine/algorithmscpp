// Bottom-Up Heap Construction 
// heapify procedure calls itself recursively to build heap in top down manner. 
//
// Created by @altanai on 31/03/21.
//

#include <iostream>
using namespace std;

//Constructs a heap from elements of a given array by the bottom-up algorithm
//Input: An array H [1..n] of orderable items
//Output: A heap H [1..n]
// void heapbottomup(int arr[] , int n){
//     for (int i =0; i<=n/2; i++){
//         int k = i;
//         int v = arr[k];   
//         bool heap = false;
//         while( !heap && 2*k <= n ){
//             int j = 2*k;
//             if(arr[j]< arr[j+1]) j++;
//             if(v >= arr[j]) {
//                 heap = true;
//             }else {
//                 arr[k] = arr[j];
//                 k = j;
//             }
//         }
//         arr[k]=v;
//     }
// }

void printarray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<< endl;
}


// approach 1  :  bottom-up order.
// Heapify procedure applied to a node only if its children nodes are heapified
// 2(n − log 2 (n + 1))
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i +1 ;
    int r = 2*i +2 ;

    if( l<n && arr[l]>arr[largest]) largest=l;
    if( r<n && arr[r]>arr[largest]) largest=r;
    if(largest !=i ) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapbottomup(int arr[] , int n){
    int nonleftindex = n/2 -1;
    for(int i = nonleftindex; i>=0; i--){
        heapify(arr, n,i);
        printarray(arr, n);
    }
}


// approach 2 : Top Down heap order 
// constructs a heap by successive insertions of a new key into a previously constructed heap
// height of a heap with n nodes is about log2 n, the time efficiency of insertion is in O(log n).
void heaptopdown(int arr[], int n){

}

// ----------------------- utility function 
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
node* insertarr_bt(int arr[], node* root, int i, int n){
    if(i<n){
        root = new node(arr[i]);
        root->left = insertarr_bt(arr, root->left, 2*i+1, n);
        root->right = insertarr_bt(arr, root->right, 2*i+2, n);
    }
    return root;
}
void printBT(const std::string& prefix, const struct node* root, bool isLeft){
    if( root != nullptr ){
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << root->data << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}
void printBT(const struct node* root){
    printBT("", root, false);    
}

int main(){
    int arr[] = {12,15,19,10,8,16,5}; //{2,9,7,6,5,8}; //{3,5,1,7,2,8};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    heapbottomup(arr, arr_size);
    printarray(arr, arr_size);

    int n = sizeof(arr)/sizeof(arr[0]);
    struct node* root = insertarr_bt(arr, root, 0, n);
    printBT(root);

    return 0;
}

// g++ HeapBottomUp.cpp -o HeapBottomUp.out 
// ./HeapBottomUp.out

// Outpupt 
// 12 15 19 10 8 16 5 
// 12 15 19 10 8 16 5 
// 19 15 16 10 8 12 5 
// 19 15 16 10 8 12 5 
// └──19
//     ├──15
//     │   ├──10
//     │   └──8
//     └──16
//         ├──12
//         └──5