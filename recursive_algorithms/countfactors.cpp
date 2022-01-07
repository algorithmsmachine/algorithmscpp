// Exponential

#include <iostream>
using namespace std;
#include<stdio.h>
#include<cmath>

//  if k divides n and k<√n , then there is another factor j=n/k such that j>√n 
int countfactors(int n){
    int k =1;
    int factors =0;
    while ( k < sqrt(n)){
        if(n%k ==0 ) {
            // cout << k << endl;
            factors += 2;
        }
        k++;
    }
    if( k*k ==n){
        // cout << k << endl;
        factors +=1;
    }
    return factors;
}

int main(){
    cout << countfactors(12);
}

//  g++ countfactors.cpp -o countfactors.out 
//  ./countfactors.out 

// 12 factors 1,2,3,4,6,12 , total 6