// Inorder , preorder and post order traversal in BT (binary tree) 
// 
// Created by @altanai on 31/03/21.
//

#include <iostream>
#include <queue>
using namespace std;

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
//     node(int val){
//         data=val;
//         left= NULL;
//         right = NULL;
//     }
// };


// struct MinHeapNode {
// 	char data;
// 	unsigned freq;
// 	struct MinHeapNode *left, *right;
// };

// Inorder is L -> Root -> R
// void inorder(MinHeapNode* root, std::vector<MinHeapNode*>& nodes){
//     if(root ==NULL) return ;
//     inorder(root->left, nodes); 
//     nodes.push_back(root);
//     inorder(root->right, nodes);
// }

// Inorder is L -> Root -> R
void inorder(node* root, int i, int orderarr[]){
    if(root ==NULL) return ;
    inorder(root->left, i, orderarr); 
    cout << root->data << " " ; orderarr[i]=root->data; i++;
    inorder(root->right, i, orderarr);
}

// Preorder is Root -> L -> R
int preorder(node* root, int i , int orderarr[]){
    if(root ==NULL) return;
    cout << root->data << " " ; orderarr[i]=root->data; i++;
    preorder(root->left ,i, orderarr); 
    preorder(root->right ,i, orderarr); 
}

// Postorder is  L -> R -> Root
int postorder(node* root, int i , int orderarr[]){
    if(root ==NULL) return;
    postorder(root->left,i, orderarr); 
    postorder(root->right,i, orderarr); 
    cout << root->data << " " ; orderarr[i]=root->data; i++;
}


int height(node *currnode ){
    if(currnode==NULL) return 0;
    return 1+ max(height(currnode-> left) , height(currnode->right));
}

void printq(queue<node*> q){
    queue<node*> qcopy = q;
    cout<<"\n print Queue ";
    while(!qcopy.empty()){
        cout << " \t " << qcopy.front();
        qcopy.pop();
    }
    cout << '\n';
}

void levelordertraversal(node* root, int i , int orderarr[]){
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
            cout << curr->data << " " ; orderarr[i]=curr->data; i++;
        }
    }

    printq(q);
}
