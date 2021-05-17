// Insert / Delete node in BST by level order 

//
// Created by @altanai on 31/03/21.
//

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int value){
        data=value;
        left= NULL;
        right = NULL;
    }
};


// Search(data)
// Begin 
//     If node == null  or node->data == val
//          return node
//     If(data >root->data)
//          Search(node->right)
//     Else If(data < root->data)
//          Search(node->left,data)
//     Return node;
// end
node* searchbst(struct node* root, int val){
    if(root==NULL || root->data == val)
        return root;
    if(val > root->data)
        searchbst(root->right, val);
    else if( val < root->data)
        searchbst(root->left, val);
}

// Insert(data)
// Begin
//     If node == null
//          Return createNode(data)
//     If(data >root->data)
//          Node->right = insert(node->right,data)
//     Else If(data < root->data)
//          Node->left = insert(node->left,data)
//     Return node;
// end
node* insertbst(struct node* root, int val){
    if(root == NULL) 
        root = new node(val);
    if(val > root->data) 
        root->right = insertbst(root->right, val);
    else if(val < root->data) 
        root->left = insertbst(root->left, val);
    return root;
}

node* deletebst(struct node* root, int val){
    if(root->data == val && root->left == NULL && root->right == NULL) 
        root = NULL;
    if(val > root->data) 
        root->right = deletebst(root->right, val);
    else if(val < root->data)
        root->left = deletebst(root->left, val);
    return root;
}

// ----------------------- utility function start
void printBT(const std::string& prefix, const struct node* root, bool isLeft)
{
    if( root != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << root->data << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}
void printBT(const struct node* root)
{
    printBT("", root, false);    
}

int main(){

    struct node* root = new node(5);
    root->left = new node(1);
    root->right = new node(7);

    printBT(root);

    // root = insertbst(root,11);
    // printBT(root);

    // root = insertbst(root,2);
    // printBT(root);

    // root = insertbst(root,3);
    // printBT(root);


    struct node* snode = searchbst(root,1);
    printBT(snode);              // Will print seg fault if u look up element no presnet in BST ,todo : handle case for errors
    cout<< snode->data;

    // When the tobe deleted node is a Leaf Node
    // root = deletebst(root,7);
    // printBT(root);

    // When the tobe deleted node has 1 child

    // When the tobe deleted node has 2 children

    return 0;
}

// g++ bst_insert_delete.cpp -o bst_insert_delete.out
// ./bst_insert_delete.out

// outout insert 

// └──5
//     ├──1
//     └──7
// └──5
//     ├──1
//     └──7
//         └──11
// └──5
//     ├──1
//     │   └──2
//     └──7
//         └──11
// └──5
//     ├──1
//     │   └──2
//     │       └──3
//     └──7
//         └──11