// Check if the binary tree is a binary serach tree ( BST)

// binary serach tree : 
// - left subtree of a node contains only nodes with keys <  node’s key. 
// - right subtree of a node contains only nodes with keys >  node’s key. 
//
// Created by @altanai on 31/03/21.
//

#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// appriach 1 :
// assumes no duplicate elements with value INT_MIN or INT_MAX 
bool isBST(struct node* root, int min , int max){

    // empty free is BST
    if(root == NULL) return true;

    // not BST if this node violates the min/max constraint  
    if(root->data <min || root->data > max) return false;

    // recisively check for iBS on left subtree and right subtree 
    return isBST(root->left, INT_MIN, root->data-1 ) && isBST(root->right, root->data+1, INT_MAX);
}

int main(){

    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);

    cout<<isBST(root,INT_MIN, INT_MAX)<<endl ;
    return 0;
}

// g++ check_binaryhtree.cpp -o checkbst.out
// ./checkbst.out   