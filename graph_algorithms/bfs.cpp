// BFS - breadth-first search traversal 

// Input : Graph G=(V,E)
// Output :  Graph G with its vertices marked with consecutive integers in order of encoounter

//Algo

// marks all vertex as 0 unvisited
// counter <- 0
// for each vertex v in V do
//     if v ismarked 0
//            bfs(v)

// bfs(v)
// counter <- counter +1
// while !queue.empty do
//      for each vertex w in vadj to front vertex do
//          if w ismarked 0
//              counter <- counter +1 ; mark w with counter 
//              queue.add w
//      queue.pop front vertex



// gcc -Wall undirected_dfs.c -o dfs.out 

#include<bits/stdc++.h>
using namespace std;

// Breadth first traversal for unvisited vertices 
void bfstraversal(int u, vector<int> adj[],vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        int s=q.front();
        cout<< s << " " ;
        q.pop();
        for(auto i=adj[s].begin();i!=adj[s].end();++i){
            if(!visited[*i]){
                visited[*i]=true;
                q.push(*i);
            }
        }
    }
}

// BFS for all unvisited vertices
void bfs(vector<int>adj[], int V){
    queue<int> q;
    vector<bool> visited(V,false);
    for(int i=0;i<=V;i++) 
        visited[i]=false;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bfstraversal(i,adj,visited);
    }
}


void addEdge(vector<int> adj[], int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);  // for directed comment this line 
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
    int V=11;
    vector<int> adj[V];
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 4);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);

    addEdge(adj, 8, 10);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 7);
    printGraph(adj,V);

    bfs(adj,V);

    return 0;
}
