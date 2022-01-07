// Is binary tree perfect 
//A Binary tree is a Perfect Binary Tree in which all internal nodes have two children 
// and all leaves are at the same level.

// NOT WORKING
#include <iostream>
#include<queue>
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
void addEdge(struct node* root , int key){
    if(root == NULL){
        root = new node(key);
    }else if(key > root->data){
         addEdge(root->right, key);
    }else{
         addEdge(root->left, key);
    }
}


// approach 1 :
// Iterative approach to check if a Binary Tree is Perfect
bool isperfect(node* root){
    queue<node*> q;
    q.push(root);
    int flag=0;

    while (!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp->left && temp->right){
            if(flag==1){
                return false;
            }else{
                q.push(root->left);
                q.push(root->right);
            }
        }else if(!temp->right && !temp->left){
            flag=1;
        }else if(!temp->right || !temp->left){
            return false;
        }
    }
    return true;
}

int main(){
    // int arr[]={5,7,3,6,2,9};
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct node* root= new node(arr[0]);
    for(int i=1;i<n;i++){
        addEdge(root,arr[i]);
    }

    cout << isperfect(root);
}