#include<iostream>
#include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/printBT.cpp>
#include <queue>
using namespace std;

// #include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/delete_insert.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left= NULL;
        right = NULL;
    }
} node;

#include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/traversal.h>

// ----------------------- utility function insertbst and deletebst
struct node* insertbst(struct node* root, int val){
    if(root == NULL) 
        root = new node(val);
    if(val > root->data) 
        root->right = insertbst(root->right, val);
    else if(val < root->data) 
        root->left = insertbst(root->left, val);
    return root;
}
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* deletebst(struct node* root, int key){
    if (root == NULL) return root;
 
    if (key < root->data)
        root->left = deletebst(root->left, key);
    else if (key > root->data)
        root->right = deletebst(root->right, key);
    else {
        if (root->left==NULL ){
            struct node* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletebst(root->right, temp->data);
    }
    return root;
}

// ----------------------- utility function array  to BST
// pointer to pointer 
// first pointer is used to store the address of the variable. 
// And the second pointer is used to store the address of the first pointer. 
// use : To retain change in the Memory-Allocation or Assignment even outside of a function call 
void insert(node ** root, int val){
    if(*root == NULL)
        *root = new node(val);
    else if((*root)->data <= val)
        insert(&((*root)->right), val);
    else if((*root)->data > val)
        insert(&((*root)->left), val);
}
node* getBST(int *arr, int n){
    node * root = NULL;
    for(int i = 0; i < n; i++)
        insert(&root, arr[i]);
    return root;
}
// void inorderbst(node * root, int i, int arr[]){
//     if(root && root->left) inorderbst(root->left, i++, arr);
//     if(root){
//          std::cout<<root->data<<" , ";
//          arr[i]=root->data;
//     }
//     if(root && root->right) inorderbst(root->right, i++, arr);
// }



// ----------------------- utility function printBT
void printBT(const std::string& prefix, const struct node* root, bool isLeft){
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



// ----------------------- main
int main()
{
    // int arr[] = {10,5,15,5,6,7,8,89};
    // int arr[] = {28,39,2,17,56,10,30,5,12,85,64};
    int arr[]={10,3,12,1,7,11,14,13,15};
    int n = sizeof(arr)/sizeof(arr[0]);

    BinTree<int> bt;
    for(int j=0;j<n;j++)  
        bt.insert(arr[j]);
    cout << "Tree from OP:\n\n";
    bt.Dump();
    cout << "\n\n";
    bt.clear();

    struct node * root = getBST(arr, n);

    cout << "\n inorder ";
    inorder(root);

    cout << "\n postorder ";
    postorder(root);

    cout << "\n preorder ";
    preorder(root);
    cout<<endl;


    // int arr2[n];
    root  = deletebst(root, 3);
    root  = deletebst(root, 12);
    root  = deletebst(root, 10);
    // printBT(root);
    
    root = insertbst(root,2);
    root = insertbst(root,21);

    cout<< "\n level order tarversal ";
    levelordertraversal(root, 0 , arr); 
    BinTree<int> bt2;
    for(int j=0;j<n;j++)  
        bt2.insert(arr[j]);
    cout << "\n Balanced BST :\n\n";
    bt2.Dump();
    cout << "\n\n";
    bt2.clear();

    return 0;
}