// Vector of vectors 
// 2D dynamic array with varaible number of rows
// vectore< vector<datatype>> vec;

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
int main(){
    // vector<vector<int>> vv{
    //     {1,2,3},
    //     {4,5},
    //     {6,7,8,9}
    // };

    vector<vector<int>> vv;
    int n=10; // num of elemenst to insert in col
    for (int i = 0; i < ROW; i++) {
        // Vector to store column elements
        vector<int> v1;
  
        for (int j = 0; j < COL; j++) {
            v1.push_back(n);
            n += 5;
        }
  
        // Pushing back above 1D vector
        // to create the 2D vector
        vv.push_back(v1);
    }
    // vv.push_back({2,5,7});

   for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    // Find the sum of the vector of every row
    for (int i = 0; i < vv.size(); i++) {
        cout << "\nSum = "<< accumulate( vv[i].begin(),  vv[i].end(), 0);
    }
   
}

// 