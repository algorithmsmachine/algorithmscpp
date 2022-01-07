// Exponential

#include <iostream>
using namespace std;
#include<stdio.h>
#include<cmath>

// Approach 1 : Iterative Exponential
// O(n)
// int exponential(int n)
// {
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

// int ceil(int x, int y) {
//     return x / y + (x % y != 0);
// or  q = 1 + ((x - 1) / y); // if x != 0 
// }

// Approach 2 : Recursive Exponential 
// O(n)
int exponential(int n, int p, int &i){
    if(i==p) return 1;
    return n*exponential(n,p,++i); 
}

// Approach 3 : Divide and Conquer Exponential 
// power(x, n) = power(x, n / 2) × power(x, n / 2);        // otherwise, n is even
// power(x, n) = x × power(x, n / 2) × power(x, n / 2);    // if n is odd 
// O(n)
int exponential_dc(int n, int p)
{
    if(p<=1) return n;
    // cout <<"\n" << floor(p/2) << 3/2 <<  (1+(p-1)/2) ;
    // ceil outwatds roufning mode // https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
    return exponential_dc(n,floor(p/2)) * exponential_dc(n, 1+(p-1)/2);
}


// Approach 5 : Optimized Divide and Conquer Exponential 
// O(logn)
int exponential_dc2(int n, int p){
      // base condition
    if (p == 0) {
        return 1;
    }
    // calculate subproblem recursively
    int pow = exponential_dc2(n, p / 2);
    if (p & 1) { // if `p` is odd
        return n * pow * pow;
    }
 
    // otherwise, `p` is even
    return pow * pow;
}

 
// Approach 6 : Faster Exponential by successive sqauring in computing even expoenetials 
int square(int x){
  return x*x;
}
int exponential_sq(int n, int p){
  if(p<=1) return n ;
  if(p%2==0) return square(exponential_sq(n ,p/2));
  else return n*exponential_sq(n,p-1);
}

int main ()
{
  int n = 2; int p =3; // ans 2^3 = 8
  int i = 0;

  printf("Final %d", exponential(n, p, i));
  printf("\n DC %d", exponential_dc(n, p));
  printf("\n exponential_sq %d", exponential_sq(n, p));
  return 0;
}

// g++ -o exponential.out exponential.cpp
// ./exponential.out 

// outout
// Final 8
// DC 8
// exponential_sq 8% 