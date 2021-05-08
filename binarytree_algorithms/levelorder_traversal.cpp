// print the level order traversal of a BST 

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

int height(node *currnode ){
    if(currnode==NULL) return 0;
    return 1+ max(height(currnode-> left) , height(currnode->right));
}


// Approach2 : iterative level order traversal , print BT from queue

// insert the root and a null element into the queue ( null element acts as a delimiter). 
// Next pop from the top of the queue and add its left and right nodes to the end of the queue and then print the top of the queue. 
// Continue this process till the queues become empty. 

void printq(queue<node*> q){
    queue<node*> qcopy = q;
    cout<<"\n print Queue ";
    while(!qcopy.empty()){
        cout << " \t " << qcopy.front();
        qcopy.pop();
    }
    cout << '\n';
}

void levelordertraversal(node* root){
    int h = height(root);
    cout << " height "<< h << endl;

    if(root == NULL ) return;

    queue<node*> q; // empty queue
    node* curr; // node to store front element 

    q.push(root);
    q.push(NULL);

    while(q.size()>1){
        curr = q.front();
        q.pop();

        if(curr ==NULL){
            q.push(NULL);
            cout << "\n";
        }else{
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            cout << curr->data << " ";
        }
    }

    printq(q);
}

//approach 1 : Recursive level order traversal , print keys 
// void levelorderprint(node* root , int level){
//     if(root==NULL) return;
//     if(level==1){
//          cout << root->data << " ";
//     }else if(level>1){
//         levelorderprint(root->left, level-1);
//         levelorderprint(root->right, level -1);
//     }
// }

// void levelordertraversal(node* root){
//     int h = height(root);
//     cout << " height "<< h << endl;
//     for( int i=1 ;i<= h ;i++){
//         levelorderprint(root,i);
//         cout<<endl;
//     }
// }

int main() {
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    cout << "BST ";
    levelordertraversal(root);
    return 0;
}

// g++ levelorder_traversal.cpp -o levelorder_traversal.out 
// ./levelorder_traversal.out  
// output 
//BST  height 3
//1 
//2 5 
//3 4 6 