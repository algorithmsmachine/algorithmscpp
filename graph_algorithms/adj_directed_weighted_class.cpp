// Adjcency List from a graph
#include<iostream>
#include<vector>
using namespace std;

struct Edge{
    int src, dest, weight;
};
typedef pair<int,int> Pair;

class Graph{
public:
    vector<vector<Pair>> adj; // vector of vectors for adj list
    Graph(vector<Edge> const &edges, int N ){
        adj.resize(N);
        for(auto &edge: edges)  
            adj[edge.src].push_back(make_pair(edge.dest,edge.weight));
    }
};

// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " ——> "; // print the current vertex number
 
        for (Pair v: graph.adj[i]) {
            cout << "(" << v.first << " " << v.second<< ")";   // print all neighboring vertices of a vertex `i`
        }
        cout << endl;
    }
}

int main(){
    vector<Edge> edges={
        { 0, 1, 6 }, 
        { 1, 2, 7 }, 
        { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, 
        { 5, 4, 1 }, 
        { 4, 5, 3 }
    };
    int N=6;
    Graph g(edges, N);
    printGraph(g,N);
    return 0;
}


//  g++ adj_directed_weighted.cpp -o adj_directed_weighted.out 
// ./adj_directed_weighted.out 
// 0 ——> (1 6)
// 1 ——> (2 7)
// 2 ——> (0 5)(1 4)
// 3 ——> (2 10)
// 4 ——> (5 3)
// 5 ——> (4 1)