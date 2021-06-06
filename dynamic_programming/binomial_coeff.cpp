// binomail coeff 
// coefficient of x^k in the expansion of (1 + x)^n.
//
// Created by @altanai on 31/03/21.
//
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

// optimal substructure 
//   C(n, k) = C(n-1, k-1) + C(n-1, k)
//   C(n, 0) = C(n, n) = 1

// Approach 1 : Recussive Function 
int binocoeff_recursive(int n , int k){
    if(k>n) return 0;
    if(k==0 || n==k) return 1;
    return binocoeff_recursive(n-1,k-1)+binocoeff_recursive(n-1,k);
}


// Approach 2 : Dynamic programing 
// Using 2D-array C[][] in a bottom-up manner.

// Algorithm 
// for i<- 0 to n do 
//     for j <- 0 to min(i,k) do 
//         if j==0 or j==i 
//             C[i,j] = 1
//         else 
//             C[i,j] = C[i-1,j] + C[i-1,j-1]
// return C[i,j] 

// Time Complexity: O(n*k) 
// Auxiliary Space: O(n*k)

int binocoeff(int n, int k){
    int C[n+1][k+1]={};
    for (int i=0; i<= n; i++){
        for(int j=0; j<= std::min(i,k); j++){
            if( (j==0) || (j==i))
                C[i][j]= 1;
            else
                C[i][j]= C[i-1][j] + C[i-1][j-1];
        }
    }

    cout << '\n';
    for ( int i = 0; i<=n; i++){
        for (int j = 0; j<=k; j++){
            cout << C[i][j]<< '\t';
        }
        cout << '\n';
    }
    return C[n][k];
}


// Approach 3 : space optimized binomial coeff using pascals triangle
int binocoeff_spaceoptimized(int n, int k){
    int C[k+1]={};
    memset(C,0,sizeof(C));                  // set to 0
    C[0]=1;                                 // starting of pascals triangle
    
    for (int i=0; i<= n; i++){              // incrementing  loop
        for(int j=std::min(i,k); j>0; j--){ // decrementing loop
                C[j]= C[j] + C[j-1];        // reuse space doing coeff calculation
        }
    }
    return C[k];
}

int main(){
    
    // int n =3, k=2;
    int n=5, k=5;
    // int n =30, k=28;

    // cout<<"binomial coefficients by recursion ";
    // cout<< binocoeff_recursive(n,k)<< endl;                   // 3240 / 0.10s user 0.00s system 98% cpu 0.107 total

    cout<<"binomial coefficients by dynamic programing ";      // 3324 /  0.01s user 0.01s system 88% cpu 0.007 total
    cout<< binocoeff(n,k) <<endl;

    // cout <<"binomial coefficients by dynamic programing with space optimization ";
    // cout<< binocoeff_spaceoptimized(n,k) <<endl;                 // 3244  /  0.00s user 0.01s system 90% cpu 0.006 total
    return 1;
}

// /usr/bin/time -f "%M" ./binomial_coeff.out
// or 
// g++ binomial_coeff.cpp -o binomial_coeff.out 
// ./binomial_coeff.out 

// output 
// binomial coefficients by dynamic programing 
// 1       0       0       0       0       0
// 1       1       0       0       0       0
// 1       2       1       0       0       0
// 1       3       3       1       0       0
// 1       4       6       4       1       0
// 1       5       10      10      5       1

// Output with time efficiency
// time  ./binomial_coeff.out 

// binomial coeffcients by recursion 5852925
// ./binomial_coeff.out  0.10s user 0.00s system 98% cpu 0.107 total

// binomial coeffcients by dynamic programing 27405
// ./binomial_coeff.out 0.01s user 0.01s system 88% cpu 0.007 total

// binomial coeffcients by dynamic programing with space optimization 435
// ./binomial_coeff.out  0.00s user 0.01s system 90% cpu 0.006 total