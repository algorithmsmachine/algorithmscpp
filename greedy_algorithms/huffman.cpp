// C++ Program for Huffman Coding
// using Priority Queue
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include<map>
using namespace std;

// Maximum Height of Huffman Tree.
#define MAX_SIZE 100

class Node {
public:
	char data;
	double freq;
	Node* left;
	Node* right;

Node(char character,	double frequency)
	{
		data = character;
		freq = frequency;
		left = right = NULL;
	}
};

// Custom comparator class
class Compare {
public:
	bool operator()(Node* a,
					Node* b)
	{
		// Defining priority on the basis of frequency
		return a->freq > b->freq;
	}
};

// Function to generate Huffman
// Encoding Tree
Node* generateTree(priority_queue<Node*,
							vector<Node*>,
											Compare> pq)
{

	// We keep on looping till
	// only one node remains in
	// the Priority Queue
	while (pq.size() != 1) {

		// Node which has least
		// frequency
		Node* left = pq.top();

		// Remove node from
		// Priority Queue
		pq.pop();

		// Node which has least
		// frequency
		Node* right = pq.top();

		// Remove node from
		// Priority Queue
		pq.pop();

		// A new node is formed
		// with frequency left->freq
		// + right->freq

		// We take data as '$'
		// because we are only
		// concerned with the
		// frequency
		Node* node = new Node('$',
								left->freq + right->freq);
		node->left = left;
		node->right = right;

		// Push back node
		// created to the
		// Priority Queue
		pq.push(node);
	}

	return pq.top();
}

// Function to print the
// huffman code for each
// character.

// It uses arr to store the codes
void printCodes(Node* root,	int arr[], double freq[],  int top, map<string,string> &codes)
{
	
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left,	arr, freq, top + 1, codes);  // Assign 0 to the left node  and recur
	}

	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, freq, top + 1, codes);  // Assign 1 to the right node and recur
	}

	// If this is a leaf node, then we print root->data
	if (!root->left && !root->right) {
		cout << root->data <<  "\t"  <<  root->freq << "\t" ;
		string key(1, root->data) ;
		for (int i = 0; i < top; i++) {
			codes[key]+= to_string(arr[i]);
		}
		cout << codes[key] <<"\n";
	}
}

int isLeaf(struct Node* root){
	return !(root->left) && !(root->right);
}

void printtree(struct Node* root, int indent = 0, string prefix = ""){
	int INDENT_SIZE = 4;
    if (root == NULL) {
        return;
    }

    char letter = ' ';
    if (isLeaf(root)) {
        letter = root->data;
    }

    cout << string(indent, ' ') << prefix << "(" << letter << " [" << root->freq << "]";
    if (isLeaf(root)) {
        cout << ")" << endl;
    } else {
        cout << endl;
        printtree(root->left, indent + INDENT_SIZE, "0");
        printtree(root->right, indent + INDENT_SIZE, "1");
        cout << string(indent, ' ') << ")" << endl;
    }
}

void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
 
    // found a leaf node
    if (isLeaf(root)){
        cout << root->data;
        return;
    }
 
    index++;
 
    if (str[index] == '0') {
        decode(root->left, index, str);
    }
    else {
        decode(root->right, index, str);
    }
}


void HuffmanCodes(char data[], double freq[], int size,  map<string,string> &codes){
	// Declaring priority queue
	priority_queue<Node*,vector<Node*>,Compare> pq;

	// Populating the priority queue
	for (int i = 0; i < size; i++) {
		Node* newNode = new Node(data[i], freq[i]);
		pq.push(newNode);
	}

	// Make Huffman Encoding Tree and get the root node
	Node* root = generateTree(pq);

	int arr[MAX_SIZE], top = 0;

	// map<string,string> codes;
	printCodes(root, arr, freq, top, codes);
    printtree(root);


	string decodestr = "100010111001010";
	cout << "\n decoded string" << decodestr << " is ";
	int index = -1;
	while (index < (int)decodestr.size() - 2) {
		decode(root, index, decodestr);
	}
	cout << endl;
}

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr) {
        return;
    }
 
    if (isLeaf(root)) {
        huffmanCode[root->data] = (str != "") ? str : "1";
    }
 
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
 

int main()
{
	// char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	// int freq[] = { 5, 9, 12, 13, 16, 45 };

    // char arr[] 	  = { 'A', 'B', 'C', 'D', '_' };
	// double freq[] = { 0.4, 0.1, 0.2, 0.15, 0.15 };

    char arr[] 	  = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','H'};
	double freq[] = { 1/30, 1/30, 1/30, 2/30, 3/30 ,5/30, 5/30, 12/30  };

	int size = sizeof(arr) / sizeof(arr[0]);

    map<string,string> codesmap;
    map<string,int>::iterator itr;
	HuffmanCodes(arr, freq, size, codesmap);

	// for (auto& v : codes)
    // 	cout << v.first << ", " << v.second << endl;
		
	for (auto const &pair: codesmap) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }


	// cout << " Encoded code"; 
    string encodedStr= "ABACABAD";
	string str = "";
	for (auto i: encodedStr) {
		string k(1, i) ;
		cout << k ;
		if ( codesmap.find(k) == codesmap.end() ) {
			// cout << "not found";
		} else {
			str += codesmap.find(k)->second;
		}
	}
	cout << "\nEncoded string is :\n" << str << '\n';


	return 0;
}

//  g++ huffman.cpp -o huffman.out 
// ./huffman.out                  

// output
// a       0.4     0
// b       0.1     100
// d       0.15    101
// _       0.15    110
// c       0.2     111
// (  [1]
//     0(a [0.4])
//     1(  [0.6]
//         0(  [0.25]
//             0(b [0.1])
//             1(d [0.15])
//         )
//         1(  [0.35]
//             0(_ [0.15])
//             1(c [0.2])
//         )
//     )
// )