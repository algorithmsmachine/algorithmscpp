//  Prim's Minimum Spanning Tree (MST)

#include <bits/stdc++.h>
using namespace std;

#define V 6
#define INF 9999

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V], string path[]){
	cout<<"Edge \t Path \t  Weight\n";
    int totalcost=0;
	for (int i = 1; i < V; i++){
		cout<< parent[i] <<" - "<< i <<" \t" << path[i] <<" \t" << graph[i][parent[i]] <<" \n";
        totalcost += graph[i][parent[i]];
    }
    cout << " total cost "<< totalcost<< endl;
}


void primMST(int graph[V][V])
{
	int parent[V];      // store constructed MST 
	string path[V];     // path to vertex
	int key[V];         // Key values used to pick minimum weight edge in cut

	bool mstSet[V];    // set of vertices included in MST 

	for (int i = 0; i < V; i++)
		key[i] = INF, mstSet[i] = false; // Initialize all keys as INFINITE

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	for (int count = 0; count < V - 1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;                       // visited 

		for (int v = 0; v < V; v++)
			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){        // go over not vidited vertices 
				parent[v] = u, key[v] = graph[u][v];    
                path[v] = path[u] + ' ' + to_string(u); 
            }
	}

	// print the constructed MST
	printMST(parent, graph, path);
}

// Driver code
int main()
{
	int graph[V][V] = { { INF, 1, 1, 5, INF, INF },
						{ 1, INF, 1, INF, 1, 4 },
						{ 1, 1, INF, 6, 2 , INF},
						{ 5, INF, 6, INF, INF , 7 },
						{ INF, 1, 2, INF , INF , 3 },
                        { INF , 4, INF , 7, 3, INF} };
	primMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra
