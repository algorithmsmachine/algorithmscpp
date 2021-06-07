#include <queue>
// ----------------------- utility function level order traversal
int height(node *root ){
    if(root==NULL) return 0;
    return 1+ max(height(root-> left) , height(root->right));
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
