// Fibonacci’s rabbits problem 
// A man put a pair of rabbits in a place surrounded by a wall. How many pairs of rabbits will be there in a year if the
// initial pair of rabbits (male and female) are newborn and all rabbit pairs are
// not fertile during their first month of life but thereafter give birth to one new
// male/female pair at the end of every month?
#include <iostream>
using namespace std;
#include<stdio.h>
  
int fib(int n)
{
  /* Declare an array to store Fibonacci numbers. */
  int f[n+1];
  int i;
  
  f[0] = 0;
  f[1] = 1;
  
  cout << f[0] << ", "<< f[1] << ", ";

  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
      cout << f[i] << ", ";
  }
  
  return f[n];
}
  
int main ()
{
  int n = 11;
  printf("Final count %d", fib(n));
  getchar();
  return 0;
}

// Answer : 89