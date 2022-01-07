// find if a graph is bipartite by coloring its node in group of 
// -1 uncolored 
// 0 blue 
// 1 red

// DOESNT WORK 

#include<iostream>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isbipartite(vector<int> adj[], int V, int s){
    vector<int> color(V,-1); // every node uncolored 

    color[s]=0; // color starting node as blue
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for( int i=0;i<V;++i){
    
            for(auto v:adj[i]){
                if(u==i) return false; // self loop return false
                
                if(color[v]==-1){  // edge from v exists and destination is not colored 
                    color[v]=1-color[u]; // assign alternate color 
                    q.push(v);
                }else if(color[v]==color[u]){
                    return false;
                }
            }
        }
        
    }
    return true;
}

int main(){
    int V=4;
    vector<int> adj[V];
    // addEdge(adj,0,2);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);
    // addEdge(adj,2,1);

    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,0);
    addEdge(adj,1,2);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,3,2);

    isbipartite(adj,V, 0)?cout<<"yes":cout<<"no";
    return 0;
}