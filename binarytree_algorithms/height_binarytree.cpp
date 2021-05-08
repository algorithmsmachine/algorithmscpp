//
// Created by @altanai on 31/03/21.
//

// Heighgt of binary tree / number of levels in binary tree 

// The approach is to calculate the height of the left and right subtree. The height of a subtree rooted at any node will be one more than the maximum height of its left and right subtree. 
// Recursively apply this property to all tree nodes in a bottom-up manner (postorder fashion) and return the subtree’s maximum height rooted at that node


#include <iostream>
using namespace std;

struct node{
    int data; 
    struct node* left;
    struct node* right;
    node(int value){
        data = value;
        left = NULL;
        right = NULL;        
    }
};

// Computes recursively the height of a binary tree
// Input: A binary tree T
// Output: The height of T
// if T = ∅ return −1
// else return max{Height(T lef t ), Height(T right )} + 1
int height(node *currnode ){
    if(currnode==NULL) return 0;//  Base case: empty tree has a height of 0
    // Single node tree has height of 1 
    return 1+ max(height(currnode-> left) , height(currnode->right));
}

int main() {
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    cout << "Height of tree " << height(root);
    return 0;
}