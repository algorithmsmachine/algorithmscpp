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

    void addEdge(char source, char destination, int weight, map<char,int> mp) {
        
        int src = mp.find(source)->second;
        int dst = mp.find(destination)->second;
        this->edges[src][dst] = weight;
    }
};

char findKeybyVal(map<char,int> mp, int k){
    for(auto itr:mp){
        if(itr.second == k) return itr.first;
    }
    return -1;
}

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


void print(Graph graph,int dist[], int V ,string path[], map<char,int> mp) {
    cout << "\nVertex \tDistance \tPath " << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] < INT_MAX)
            cout << findKeybyVal(mp,i) << "\t" << dist[i] << "\t" << path[i]  << endl;
        else
            cout << findKeybyVal(mp,i) << "\tINF"  << endl;
    }
}

// SSSP - Single source shortest path
// doesn't work on negative weights
void Dijkstra(Graph graph, char source, map<char,int> mp) {

    int src = mp.find(source)->second;

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

    for (int count = 0; count < V - 1; count++) { // iterate to find shortest path
        int u = minDistance(mdist, vset, V);
        vset[u] = true;

        for (int v = 0; v < V; v++) {
            if (!vset[v] && graph.edges[u][v] && mdist[u] + graph.edges[u][v] < mdist[v]) {
                mdist[v] = mdist[u] + graph.edges[u][v];
                path[v] = path[u] + ' ' + findKeybyVal(mp,u); 
            }
        }
    }

    print(graph, mdist, V , path, mp);
}

int main() {
    int V = 7;
    map<char,int> mp;
    map<char,int>::iterator itr;
    mp['A']=0;
    mp['B']=1;
    mp['C']=2;
    mp['D']=3;
    mp['E']=4;
    mp['F']=5;
    mp['G']=6;
 
    Graph G(V);

    // adj matrix
    // int adjmatrix[V][V]= {{0, 2, 1, INF, INF },
    //                 {INF ,0, 1, INF , INF},
    //                 {9, INF ,0 ,8 ,2 },
    //                 {3, INF, INF ,0 ,INF},
    //                 {INF ,INF ,INF ,3 ,0}};
    // for (int i = 0; i <V; i++){
    //     for (int j = 0; j<V; j++){
    //         char s= findKeybyVal(mp,i);
    //         char d= findKeybyVal(mp,j);
    //         G.addEdge(s, d, adjmatrix[i][j], mp);
    //     }
    // }

    // adj List 
    G.addEdge('A', 'B', 1, mp); // src, dst, weight;
    G.addEdge('A', 'D', 2, mp);

    G.addEdge('B', 'C', 3, mp);

    G.addEdge('C', 'F', 2, mp);
    G.addEdge('C', 'G', 4, mp);
    // G.addEdge('C', 'E', 2, mp);

    G.addEdge('D', 'E', 3, mp);

    G.addEdge('E', 'G', 3, mp);

    G.addEdge('F', 'G', 1, mp);

    char gsrc='A';
    Dijkstra(G, gsrc, mp );


    return 0;
}

// g++ dijkstra.cpp -o dijkstra.out
// ./dijkstra.out   

// Output 
// Vertex  Distance        Path 
// A       8        C E D
// B       10       C E D A
// C       0
// D       5        C E
// E       2        C