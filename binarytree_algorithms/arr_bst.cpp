#include<iostream>
using namespace std;
#include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/printBT.cpp>
struct node{
    int data;
    struct node* left;
    struct node* right;
    node( int val){
        data = val;
        left = NULL;
        right= NULL;
    }
};
void addEdge(struct node* root , int key){
    if(root == NULL){
        root = new node(key);
    }else if(key > root->data){
         addEdge(root->right, key);
    }else{
         addEdge(root->left, key);
    }
}

#include</home/altanai/Documents/algorithms/algorithmscpp/binarytree_algorithms/levelordertraversal.cpp>


int main(){
    int arr[]={5,7,3,6,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct node* root= new node(arr[0]);
    for(int i=1;i<n;i++){
        addEdge(root,arr[i]);
    }

    cout<< "\n level order tarversal ";
    levelordertraversal(root, 0 , arr); 
    BinTree<int> bt2;
    for(int j=0;j<n;j++)  
        bt2.insert(arr[j]);
    cout << "\n Balanced BST :\n\n";
    bt2.Dump();
    cout << "\n\n";
    bt2.clear();

}

//  g++ arr_bst.cpp -o arr_bst.out
//  ./arr_bst.out                

// Output
//  level order tarversal  height 1
// 5 
//  print Queue     0

//  Balanced BST :

//     5
//    / \
//   3   7
//  2   6 9