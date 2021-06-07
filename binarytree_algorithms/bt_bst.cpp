// Binary tree to binary Serach Tree Conversion 
//
// Created by @altanai on 31/03/21.
//

// step 1 : create inorder traversal of the tree into temp array O(n)
// step 2 : sort the data O(nlogn) - heap sort , merge sort or quicksort O(n^2)  to O(nlogn)
// Step 3 : again inorder traversal and copy elements to node

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

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
#include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/printBTvertical.h>

void inorderstore(node* root, int temp[], int* i){
    if(root==NULL) return;
    inorderstore(root->left,temp,i);
    temp[*i]=root->data;
    (*i)++;
    inorderstore(root->right,temp,i);
}

int countnodes(node* root){
    if(root==NULL) return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void fillbst(int temp[],struct node*root,int *i){
    if(root==NULL) return;
    fillbst(temp,root->left,i);
    root->data=temp[*i];
    (*i)++;
    fillbst(temp,root->right,i);
}

void bttobst(node* root){
    if(root==NULL) return;            //empty tree
    int n = countnodes(root);         // 1. count nodes 
    int* temparr = new int[n];        // 2. Make temp array and store innorder traversal
    int i = 0;
    inorderstore(root, temparr, &i);
    qsort(temparr,n,sizeof(temparr[0]),compare); // 3. qsort libary function
    i=0;
    fillbst(temparr,root,&i);         // 4. copy sorted values back to tree 
    delete temparr;
}

int main(){

    struct node* root = new node(10);
    root->left = new node(30);
    root->right = new node(15);
    root->left->left = new node(20);
    root->right->right = new node(5);

    printBT(root);
    bttobst(root);
    printBT(root);
    return 0;
}


// g++ bt_bst.cpp -o bt_bst.out
// ./bt_bst.out                
// └──10
//     ├──30
//     │   ├──20
//     └──15
//         └──5
//  Number of node 5
// └──15
//     ├──10
//     │   ├──5
//     └──20
//         └──30