// DFS ( Depth First Serach/Traversal) in Directed graph
// using adjacency list 
//
// Created by @altanai on 31/03/21.
//
// start from a node and explores as far as possible along each branch(using unmarked) before backtracking
// O(V + E)

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class Graph{
    map<int,bool> visited;
    map<int,list<int>> adj;
    public:
        // Graph(int v);
        void addEdge(int v , int w);
        void dfs(int v);
};

// Graph::Graph(int v){
//     this->v = v;
//     adj = new map<int,list<int>>[v];
// }

void Graph::addEdge(int v,int w){
    adj[v].push_back(w); 
}

void Graph::dfs(int v){
    visited[v]=true;
    cout<< v << " ";
    list<int>::iterator i;
    for( i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            dfs(*i);
        }
    }

}

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,3);

    g.dfs(2);  // bfs starting from the vertex 0

    return 0;
}

