// Factorial

#include <iostream>
using namespace std;
#include<stdio.h>

// Approach 1 : Linear  
// int factorial(int n)
// {
//     /* Declare an array to store factorial numbers. */
//     int f[n]={1};
//     int i;

//     f[0] = n;

//     cout << f[0] << ", ";

//     for (i = 1; i <= n; i++)
//     {
//         f[i] *= f[n-i];
//         cout << f[i] << ", ";
//     }

//     return f[n];
// }

// Approach 2 : Recursion 
int factorial(int n){
    if(n==1) return 1;

    return n*factorial(n-1);
}

int main (){
  int n = 4;
  printf("Final count %d", factorial(n));
  return 0;
}

// g++ -o factorial.out factorial.cpp
// ./factorial.out 

// Answer : 89