// BFT ( Breadth First Traversal) in Directed graph
// using adjacency list 
//
// Created by @altanai on 31/03/21.
//

// Time Complexity: O(V+E) where,
// V is number of vertices in the graph and
// E is number of edges in the graph.

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v; // vertex
    list<int> *adj;
    public:
        Graph(int v);
        void addEdge(int v,int w); 
        void bfs(int s);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);  // vector push_back adds element at the end
}

void Graph::bfs(int s){
    bool *visited = new bool[v];
    for(int i=0;i<=v;i++) visited[i]=false; // Mark all vertices as not visited

    list<int> q;
    visited[s]=true; // mark current node as visited and enqueue it
    q.push_back(s);

    list<int>::iterator i;

    while(!q.empty()){
        s=q.front();
        cout<< s << " " ;
        q.pop_front();
    
        for(i=adj[s].begin();i!=adj[s].end();++i){
            if(!visited[*i]){
                visited[*i]=true;
                q.push_back(*i);
            }
        }
    }
}


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,3);

    g.bfs(2);  // bfs starting from the vertex 4

    return 0;
}