// Prime Number Checker 

#include <iostream>
using namespace std;
#include<stdio.h>
#include<cmath>


// Approach : iterartive prime  
// int prime(int n){
//     for(int i =2; i<n ;i++)
//         if(n%i==0 ) return -1;
//     return 1;
// }

// Approach 2 : recussive primer number checker 
// bool prime(int n, int i){
//   if(n==1) return true;
//   if(i==n) return true;

//   if(n%i==0)
//     return false;
  
//   prime(n,++i);
// }

// Approach 3 : Precheck for 2 and computer uptill sqrt(n)
// Each “pair” of factors will repeat once you go past the square root of the number being factored, 
// so it becomes redundant to continue checking for divisibility after that point.  
bool isprime(int n)
{
  static int i=2;
  if(n%i==0 && n!=2) return false;    
  else if (i< sqrt(n)){
    i++;
    return isprime(n);
  }
  return true;
}


int main (){
  int n = 3; 
  // printf("Final %d", prime(n)); // approach 1
  // cout <<  prime(n, 2); // approach 2 
  cout <<  isprime(n); // apparoach 3
  return 0;
}


// g++ -o prime.out prime.cpp
// ./prime.out 