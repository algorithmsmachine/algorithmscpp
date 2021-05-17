// Inorder , preorder and post order traversal in BT (binary tree) 
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

int main() {

    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);

    printBT(root);

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
//  ./traversal.out
// output 
// └──1
//     ├──2
//     │   ├──3
//     │   └──4
//     └──5
//         ├──6
// Inorder traversal 3 2 4 1 6 5 
// Pre traversal 1 2 3 4 5 6 
// Post traversal 3 4 2 6 5 1