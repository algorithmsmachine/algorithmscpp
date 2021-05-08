#include <iostream>
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

//approach1 : iterative level order traversal using queue to find level of a key in BT
int levelordertraversal(node* root, int key){
    int level=1;

    queue<node*> q; // empty queue
    q.push(root);
    q.push(NULL);  // delimiter, NULL is pushed to keep track of all the nodes to be pushed before level is incremented by 1

    while(!q.empty()){
        node* curr= q.front();
        // cout << curr->data << "  L " << curr->left << " R " << curr->right << endl; 
        q.pop();
        if(curr == NULL) {
            if (q.front() != NULL) {
                q.push(NULL);
            }
            level++;  // all nodes of this level are traversed, so increment level
        }else {
            if(curr->data == key) return level; 
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return 0;
}

int main() {
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);

    int key = 1;
    cout << "BST level finder for key " << levelordertraversal(root, key) << endl;
    return 0;
}

//  g++ levelfinder_binarytree.cpp -o levelfinder_binarytree.out 
//  ./levelfinder_binarytree.out      