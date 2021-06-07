// Binary tree from array, via level order readings
//
// Created by @altanai on 31/03/21.
//

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertarr_bt(int arr[],node* root, int i, int n){
    if(i<n){
        root = new node(arr[i]);
        root->left = insertarr_bt(arr, root->left, 2*i+1, n);
        root->right = insertarr_bt(arr, root->right, 2*i+2, n);
    }
    return root;
}

void inorder(struct node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// ----------------------- utility function 
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
    
    // int arr[] = { 5,1,7 };
    int arr[] = { 1,2,3,4,5,-1,6 }; // assume -1 is null
    // int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };

    int n = sizeof(arr)/sizeof(arr[0]);
    
    struct node* root = insertarr_bt(arr, root ,0, n);
    printBT(root);
    inorder(root);
    return 0;
}

// g++ arr_bt.cpp -o arr_bt.out
// ./arr_bt.out 

// output for array [ 1,2,3,4,5,-1,6]

// └──1
//     ├──2
//     │   ├──4
//     │   └──5
//     └──3
//         ├──-1
//         └──6
// 4 2 5 1 -1 3 6 %  