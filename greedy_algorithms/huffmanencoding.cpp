// // Huffman Coding
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// NOT WORKINH FOR DOUBLE , ONLY WORKS FOR INT 

// // This constant can be avoided by explicitly calculating height of Huffman Tree
// #define MAX_TREE_HT 100

// // Huffman tree node
// struct MinHeapNode {
// 	char data;
// 	double freq;
// 	struct MinHeapNode *left, *right;
// };

// // A Min Heap: Collection of
// // min-heap (or Huffman tree) nodes
// struct MinHeap {
// 	unsigned size; 	// Current size of min heap
// 	unsigned capacity; 	// capacity of min heap
// 	struct MinHeapNode** array; // arr for minheap node pointers
// };

// // New min heap node with given character and frequency of the character
// struct MinHeapNode* newNode(char data, unsigned freq)
// {
// 	struct MinHeapNode* temp = (struct MinHeapNode*)malloc (sizeof(struct MinHeapNode));

// 	temp->left = temp->right = NULL;
// 	temp->data = data;
// 	temp->freq = freq;

// 	return temp;
// }

// // Make a min-heap of given capacity
// struct MinHeap* createMinHeap(unsigned capacity){

// 	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
// 	minHeap->size = 0;
// 	minHeap->capacity = capacity;
// 	minHeap->array = (struct MinHeapNode**)malloc(minHeap-> capacity * sizeof(struct MinHeapNode*));
// 	return minHeap;
// }

// // swap two min-heap nodes
// void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
// 	struct MinHeapNode* t = *a;
// 	*a = *b;
// 	*b = t;
// }

// // minHeapify function.
// void minHeapify(struct MinHeap* minHeap, int idx){
// 	int smallest = idx;
// 	int left = 2 * idx + 1;
// 	int right = 2 * idx + 2;

// 	if (left < minHeap->size && minHeap->array[left]-> freq < minHeap->array[smallest]->freq)
// 		smallest = left;

// 	if (right < minHeap->size && minHeap->array[right]-> freq < minHeap->array[smallest]->freq)
// 		smallest = right;

// 	if (smallest != idx) {
// 		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
// 		minHeapify(minHeap, smallest);
// 	}
// }

// // check if size of heap is 1 or not
// int isSizeOne(struct MinHeap* minHeap){
// 	return (minHeap->size == 1);
// }

// // extract minimum value node from heap
// struct MinHeapNode* extractMin(struct MinHeap* minHeap){
// 	struct MinHeapNode* temp = minHeap->array[0];
// 	minHeap->array[0] = minHeap->array[minHeap->size - 1];
// 	--minHeap->size;
// 	minHeapify(minHeap, 0);
// 	return temp;
// }

// // insert a new node to Min Heap
// void insertMinHeap(struct MinHeap* minHeap,
// 				struct MinHeapNode* minHeapNode){
// 	++minHeap->size;
// 	int i = minHeap->size - 1;
// 	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
// 		minHeap->array[i] = minHeap->array[(i - 1) / 2];
// 		i = (i - 1) / 2;
// 	}
// 	minHeap->array[i] = minHeapNode;
// }

// // build min heap
// void buildMinHeap(struct MinHeap* minHeap){
// 	int n = minHeap->size - 1;
// 	int i;
// 	for (i = (n - 1) / 2; i >= 0; --i)
// 		minHeapify(minHeap, i);
// }

// void printArr(int arr[], int n){
// 	int i;
// 	for (i = 0; i < n; ++i)
// 		cout<< arr[i];

// 	cout<<"\n";
// }

// //  check if this node is leaf
// int isLeaf(struct MinHeapNode* root){
// 	return !(root->left) && !(root->right);
// }

// // Creates a min heap of capacity equal to size and inserts all character of data[] in min heap. 
// struct MinHeap* createAndBuildMinHeap(char data[], double freq[], int size){
// 	struct MinHeap* minHeap = createMinHeap(size);
// 	for (int i = 0; i < size; ++i)
// 		minHeap->array[i] = newNode(data[i], freq[i]);

