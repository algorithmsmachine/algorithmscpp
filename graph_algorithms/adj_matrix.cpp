#include<bits/stdc++.h>
using namespace std;


void printGraph(vector<int> adj[], int N){
    for (int i = 0; i < N; i++){
        cout << i << " ——> "; // print the current vertex number 
        for (auto v: adj[i]) 
            cout << v << " ";   // print all neighboring vertices of a vertex `i`
        cout << endl;
    }
}

void printMatrix(vector<vector<int>> adjmatrix){
    int V = adjmatrix.size();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjmatrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

// convert an adjacency list to the adjacency matrix
void addEdge(vector<int> adj[], int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void convertlist_matrix(vector<int> adj[],int V){
    vector<vector<int>> adjmatrix(V,vector<int>(V, 0));
    for(int i=0 ;i<V; i++){
        for(auto j:adj[i]){
            adjmatrix[i][j]=1;
        }
    }
    printMatrix(adjmatrix);
}


// convert an adjacency matrix to the adjacency list
void convertmatrix_list (vector<vector<int>> adjmatrix){
    int V = adjmatrix.size() ;
    vector<int> adjlist[V];
    for(int i=0 ;i<V; i++){
        for(int j =0; j<V; j++){
            if(adjmatrix[i][j]==1)
                adjlist[i].push_back(j);
        }
    }
    printGraph(adjlist,V);
    // return adjlist;
}


int main(){
    vector<vector<int>> adjmatrix;
    adjmatrix.push_back({0,0,1});
    adjmatrix.push_back({0,0,1});
    adjmatrix.push_back({1,1,0});
    // vector<int> adj= 
    convertmatrix_list(adjmatrix);
    
    // int V = 3;
    // vector<int> adj[V];
    // addEdge(adj,0,2);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);
    // addEdge(adj,2,1);

    int V = 4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,3,2);

    convertlist_matrix(adj,V);
    return 0;
}

// g++ adj_matrix.cpp -o adj_matrix.out 
// ./adj_matrix.out 
// 0 ——> 2 
// 1 ——> 2 
// 2 ——> 0 1