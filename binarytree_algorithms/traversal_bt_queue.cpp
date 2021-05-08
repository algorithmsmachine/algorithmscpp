//
// Created by @altanai on 31/03/21.
//

#include <iostream>
#include <queue>
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

void levelorder(node* root){
    if(root==NULL) return;
    
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        
        node* curr = q.front(); // / Print front of queue and remove it from queue
        cout<< curr->data << "  ";
        q.pop();
        
        if(curr->left)  q.push(curr->left); // Enqueue left child
        
        if(curr->right) q.push(curr->right); // Enqueue right child
    }
}

int main() {

    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);

    // cout << "Inorder traversal ";
    // inorder(root);
    // cout << endl;

    // cout << "Pre traversal ";
    // preorder(root);
    // cout << endl;

    // cout << "Post traversal ";
    // postorder(root);
    // cout << endl;

    cout << "Level Order ";
    levelorder(root);
    cout << endl;

    return 0;
}

// g++ traversal_bt_queue.cpp -o traversal.out 
