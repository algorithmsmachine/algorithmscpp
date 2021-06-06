// Adjcency List from a Directed graph

// Source src and destination of Edge used while building graph 

#include<iostream>
#include<vector>
using namespace std;

struct Edge{
    int src, dest;
};

class Graph{
public:
    vector<vector<int>> adj; // vector of vectors for adj list
    Graph(vector<Edge> const &edges, int N ){
        adj.resize(N);
        for(auto &edge: edges)  
            adj[edge.src].push_back(edge.dest);
    }
};

// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << i << " ——> "; // print the current vertex number
 
        for (int v: graph.adj[i]) {
            cout << v << " ";   // print all neighboring vertices of a vertex `i`
        }
        cout << endl;
    }
}

int main(){
    vector<Edge> edges={
        { 0,1} , 
        { 1, 2 }, 
        { 2, 0 }, { 2, 1 },
        { 3, 2 }, 
        { 4, 5 }, 
        { 5, 4 }
    };
    int N=6;
    Graph g(edges, N);
    printGraph(g,N);
    return 0;
}


// g++ adjacencylist.cpp -o adjacencylist.out 
// ./adjacencylist.out 
// 0 ——> 1 
// 1 ——> 2 
// 2 ——> 0 1 
// 3 ——> 2 
// 4 ——> 5 
// 5 ——> 4 