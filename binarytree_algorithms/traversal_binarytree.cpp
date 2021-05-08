//
// Created by @altanai on 31/03/21.
//

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

// Inorder is L -> Root -> R
void inorder(node* currnode){
    if(currnode ==NULL) return;
    inorder(currnode->left); 
    cout << currnode->data << " " ;
    inorder(currnode->right);
}

// Preorder is Root -> L -> R
void preorder(node* currnode){
    if(currnode ==NULL) return;
    cout << currnode->data << " " ;
    preorder(currnode->left); 
    preorder(currnode->right);
}

// Postorder is  L -> R -> Root
void postorder(node* currnode){
    if(currnode ==NULL) return;
    postorder(currnode->left); 
    postorder(currnode->right);
    cout << currnode->data << " " ;
}

int main() {

    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);

    cout << "Inorder traversal ";
    inorder(root);
    cout << endl;

    cout << "Pre traversal ";
    preorder(root);
    cout << endl;

    cout << "Post traversal ";
    postorder(root);
    cout << endl;

    return 0;
}

// g++ traversal_binarytree.cpp -o traversal.out 
