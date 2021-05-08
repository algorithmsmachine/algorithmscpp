// Insert new node in BT by level order 

// Note BST has order but BT has no order among elements

#include <iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node* left ;
    struct node* right;

    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

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

/* Inorder traversal of a binary tree */
 
void inorder(node* temp){
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// ----------------------- 

// iterative level order traversal in BT of the given tree using queue to find a node with a null child
node* insert_levelorder(node* root, int newdata){

    if(root == NULL){
        root = new node(newdata);// If the tree is empty, assign new node address to root
        return root;
    }

    queue<node*> q; // empty queue
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr->left) q.push(curr->left);
        else{
            curr->left = new node(newdata);
            return root;
        }
        
        if(curr->right) q.push(curr->right);
        else{
            curr->right = new node(newdata);
            return root;
        }
    }
}


// TBD : XX NOT working ok for innner nodes , woks ok for leave node 
// tree shrinks from bottom 
// deleted node is replaced by bottom most and rightmost node 
// not a bst, hence order is of no consequence 

// delete the deepest rightmost node 
void deleteDeepest(node* root, node* delnode){

    queue<node*> q; // empty queue
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr == delnode){
            curr = NULL;
            delete(delnode);
            return;
        }  

        if(curr->left){
            if(curr-> left == delnode){
                delete(delnode);
                return;
            }else{
                q.push(curr->left);
            }
        }
   
        if(curr->right){
            if(curr->right == delnode){
                curr->right=NULL;
                delete(delnode);
                return;
            }else{
                q.push(curr->right);
            }
        }
    }
}


// find nod to be deleted
node* delete_levelorder(node* root, int deldata){

    if(root == NULL){
        return root;
    }

    node* delnode;
    queue<node*> q; // empty queue
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr->data == deldata)  delnode=curr;

        if(curr->left) q.push(curr->left);
        
        if(curr->right) q.push(curr->right);
    }

    if(delnode !=NULL ){ // if the node to be deleted is found , then replace with deepest and rightmost  node
        int temp = delnode->data;
        deleteDeepest(root, delnode);
        delnode->data = temp;
    }
    return root;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    // root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);

    cout << "\n  Before \n";
    printBT(root);

    insert_levelorder(root,11);

    cout << "\n  After \n";
    printBT(root);

    delete_levelorder(root,5);

    cout << "\n  After deletion \n";
    printBT(root);

    return 0;
}

// g++ insertion_bt.cpp -o insertion_bt.out
//  ./insertion_bt.out   

// Outout: 
//   Before 
// └──1

//   After 
// └──1
//     ├──11



//   Before 
// └──1
//     ├──2
//     │   └──4
//     └──5
//         ├──6

//   After 
// └──1
//     ├──2
//     │   ├──11
//     │   └──4
//     └──5
//         ├──6