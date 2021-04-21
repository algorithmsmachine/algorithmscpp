// Fibonacci numbers
// each number is the sum of the two preceding ones, starting from 0 and 1.
// They were introduced by Leonardo Fibonacci in 1202 as a solution to a problem about the size of a rabbit population

#include <iostream>
using namespace std;


//Fibonacci Series using Dynamic Programming
#include<stdio.h>

// Appriach 1 : Iterative code 
// Time Complexity of iterative code = O(n)
// Space Complexity of iterative code = O(1)
int fib_iterative(int n)
{
  int f[n+1];
  int i;
  
  f[0] = 0;
  f[1] = 1;
  
  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];
      cout << f[i] << ", ";
  }
  
  return f[n];
}

// Approach 2 : Recurssive code ( has bugs )

// Time complexity of recursive code = O(2^n)
// Space Complexity of recursive code = O(n) (for recursion call stack)

// int fib_recursive(int n)
// {

//   printf(" n %d", n);

//   if(n <= 1) {
//     return n;
//   }

//   return fib_recursive(n-1)+ fib_recursive(n-2);
// }
  
int main ()
{
  int n = 10;
  
  printf("fib_iterative %d", fib_iterative(n));
  getchar();

  // printf("fib_recursive %d", fib_recursive(n));

  // Here recursive algorithm is a more tough to analyse and inefficient in comparison with the iterative algorithms. 
  return 0;
}


// int main() {
//     int t1 = 0, t2 = 1, nextTerm = 0, n;

//     cout << "Enter a positive number: ";
//     cin >> n;

//     // first two terms which is always 0 and 1
//     cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";

//     nextTerm = t1 + t2;

//     while(nextTerm <= n) {
//         cout << nextTerm << ", ";
//         t1 = t2;
//         t2 = nextTerm;
//         nextTerm = t1 + t2;
//     }
//     return 0;
// }



//Fibonacci Series using Recursion
// #include<stdio.h>
// int fib(int n)
// {
//     if (n <= 1)
//       return n;
//     return fib(n-1) + fib(n-2);
// }
// int main ()
// {
//    int n = 9;
//    printf("%d", fib(n));
//    getchar();
//    return 0;
// }


// To see the growth 

// upto 10 -    0, 1, 1, 2, 3, 5, 8,
// upto 500 -   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
// upto 5000 -  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181
// upto 20000 - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711
// upto 900000-  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040

//  g++ -o fibonacci  Fibonacci.cpp
//  ./fibonacci