// 	minHeap->size = size;
// 	buildMinHeap(minHeap);

// 	return minHeap;
// }

// // builds Huffman tree
// struct MinHeapNode* buildHuffmanTree(char data[], double freq[], int size){
// 	struct MinHeapNode *left, *right, *top;

// 	// Step 1: Create a min heap of capacity equal to size. 
// 	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

// 	// Iterate while size of heap doesn't become 1
// 	while (!isSizeOne(minHeap)) {

// 		// Step 2: Extract the two minimum freq items from min heap
// 		left = extractMin(minHeap);
// 		right = extractMin(minHeap);

// 		// Step 3: Create  node with frequency equal to the sum of the two nodes frequencies.
// 		// Make the two extracted node as left and right children of this new node.
// 		// Add this node to the min heap with '$' special value for internal nodes, not used
// 		top = newNode('$', left->freq + right->freq);

// 		top->left = left;
// 		top->right = right;

// 		insertMinHeap(minHeap, top);
// 	}

// 	// Step 4: return root node and the tree is complete.
// 	return extractMin(minHeap);
// }

// void printCodes(struct MinHeapNode* root, int arr[], int top){

// 	if (root->left) {
// 		arr[top] = 0;			// Assign 0 to left edge and recur
// 		printCodes(root->left, arr, top + 1);
// 	}

// 	if (root->right) {
// 		arr[top] = 1;			// Assign 1 to right edge and recur
// 		printCodes(root->right, arr, top + 1);
// 	}

// 	// If this is a leaf node, then	 it contains one of the input characters, 
// 	// print the character and its code from arr[]
// 	if (isLeaf(root)) {
// 		cout<< root->data <<": ";
// 		printArr(arr, top);
// 	}
// }

// void printtree(struct MinHeapNode* root, int indent = 0, string prefix = ""){
// 	int INDENT_SIZE = 4;
//     if (root == NULL) {
//         return;
//     }

//     char letter = ' ';
//     if (isLeaf(root)) {
//         letter = root->data;
//     }

//     cout << string(indent, ' ') << prefix << "(" << letter << " [" << root->freq << "]";
//     if (isLeaf(root)) {
//         cout << ")" << endl;
//     } else {
//         cout << endl;
//         printtree(root->left, indent + INDENT_SIZE, "0");
//         printtree(root->right, indent + INDENT_SIZE, "1");
//         cout << string(indent, ' ') << ")" << endl;
//     }
// }

// void HuffmanCodes(char data[], double freq[], int size){
	
// 	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); // Huffman Tree
// 	int arr[MAX_TREE_HT], top = 0; 	
// 	printCodes(root, arr, top);							// Print Huffman codes 

// 	printtree(root);
// 	// std::vector<MinHeapNode*> nodes;  
// 	// inorder(root, nodes);
// 	// double* inorderarr = &nodes[0];

// 	// BinTree<int> bt;
//     // bt.insert(inorderarr);
//     // cout << "Tree from OP:\n\n";
//     // bt.Dump();
//     // cout << "\n\n";
//     // bt.clear();

// }

// // Driver code
// int main(){
// 	// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
// 	// int freq[] = { 5, 9, 12, 13, 16, 45 };

// 	// char arr[] 	  = { 'm', 'p', 's', 'i' };
// 	// double freq[] = { 1, 2 ,4, 4 };

// 	// char arr[] 	  = { 'm', 'p', 's', 'i' };
// 	// double freq[] = { 0.1, 0.2 ,0.4, 0.4 };

// 	char arr[] 	  = { 'a', 'b', 'c', 'd', '_' };
// 	double freq[] = { 0.4, 0.1, 0.2, 0.15, 0.15 };

// 	int size = sizeof(arr) / sizeof(arr[0]);

// 	HuffmanCodes(arr, freq, size);

// 	return 0;
// }
