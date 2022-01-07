// Is graphs connected 

// Connected graph - all vertices are reachable from the starting vertex. 
// Disconnected graph - not all reachable
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

bool isConnected_BFS(int u, vector<int> adj[],vector<bool> &visited){ 
    for(int i = 0; i < visited.size(); i++) {
        if(!visited[i]){ //if there is a node, not visited by traversal, graph is not connected
            cout << " Discinnected ";
            return false;
        }
    }
    cout << " Connected ";
    return true;
}

void BFSUtil(int u, vector<int> adj[],vector<bool> &visited){ 
    list<int> q;
    visited[0] = true; 
    q.push_back(u);
   
    while(!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop_front();
   
        for (int i = 0; i != adj[u].size(); ++i){
            if (!visited[adj[u][i]]){
                visited[adj[u][i]] = true;
                q.push_back(adj[u][i]);
            }
        }
    }
    isConnected_BFS(u, adj, visited);
}
void BFS(vector<int> adj[], int V){
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            BFSUtil(u, adj, visited);
}

// Algorithms bool isConnected();
// solved using a modified DFS changes include:
// 1. Including a count of # of vertices; each time you compile a vertex, then 
//    decrement the count -> this happens when you pop that vertex off the stack
// 2. If the stack is ever empty, check if the vertex count from part (1) is zero. 
//    If so, then connected and return true. Else, return false.

int main(){
    int V = 5;
    vector<int> adj[V];
  
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // isconnected suing BFS
    BFS(adj, V);

    // is connected using DFS

    return 0;

}