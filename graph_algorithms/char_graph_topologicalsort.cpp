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
            dfstraversal(adj[u][i],adj, visited, dfstree);
    }
}

// DFS for all unvisited vertices
vector<int> dfs(vector<int>adj[], int V){
    vector<bool> visited(V, false);
    vector<int> dfstree;
    for( int u=0; u<V; u++){
        if(visited[u]==false)
            dfstraversal(u,adj, visited, dfstree);
    }

    return dfstree;
}

// --------------------- Topological sort 

// do DFS traversal among adj which are non visisted 
void topotraversal(int u, vector<int> adj[], vector<bool> &visited, stack<int> &stk){
    visited[u]=true;
    for(int i=0; i<adj[u].size(); i++){
        if(visited[adj[u][i]]==false)
            topotraversal(adj[u][i],adj, visited, stk);
    }
    stk.push(u);
}

// DFS for all unvisited vertices
stack<int> topologicalsort(vector<int>adj[], int V){
    vector<bool> visited(V, false);
    stack<int> stk; 
    for( int u=0; u<V; u++){
        if(visited[u]==false)
            topotraversal(u,adj, visited, stk);
    }

    return stk;
}


int main(){
    map<char,int> mp;
    map<char,int>::iterator itr;

    // Map for 7 edges graph    
    mp['a']=0;
    mp['b']=1;
    mp['c']=2;
    mp['d']=3;
    mp['e']=4;
    mp['f']=5;
    mp['g']=6;

    // DAG 
    // int V=7;
    // vector<int> adj[V];
    // addEdge(adj, mp, 'a', 'b');
    // addEdge(adj, mp, 'a', 'c');
    // addEdge(adj, mp, 'b', 'e');
    // addEdge(adj, mp, 'b', 'g');
    // addEdge(adj, mp, 'c', 'f');
    // addEdge(adj, mp, 'd', 'a');
    // addEdge(adj, mp, 'd', 'b');
    // addEdge(adj, mp, 'd', 'c');
    // addEdge(adj, mp, 'd', 'f');
    // addEdge(adj, mp, 'd', 'g');
    // addEdge(adj, mp, 'g', 'f');


    // Cyclic graph 
    int V=7;
    vector<int> adj[V];
    addEdge(adj, mp, 'a', 'b');
    addEdge(adj, mp, 'b', 'c');
    addEdge(adj, mp, 'c', 'd');
    addEdge(adj, mp, 'd', 'g');
    addEdge(adj, mp, 'e', 'a');
    addEdge(adj, mp, 'f', 'b');
    addEdge(adj, mp, 'f', 'c');
    addEdge(adj, mp, 'f', 'e');
    addEdge(adj, mp, 'g', 'f');
    addEdge(adj, mp, 'g', 'e');


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

    stack<int> stk = topologicalsort(adj,V);
    cout << "\n  Topological sort ";
    while(!stk.empty()){
        cout<< findKeybyVal(mp,stk.top())<<" ";
        stk.pop();
    }

    cout<< endl;
    return 0;
}

// g++ char_graph_topologicalsort.cpp -o ./graph.out
// ./graph.out

// output 

// a ——> b c 
// b ——> e g 
// c ——> f 
// d ——> a b c f g 
// e ——> 
// f ——> 
// g ——> f 
//     a   b   c   d   e   f   g   
// a   0   1   1   0   0   0   0   
// b   0   0   0   0   1   0   1   
// c   0   0   0   0   0   1   0   
// d   1   1   1   0   0   1   1   
// e   0   0   0   0   0   0   0   
// f   0   0   0   0   0   0   0   
// g   0   0   0   0   0   1   0   


//   DFS a b e g f c d 
//   BFS a a a a a a a a b c e g f d 
//   Topological sort d a c b g f e