// Maximum value of a Binary Tree using recussion
//
// Created by @altanai on 31/03/21.
//
// Note that binary tree is un ordered thus all values need to be traversed to find the max O(n)
#include<iostream>
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

int maxi(node* root){

    if(root==NULL) return -1; // Base Case
    // Return maximum of 3 values:
    // 1) Root's data 
    // 2) Max in Left Subtree
    // 3) Max in right subtree
    int max = root->data;
    int lmax = maxi(root->left);
    int rmax = maxi(root->right);
    // cout <<"\n max " << max << " lmax "<< lmax << " rmax "<< rmax;
    if(lmax > max) max=lmax;
    if(rmax > max) max=rmax;
    return max;
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(0);
    root->right->right->right = new node(9);
    cout <<"Maximum value in BT " << maxi(root) << endl;
    return 0;
}

// g++ minmax_bt.cpp -o mminmax.out
// ./mminmax.out