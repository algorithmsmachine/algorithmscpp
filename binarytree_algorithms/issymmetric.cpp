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

// Symmetric check for binary tree  
// mirror images all roots within itself 
// root->left->left == root->right->right 
// approach 1 :
// Iterative approach to check if a the binary tree is symmetric
bool issymmetric(struct node* root){
    queue<node*> q;
    q.push(root); // pushed two times for either child 
    q.push(root);
    int flag=0;

    node * lnode , *rnode;
    while (!q.empty()){
        lnode = q.front();
        q.pop();

        rnode = q.front();
        q.pop();

        if(lnode->data != rnode->data)
            return false;

        if(lnode->left && rnode->right){
                q.push(lnode->left);
                q.push(rnode->right);
        }else if(lnode->left || rnode->right){
            return false;
        }
        
        if(lnode->right && rnode->left){
                q.push(lnode->right);
                q.push(rnode->left);
        }else if(lnode->right || rnode-> left){
            return false;
        }
    }
    return true;
}

//For every node, data value must be equal to the sum of data values in left and right children. 
// Consider data value as 0 for NULL children.
bool issumproperty(struct node* root){
    queue<node*> q;
    q.push(root); // pushed two times for either child 

    while (!q.empty()){
        node * parent = q.front();
        q.pop();

        if(parent->right && parent->left){
            if(parent->data != (parent->right->data + parent->left->data))
                return false;
            q.push(parent->left);
            q.push(parent->right);
        }else if(parent->right ){
            if(parent->data != parent->right->data)
                return false;
            q.push(parent->right);
        }else if (parent->left ){
            if(parent->data != parent->left->data)
                return false;
            q.push(parent->left);
        }
    }
    return true;
}

// foldable tree 
//    10
//  /    \
// 7      15
//  \    /
//   9  11
// 
// non foldable tree 
//     10
//    /  \
//   7   15
//  /    /
// 5   11

void mirror(struct node* node)
{
    if (node == NULL)
        return;
    else {
        struct node* temp;
 
        mirror(node->left); /* mirror the subtrees */
        mirror(node->right);
         
        temp = node->left; /* swap the pointers in this node */
        node->left = node->right;
        node->right = temp;
    }
}

bool compareNodes(struct node* l, struct node* r){
    if (l == NULL && r == NULL)
        return true;
    
    if (l != NULL && l != NULL && compareNodes(l->left, r->left) && compareNodes(l->right, r->right)) {
        return true;
    }
 
    return false;
}

bool isfoldable(node* root){
    if(root==NULL) return true;

    mirror(root->left); // mirro to compare
    return compareNodes(root->left , root-> right);
    // mirror(root->left); // revert 
}

int main(){
    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(2);
    // root->right->right = new node(0);
    // root->right->right->right = new node(9);

    // // node *root = new node (1);
    // // root->left = new node(2);
    // // root->right = new node(2);
    // // root->left->left = new node(3);
    // // root->left->right = new node(4);
    // // root->right->left = new node(4);
    // // root->right->right = new node(3);

    node* root = new node(3);
    root->left = new node(2);
    root->right = new node(1);
    cout << " \n Issymmetric " << issymmetric(root) << endl;
    cout << " \n Is sum propert " << issumproperty(root);
    cout << " \n Is foldable " << isfoldable(root);
}