// Sum of range in a series of first odd then even natural numbers

// Sum of first n numbers = n * (n + 1)/2
// Sum of first n even numbers = n * (n + 1)

// Thus 
// if Sum of first N even numbers is (n^2) + n 
// then Sum of first N odd numbers is n - (n^2) + n =  (n^2)

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// Function that returns sum in the range 1 to x in the
// sequence 1 3 5 7.....N 2 4 6...N-1
ll sumTillX(ll x, ll n){
    // number of odd numbers
    ll odd = ceil(n / 2.0);
 
    if (x <= odd)
       return x * x;
 
    // number of extra even numbers required
    ll even = x - odd;
 
    return ((odd * odd) + (even * even) + even);
}
 
int rangeSum(int N, int L, int R){
   return sumTillX(R, N) - sumTillX(L-1, N);
}
 
int main()
{
    ll N = 10, L = 1, R = 6;   
    cout << rangeSum(N, L, R);
    return 0;
}