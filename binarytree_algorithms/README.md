# Binary Tree operations 


**using stucts instead of class for creating binary tree**

Although even classes can be sued for creating teh nodes, I use structs often.

    class Node {
    public:
        int data;
        Node *left, *right;
        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };

or 

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

Structs are value type whereas Classes are reference type. Structs are stored on the stack whereas Classes are stored on the heap. ... When you copy struct into another struct, a new copy of that struct gets created modified of one struct won't affect the value of the other struct.

**YTraversing the binary tree, using queue based ietration vs recussion**

For simple operatiosn such as level order traversal or min , max while have O(n) class efificieny either approach is good . 
I Use ietraion for simple operations where I know all n elemenst will be toughed such as height or tree , width of tree .

For operations like inorder, post order, preorder , either can be used . 

For serach or sort operations however, it is better to adopt recussion since code looks much cleaner.
