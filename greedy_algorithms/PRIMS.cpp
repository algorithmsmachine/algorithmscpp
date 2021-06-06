//  Prim's Minimum Spanning Tree (MST)

#include <bits/stdc++.h>
using namespace std;

#define V 6
#define INF 9999

// class Graph {
// public:
//     int vertexNum;
//     int **edges;

//     Graph(const int V) {
//         this->edges = new int *[V]; // initializes the array edges.
//         for (int i = 0; i < V; i++) {
//             edges[i] = new int[V];
//         }

//         for (int i = 0; i < V; i++) { // fills the array with zeros.
//             for (int j = 0; j < V; j++) {
//                 edges[i][j] = 0;
//             }
//         }
//         this->vertexNum = V;
//     }

//     void addEdge(char source, char destination, int weight, map<char,int> mp) {
//         int src = mp.find(source)->second;
//         int dst = mp.find(destination)->second;
//         this->edges[src][dst] = weight;
//     }

//     // overload with adj[]
//     void addEdge(vector<int> adj[],char source, char destination, int weight, map<char,int> mp) {
//         int src = mp.find(source)->second;
//         int dst = mp.find(destination)->second;
//         adj[src].push_back(dst);
//         this->edges[src][dst] = weight;
//     }
// };

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void printMST(int parent[], int graph[V][V], string path[]){
	cout<<"Edge \t Path \t  Weight\n";
    int totalcost = 0;
	for (int i = 0; i < V; i++){
		cout<< parent[i] <<" - "<< i <<" \t" << path[i] <<" \t" << graph[i][parent[i]] <<" \n";
        totalcost += graph[i][parent[i]];
    }
    cout << " total cost "<< totalcost<< endl;
}
void primMST(int graph[V][V]){
	int parent[V];      
	string path[V];     
	int key[V];         
	bool mstSet[V];    
	for (int i = 0; i < V; i++)
		key[i] = INF, mstSet[i] = false; 
	key[0] = 0;
	parent[0] = -1;                     // First node is always root of MST
	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;                       // visited 
		for (int v = 0; v < V; v++)
			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){        // go over not vidited vertices 
				parent[v] = u, key[v] = graph[u][v];    
                path[v] = path[u] + ' ' + to_string(u); 
            }
	}
	printMST(parent, graph, path);
}


// void printMST(int parent[], vector<vector<int>> graph, string path[]){
// 	cout<<"Edge \t Path \t  Weight\n";
//     int totalcost = 0;
// 	for (int i = 0; i < graph.size(); i++){
// 		cout<< parent[i] <<" - "<< i <<" \t" << path[i] <<" \t" << graph[i][parent[i]] <<" \n";
//         // cout<<graph[i][2] << "\n";
//         totalcost += graph[i][parent[i]];
//     }
//     cout << " total cost "<< totalcost<< endl;
// }
// void primMST(vector<vector<int>> graph){
//     int V = graph.size();
// 	int parent[V];      
// 	string path[V];     
// 	int key[V];         
// 	bool mstSet[V];    
// 	for (int i = 0; i < V; i++)
// 		key[i] = INF, mstSet[i] = false; 
// 	key[0] = 0;
// 	parent[0] = -1; // First node is always root of MST
// 	for (int count = 0; count < V - 1; count++){
// 		int u = minKey(key, mstSet, V);
// 		mstSet[u] = true;                       // visited 
// 		for (int v = 0; v < V; v++)
// 			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){        // go over not vidited vertices 
// 				parent[v] = u, key[v] = graph[u][v];    
//                 path[v] = path[u] + ' ' + to_string(u); 
//             }
// 	}
// 	printMST(parent, graph, path);
// }


// void printMatrix(vector<vector<int>> adjmatrix){
//     int V = adjmatrix.size();
//     for (int i = 0; i < V; i++) {
//         for (int j = 0; j < V; j++) {
//             cout << adjmatrix[i][j] << "   ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }
// void convertlist_matrix(vector<int> adj[], int V, vector<vector<int>> adjmatrix){
//     for(int i=0 ;i<V; i++){
//         for(auto j:adj[i]){
//             adjmatrix[i][j]=1;
//         }
//     }
//     printMatrix(adjmatrix);
// }


int main(){
   
	int graph[V][V] = { { INF, 1, 1, 5, INF, INF },
						{ 1, INF, 1, INF, 1, 4 },
						{ 1, 1, INF, 6, 2 , INF},
						{ 5, INF, 6, INF, INF , 7 },
						{ INF, 1, 2, INF , INF , 3 },
                     { INF , 4, INF , 7, 3, INF} };

    cout << "\n PRIMS ";
	primMST(graph);

    // int V = 5;
    // map<char,int> mp;
    // map<char,int>::iterator itr;
    // mp['A']=0;
    // mp['B']=1;
    // mp['C']=2;
    // mp['D']=3;
    // mp['E']=4;

    // Graph G(V);
    // vector<int> adj[V];
    // G.addEdge(adj, 'A', 'B', 2, mp);
    // G.addEdge(adj, 'A', 'C', 1, mp);

    // G.addEdge(adj, 'B', 'C', 1, mp);

    // G.addEdge(adj, 'C', 'A', 9, mp);
    // G.addEdge(adj, 'C', 'D', 8, mp);
    // G.addEdge(adj, 'C', 'E', 2, mp);

    // G.addEdge(adj, 'D', 'A', 3, mp);

    // G.addEdge(adj, 'E', 'D', 3, mp);

    // // Adj matrix from adj list 
    // vector<vector<int>> adjmatrix(V,vector<int>(V, INF));
    // convertlist_matrix(adj,V,adjmatrix);

    // cout << "\n PRIMS ";
	// primMST(adjmatrix);

	return 0;
}

// This code is contributed by rathbhupendra
