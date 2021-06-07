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

bool isidentical(struct node * root1 , struct node * root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL) return false;
    if(root2==NULL) return false;
    if(root1->data != root2->data) return false;
    return isidentical(root1->left,root2->left) && isidentical(root1->right, root2->right);
}

int main(){
    struct node* root1 = new node(10);
    root1->left = new node(30);
    root1->right = new node(15);

    struct node* root2 = new node(10);
    root2->left = new node(30);
    root2->right = new node(15);

    cout << isidentical(root1,root2);

}