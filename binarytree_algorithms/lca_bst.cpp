// lowest common ancestor (LCA) of two given nodes in the BST. 

#include<iostream>
using namespace std;

// The 3 scenarios when searching for the nodes to determine the LCA.
// 1. p and q are on opposite sides of the tree (left and right);
// 2. p and q are on the left;
// 3. p and q are on the right.

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

// C(n) = C(n/2) + 1, n > 1
// C(1) = 1
// solving C(n) = 1 + log2n , ε Θ(logn).
struct node* lca(struct node* root , struct node* k1, struct node* k2){
    if(root == NULL) {
        return NULL;
    }
    if(k1->data < root->data && k2->data < root->data ){
        lca(root->left, k1, k2);
    }else if(k1->data > root-> data  && k2->data > root->data){
        lca(root->right, k1,k2);
    }else{
        return root;
    }
}

int main(){
    struct node* root = new node(9);
    root->left = new node(6);
    root->right = new node(12);
    root->right->left = new node(11);
    root->right->right = new node(17);
    struct node * lcanode= lca(root, root->right->right, root->right->left);
    cout<< "LCA node in BST " <<  lcanode->data;
}