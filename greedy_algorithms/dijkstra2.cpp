//
// Created by altanai on 09/08/20.
//

#include <limits.h>
#include <iostream>
#include <map> 
using namespace std;
#define INF 9999

class Graph {
public:
    int vertexNum;
    int **edges;

    Graph(const int V) {
        this->edges = new int *[V]; // initializes the array edges.
        for (int i = 0; i < V; i++) {
            edges[i] = new int[V];
        }

        for (int i = 0; i < V; i++) { // fills the array with zeros.
            for (int j = 0; j < V; j++) {
                edges[i][j] = 0;
            }
        }
        this->vertexNum = V;
    }

    void addEdge(char src, char dst, int weight) {
        this->edges[src][dst] = weight;
    }
};

// find minimum distance vertex in mdist
int minDistance(int mdist[], bool vset[], int V) {
    int minVal = INT_MAX, minInd = 0;
    for (int i = 0; i < V; i++) {
        if (!vset[i] && (mdist[i] < minVal)) {
            minVal = mdist[i];
            minInd = i;
        }
    }
    return minInd;
}


void print(Graph graph,int dist[], int V, string path[]) {
    cout << "\nVertex  Distance   Path " << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] < INT_MAX)
            cout << i << "\t" << dist[i] << "\t" << path[i] << endl;
        else
            cout << i << "\tINF " << endl;
    }
}

// SSSP - Single source shortest path
// doesn't work on negative weights
void Dijkstra(Graph graph, char src) {

    int V = graph.vertexNum;
    int mdist[V];               // distances to vertex
    string path[V];             // path to vertex
    bool vset[V];               // vset[i] is true if the vertex i included in the shortest path tree

    // Initialise mdist and vset. Set distance of source as zero
    for (int i = 0; i < V; i++) {
        mdist[i] = INT_MAX;
        path[i] = "";
        vset[i] = false;
    }

    mdist[src] = 0;

    for (int count = 0; count < V - 1; count++) {           // iterate to find shortest path
        int u = minDistance(mdist, vset, V);
        vset[u] = true;

        for (int v = 0; v < V; v++) {
            if (!vset[v] && graph.edges[u][v] && mdist[u] + graph.edges[u][v] < mdist[v]) {
                mdist[v] = mdist[u] + graph.edges[u][v];     // put min dist to v
                path[v] = path[u] + ' ' + to_string(u);      // put shortest path to v 
            }
        }
    }

    print(graph, mdist, V, path );
}

int main() {
    int V = 5;
    Graph G(V);
    int table[V][V]= {{0, 2, 1, INF, INF },
                      {INF ,0, 1, INF , INF},
                      {9, INF ,0 ,8 ,2 },
                      {3, INF, INF ,0 ,INF},
                      {INF ,INF ,INF ,3 ,0}};

    // int V = 5;
    // Graph G(V);
    // int table[V][V]= {{0, INF, INF, 7 , INF},
    //                   {3 ,0, 4, INF, INF},
    //                   {INF, INF ,0 ,INF ,6 },
    //                   {INF, 2,5 ,0 ,INF},
    //                   {INF ,INF ,INF ,4 ,0}};

    for (int i = 0; i <V; i++){
        for (int j = 0; j<V; j++)
            G.addEdge(i, j, table[i][j]);
    }

    char gsrc = 0; // 0 for A ,  2 for C
    Dijkstra(G, gsrc);

    return 0;
}

// g++ dijkstra2.cpp -o dijkstra.out
// ./dijkstra.out 

// output 
// Vertex  Distance   Path 
// 0       0
// 1       9        0 3
// 2       12       0 3
// 3       7        0
// 4       18       0 3 2