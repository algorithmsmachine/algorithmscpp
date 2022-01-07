#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxHeight(struct TreeNode *root)
{
    if(root == NULL)
        return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;

}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->val = 1;
    p->left = NULL;
    p->right = NULL;
    // TreeNode *q = (TreeNode *)malloc(sizeof(TreeNode));
    // q->val = 1;
    // q->left = NULL;
    // q->right = NULL;
    // printf("%d\n", isSameTree(p, q));
    printf("%d\n", maxHeight(p));
    return 0;
}