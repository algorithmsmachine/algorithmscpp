// DFS ( Depth First Serach/Traversal) in Un-Directed graph
// using adjacency list 
//
// Created by @altanai on 31/03/21.
//
// Graph represendted by STL

// DFS - depth-first search traversal 

// Input : Graph G = V , E
// Output : Graph G with its vertices marked with consecutive integers in order of encoounter

// Algo : 

// all vetex unvisited 1 
// counter <-0
// for each v in V do 
//      if v ismarked 0 
//          dfs(v)

// dfs(v)
// count <- count+1 ; mark w with counter 
// for each w in vadj  do 
//      if w ismarked 0
//          dfs(w)

// traversal time by adjacency matrix - theta (|V | 2 ),  
// for the adjacency list theta (|V | + |E|) 

#include<bits/stdc++.h>
using namespace std;

// do DFS traversal among adj which are non visisted 
void dfstraversal(int u, vector<int> adj[], vector<bool> &visited){
    visited[u]=true;
    cout << u <<" ";
    for(int i=0; i<adj[u].size(); i++){
        if(visited[adj[u][i]]==false)
            dfstraversal(adj[u][i], adj, visited);
    }
}

// DFS for all unvisited vertices
void dfs(vector<int>adj[], int V){
    vector<bool> visited(V, false);
    for( int u=0; u<V; u++){
        if(visited[u]==false)
            dfstraversal(u, adj, visited);
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);   // for directed comment this line 
}

void printGraph(vector<int> adj[],int V){
    for (int i = 0; i < V; i++){
        cout << i << " ——> "; // print the current vertex number 
        for (auto v: adj[i]) 
            cout << v << " ";   // print all neighboring vertices of a vertex `i`
        cout << endl;
    }
}

int main(){
    int V=5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // printGraph(adj,V);

    dfs(adj,V);

    return 0;
}

// g++ dfs_undirected.cpp -o dfs.out
// ./dfs.out

// Output
// 0 ——> 1 4 
// 1 ——> 2 3 4 
// 2 ——> 3 
// 3 ——> 4 
// 4 ——> 
// 0 1 2 3 4 % 