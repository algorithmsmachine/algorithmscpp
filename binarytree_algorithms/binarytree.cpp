//
// Created by @altanai on 31/03/21.
//

#include <iostream>
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

int main(){

    struct node* root = new node(5);

    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);

    cout<<root->data ;
    return 0;
}

// g++ binarytree.cpp -o binarytree 
//  ./binarytree 