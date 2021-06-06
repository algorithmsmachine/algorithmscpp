//
// Created by altanai on 09/08/20.
//
// Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

#define V 4 // vertices in the graph
#define INF 99999 // Define Infinite, as large as datatype can contain 
void printSolution(int dist[][V]);

// ALGORITHM Floyd(W[1..n, 1..n])
// for k←1 to n do
//     for i ←1 to n do
//         for j ←1 to n do
//             D[i, j]← min{D[i, j], D[i, k]+ D[k, j]}
// return D
void floydWarshall(int graph[][V]){
	int dist[V][V], i, j, k;

    // diagonals are 0
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) { 
				// If vertex k is on the shortest path from i to j, then update the dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
        
        cout << " solu when k " << k+1 << endl;
        printSolution(dist);
        cout << endl;
	}
    cout << "APSP - shortest path between every pair of vertices \n";
	printSolution(dist);
}

// ALGORITHM Warshall(A[1..n, 1..n])
// R(0) ← A
// for k ← 1 to n do
//  	for I ← 1 to n do
//  		for j ← 1 to n do
//  			R(k)[i, j] ← R(k−1)[i, j] or (R(k−1)[i, k] and R(k−1)[k, j])
// return R(n)
void warshall(int graph[][V]){
	int R[V][V], i, j, k;

    // diagonals are 0
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			R[i][j] = graph[i][j];

	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) { 
                R[i][j] = R[i][j] || ( R[i][k] && R[k][j]);
			}
		}
        
        cout << " solu when k " << k+1 << endl;
        printSolution(R);
        cout << endl;
	}
    cout << "Transitive closure \n";
	printSolution(R);
}

void printSolution(int dist[][V]){
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

int main(){
	// int graph[V][V] = { { 0, INF, 1, INF },
	// 					   { 7, 0, 6, INF },
	// 					   { INF, INF, 0, 5 },
	// 					   { INF, 2, INF, 0 } };
	// floydWarshall(graph);

	int graph[V][V] = { { 0, 0, 0, 0 },
						{ 0, 0, 1, 1 },
						{ 0, 1, 0, 0 },
						{ 1, 0, 1, 0 } };
    warshall(graph);
	return 0;
}

// g++ floyd.cpp -o floyd.out
//./floyd.out    

// Output
//  solu when k 1
// 0        INF     1       INF     
// 7        0       6       INF     
// INF      INF     0       5       
// INF      2       INF     0       

//  solu when k 2
// 0        INF     1       INF     
// 7        0       6       INF     
// INF      INF     0       5       
// 9        2       8       0       

//  solu when k 3
// 0        INF     1       6       
// 7        0       6       11      
// INF      INF     0       5       
// 9        2       8       0       

//  solu when k 4
// 0        8       1       6       
// 7        0       6       11      
// 14       7       0       5       
// 9        2       8       0       

// APSP - shortest path between every pair of vertices 
// 0        8       1       6       
// 7        0       6       11      
// 14       7       0       5       
// 9        2       8       0  