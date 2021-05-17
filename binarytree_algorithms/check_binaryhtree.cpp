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

// approach 1 :
// assumes no duplicate elements with value INT_MIN or INT_MAX 
bool isBST(struct node* root, int min , int max){

    // empty free is BST
    if(root == NULL) return true;

    // not BST if this node violates the min/max constraint  
    if(root->data <min || root->data > max) return false;

    // recisively check for iBST on left-subtree and-right subtree 
    return isBST(root->left, INT_MIN, root->data-1) && isBST(root->right, root->data+1, INT_MAX);
}

// ----------------------- utility function start
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

    // Non BST
    // struct node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);

    // BST
    struct node* root = new node(5);
    root->left = new node(1);
    root->right = new node(7);

    printBT(root);

    isBST(root,INT_MIN, INT_MAX)? cout<< " Yes it is BST" : cout << " Not a BST" ;   
    cout << endl ;
    return 0;
}

// g++ check_binaryhtree.cpp -o checkbst.out
// ./checkbst.out   

// Output for non BST
// └──1
//     ├──2
//     │   ├──4
//     └──3
//  Not a BST

// Output for BST
// └──5
//     ├──1
//     └──7
//  Yes it is BST