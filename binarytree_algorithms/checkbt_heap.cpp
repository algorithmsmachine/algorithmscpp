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
bool isbt_heap(struct node* root){
    if(root==NULL) return true;
    if((root->left && root->left->data <= root->data) ||
        (root->right && root->right->data <= root->data)) 
        return false;root->left root->data < max(root->left->data, root->right->data)
        return isbt_heap(root->left) && isbt_heap(root->right);
}
int main(){
    struct node * root= new node(5);
    root->left = new node(4);
    root->right= new node(9);

    cout << isbt_heap(root);
}