// Maximum value of a Binary Tree using Linear (while) queue
//
// Created by @altanai on 31/03/21.
//
// Note that binary tree is un ordered thus all values need to be traversed to find the max O(n)
#include<iostream>
#include<queue>
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

int max(node* root){

    if(root==NULL)  return -1; // bt was empty , max not found

    int max=0;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr= q.front();
        q.pop();

        if(max<curr->data) max = curr->data; 

        if(curr->left) {
            if(max<curr->left->data) max = curr->left->data;
            q.push(curr->left);
        }
        if(curr->right){
            if(max<curr->right->data) max = curr->right->data;
            q.push(curr->right);
        }
    }

    return max;
}

int main(){

    struct node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->right->right = new node(7);
    // root->right->right->right = new node(3);
    cout<< "Max in Binary tree " << max(root);

}

// g++ minmax_bt_queue.cpp -o mminmax.out  
// 