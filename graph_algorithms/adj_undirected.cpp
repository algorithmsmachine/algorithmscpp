#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void addEdge(vector<int> adj[], int u, int v ){
    adj[u].push_back(v);
    adj[v].push_back(u); // for directed remove this
}


void printGraph(vector<int> adj[], int N){
    for (int i = 0; i < N; i++){
        cout << i << " ——> "; // print the current vertex number 
        for (auto v: adj[i]) 
            cout << v << " ";   // print all neighboring vertices of a vertex `i`
        cout << endl;
    }
}

int main(){

    int V=5;
    vector<int> adj[V];
    // Graph g = new Graph(adj,0,4);
    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,3);
    // addEdge(adj,2,4);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj,V);
    return 0;
}

// g++ adj_undirected.cpp -o adj_undirected.out
// ./adj_undirected.out

// output Un-directed 
// 0 ——> 1 4 
// 1 ——> 0 2 3 4 
// 2 ——> 1 3 
// 3 ——> 1 2 4 
// 4 ——> 0 1 3

// output directed 
// 0 ——> 1 4 
// 1 ——> 2 3 4 
// 2 ——> 3 
// 3 ——> 4 
// 4 ——> 