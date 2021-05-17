// Maximum Width of a Binary Tree using recussion
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
        left=NULL;
        right=NULL;
    }
};

// Input: BT
// Output : Height of whole BT
int height(node* root){
    if(root==NULL) return 0;
    return 1+ max(height(root->left),height(root->right));
}

// Width of a specific level
// Input : tree and level of tree to count width of
// output : width of a given level
int levelwidth(node*root,int level){
    if(root==NULL) return 0;
    if(level==1) return 1;
    return levelwidth(root->left, level-1)+levelwidth(root->right,level-1);
}

// Maximum width of whole tree
// Input : BT root 
// Output : max width of whole BT
int maxwidth(node* root){
    int maxw=0;
    for(int i=1;i<=height(root);i++){
        int w=levelwidth(root,i);
        if(w>maxw) maxw=w;
    }
    return maxw;
}

// ----------------------- utility function start
void printBT(const std::string& prefix, const struct node* root, bool isLeft){
    if( root != nullptr ){
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        std::cout << root->data << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
    }
}
void printBT(const struct node* root){
    printBT("", root, false);    
}

int main(){
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(4);
    root->right->left=new node(5);
    root->right->right=new node(6);

    printBT(root);

    cout << "\n height " << height(root);
    cout << "\n max Width of BT " << maxwidth(root)<< endl;
    return 0;
}

//  g++ maxwidth_bt.cpp -o maxwidth_bt.out
//  ./maxwidth_bt.out

// output
// └──1
//     ├──2
//     │   ├──4
//     │   └──4
//     └──3
//         ├──5
//         └──6

//  height 3
//  max Width of BT 4