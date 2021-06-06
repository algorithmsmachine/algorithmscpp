// Graph with char nodes instead of int
// adj list , adj matrix , BFS , DFS , topological sort 

#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;

char findKeybyVal(map<char,int> mp, int k){
    for(auto itr:mp){
        if(itr.second == k) return itr.first;
    }
    return -1;
}

void addEdge(vector<int> adj[], map<char,int> mp, char cu, char cv){
    map<char,int>::iterator u = mp.find(cu);
    map<char,int>::iterator v = mp.find(cv);
    adj[u->second].push_back(v->second);
}

void printGraph(vector<int> adj[], map<char,int> mp, int V){
    for (int i = 0; i < V; i++){
        cout << findKeybyVal(mp,i) << " ——> "; // print the current vertex number 
        for (auto v: adj[i]) 
            cout << findKeybyVal(mp,v) << " ";   // print all neighboring vertices of a vertex `i`
        cout << endl;
    }
}


void printMatrix(vector<vector<int>> adjmatrix,  map<char,int> mp){
    cout << "    ";
    for(auto itr:mp){
        cout << itr.first << "   ";
    }
    cout<<endl;

    int V = adjmatrix.size();
    for (int i = 0; i < V; i++) {
        cout<< findKeybyVal(mp,i) << "   ";
        for (int j = 0; j < V; j++) {
            cout << adjmatrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void convertlist_matrix(vector<int> adj[],  map<char,int> mp, int V){
    vector<vector<int>> adjmatrix(V,vector<int>(V, 0));
    for(int i=0 ;i<V; i++){
        for(auto j:adj[i]){
            adjmatrix[i][j]=1;
        }
    }
    printMatrix(adjmatrix, mp);
}

// -------------------------BFS 

// Breadth first traversal for unvisited vertices 
void bfstraversal(int u, vector<int> adj[],vector<bool> &visited, vector<int> &bfstree){
    queue<int> q;
    q.push(u);
    visited[0]=true;

    // list<int>::iterator i;
    while(!q.empty()){
        int s=q.front();
        // cout<< s << " " ;
        bfstree.push_back(s);
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
vector<int> bfs(vector<int>adj[], int V){
    queue<int> q;
    vector<bool> visited(V,false);
    vector<int> bfstree(V);
    for(int i=0;i<=V;i++) visited[i]=false;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bfstraversal(i,adj,visited, bfstree);
    }
    return bfstree;
}


// -------------------------DFS 

// do DFS traversal among adj which are non visisted 
void dfstraversal(int u, vector<int> adj[], vector<bool> &visited, vector<int> &dfstree){
    visited[u]=true;
    dfstree.push_back(u);
    for(int i=0; i<adj[u].size(); i++){
        if(visited[adj[u][i]]==false)
            dfstraversal(adj[u][i],adj,visited,dfstree);
    }
}

// DFS for all unvisited vertices
vector<int> dfs(vector<int>adj[], int V){
    vector<bool> visited(V, false);
    vector<int> dfstree;
    for( int u=0; u<V; u++){
        if(visited[u]==false)
            dfstraversal(u,adj,visited,dfstree);
    }
    return dfstree;
}


int main(){
    map<char,int> mp;
    map<char,int>::iterator itr;

    mp['a']=0;
    mp['b']=1;
    mp['c']=2;
    mp['d']=3;
    mp['e']=4;
    mp['f']=5;
    mp['g']=6;

    int V=7;
    vector<int> adj[V];
    addEdge(adj, mp, 'a', 'b');
    addEdge(adj, mp, 'a', 'c');
    addEdge(adj, mp, 'b', 'e');
    addEdge(adj, mp, 'b', 'g');
    addEdge(adj, mp, 'c', 'f');
    addEdge(adj, mp, 'd', 'a');
    addEdge(adj, mp, 'd', 'b');
    addEdge(adj, mp, 'd', 'c');
    addEdge(adj, mp, 'd', 'f');
    addEdge(adj, mp, 'd', 'g');
    addEdge(adj, mp, 'g', 'f');

    printGraph(adj, mp, V);

    convertlist_matrix(adj,mp,V);


    vector<int> dfstree = dfs(adj,V);
    cout << "\n  DFS ";
    for(auto i: dfstree){
        cout<< findKeybyVal(mp,i)  << " ";
    }

    vector<int> bfstree = bfs(adj,V);
    cout << "\n  BFS ";
    for(auto i: bfstree){
        cout<< findKeybyVal(mp,i)  << " ";
    }

    return 0;
}