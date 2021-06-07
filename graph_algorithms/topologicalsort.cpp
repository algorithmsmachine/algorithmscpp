// Topological sort 
// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices in order of dependency
// cannot be applied on DAG
#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<stack>
using namespace std;

// Time Complexity: O(V+E)- this is just a  DFS with an extra stack. So time complexity is the same as DFS 
// Auxiliary space: O(V) -  The extra space is needed for the stack. 

// do DFS traversal among adj which are non visisted 
void dfstraversal(int u, vector<int> adj[], vector<bool> &visited, stack<int> &stk){
    visited[u]=true;
    // cout << u <<" ";
    for(int i=0; i<adj[u].size(); ++i){
        if(!visited[adj[u][i]])
            dfstraversal(adj[u][i], adj, visited, stk);
    }
    stk.push(u);
}

// DFS for all unvisited vertices
void dfs(vector<int>adj[], int V){
    vector<bool> visited(V, false);
    stack<int> stk; 
    for( int u=0; u<V; u++){
        if(visited[u]==false)
            dfstraversal(u, adj, visited, stk);
    }

    // print contents of stack 
    while(!stk.empty()){
        cout<< stk.top()<<" ";
        stk.pop();
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);   // for directed comment this line 
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
    int V=6;
    vector<int> adj[V];
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    
    printGraph(adj,V);

    dfs(adj,V);

    return 0 ;
}


//  g++ topologicalsort.cpp -o  topologicalsort.out
//  ./topologicalsort.out 

// Output
// 0 ——> 
// 1 ——> 
// 2 ——> 3 
// 3 ——> 1 
// 4 ——> 0 1 
// 5 ——> 0 2 
// 5 4 2 3 1 0 %  