// Find cycles / Find if DAG
// using DFS locate backedge - edge from a node to itself or to its ancestor in DFS tree.

// Algorithm
// 1. create graph for edges 
// 2. DFS using recurssive function with visited stack + additional recurssive stack
// 3. Mark current index as visited and mark the index in recurssive stack 
// 4. For all vertices not visited in adj list of current node, recussively call DFS function.
// 5. If adj vertices are already in recurssive stack , return backedge found true. 
#include<bits/stdc++.h>
using namespace std;

bool iscyclic(int u, vector<int> adj[], vector<int> dfstree){
    for(auto i: adj[u]){
        if(i==u) {
            cout << "\n Self loop in "<< i ;
            return true;
        }
        for(auto j:dfstree){
            if(i==j) {
                cout << "\n Backedge between "<< u << " and " << j;
                return true;
            }
        }
    }
    return false;
}

void dfstraversal(int u, vector<int> adj[], vector<bool> &visited, vector<int> &dfstree){
    visited[u]=true;

    // iscyclic(u, dfstree)? cout<<"Cyclic": cout<<"Acyclic";
    iscyclic(u,adj, dfstree);

    dfstree.push_back(u);
    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]])
            dfstraversal(adj[u][i],adj,visited,dfstree);
    }
}

vector<int> dfs(vector<int> adj[], int V){
    vector<bool> visited(V,false);
    vector<int> dfstree;
    for(int u=0;u<V;u++){
        if(!visited[u]){
            dfstraversal(u,adj, visited, dfstree);
        }
    }
    return dfstree;
}

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
}

int main(){
    //Cyclic
    int V= 4;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    addEdge(adj,3,3);
    

    //Acyclic
    // int V= 5;
    // vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 4);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);

    vector<int> dfstree = dfs(adj,V);

    // while (!dfstree.empty()) {
    //     cout << dfstree.front() << ' ';
    //     dfstree.pop();
    // }

    cout << "\n  DFS ";
    for(auto i: dfstree){
        cout<< i << " ";
    }
}


// g++ acyclicity.cpp -o acyclicity.out 
// ./acyclicity.out                     


// Output for Cyclic
//  Backedge between 2 and 0
//  Self loop in 3
//   DFS 0 1 2 3 %  

// Output for Acyclic
// DFS 0 1 2 3 4 