#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w)); // for directed remove this line 
}

void printGraph(vector<pair<int,int>> adj[],int V){
    for( int i=0;i<V;i++){
        cout << i << " ——> ";
        for (auto v= adj[i].begin();v!=adj[i].end();++v) {
            cout<< v->first << " (" << v->second<< ") ";
        }
        cout<<endl;
    }
}

int main(){
    int V=5;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj,V);
    return 0;
}

// g++ adj_undirected_weighted.cpp -o adj_undirected_weighted.out
// ./adj_undirected_weighted.out

// output undirected 
// 0 ——> 1 (10) 4 (20) 
// 1 ——> 0 (10) 2 (30) 3 (40) 4 (50) 
// 2 ——> 1 (30) 3 (60) 
// 3 ——> 1 (40) 2 (60) 4 (70) 
// 4 ——> 0 (20) 1 (50) 3 (70) 

// // output directed 
// 0 ——> 1 (10) 4 (20) 
// 1 ——> 2 (30) 3 (40) 4 (50) 
// 2 ——> 3 (60) 
// 3 ——> 4 (70) 
// 4 ——> 