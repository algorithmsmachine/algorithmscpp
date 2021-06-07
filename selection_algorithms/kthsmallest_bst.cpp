#include<iostream>
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

// Recursive function to insert an key into BST
node* insert(node* root, int x){
    if (root == NULL)
        return new node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
 

// Approach 1 : Inorder Traversal (O(n) time and O(h) auxiliary space)  
 node* kthsmallest( node* root, int &kth){
    if(root==NULL) return NULL;

    node* left= kthsmallest(root->left , kth);
    if(left !=NULL)                       // search in left subtree
        return left;
    
    kth--;
    if(kth == 0)
        return root;

    return kthsmallest(root->right, kth); // else search in right subtree
}

// Sum of elements from min node to the kth smallest element
int sum_kthsmallest(node* root, int &kth, int &i){
    if(root==NULL) return 0;
    if(i>kth)   return 0;
    
    int sum = sum_kthsmallest(root->left , kth, i);
    sum += root->data;
    i++;

    if(i>=kth)
        return sum;

    return sum + sum_kthsmallest(root->right, kth, i); // else search in right subtree
}

int main(){
    // struct node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->right->right = new node(7);
    // root->right->right->right = new node(3);

    struct node* root = NULL;
    int arr[] = { 20, 8, 22, 4, 12, 10, 14 };
 
    for (int x : arr)
        root = insert(root, x);

    int kth =3;
    cout<< " smallest Kth element " << kthsmallest(root,kth)->data;

    int counter =0;
    cout<< " Sum untill smallest Kth element " << sum_kthsmallest(root, kth, counter);
}