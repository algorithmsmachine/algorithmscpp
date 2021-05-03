// binary strings generator /  2n bit strings  from an integer number N , in ascending order 
// n-bit Gray Codes - generate bit patterns from 0 to 2^N-1 such that successive patterns differ by one bit. 
// Example : 2 
// 00
// 01
// 10
// 11

// The approach would use permutation using backtracking

// Permutation is an ordered combination 
// P( n ,r) = n!.(n-r)!

// Combination is selection of items from a collection, such that the order of selection does not matter. 
// C(n,r) = n!/(r!.(n-r)!)
// #include <bits/stdc++.h>


#include<iostream>
#include<stdlib.h>

using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

// approach 1 : start from front
// void binaryStrings(int arr[], int n , int i)
// {

//     if (i == n) {  
//         printArray(arr, n);
//         return;
//     }

//     arr[i] = 0;
//     binaryStrings(arr, n, i + 1);

//     arr[i] = 1;
//     binaryStrings(arr, n, i + 1);
// }



// approach 2 : start from rear
void binaryStrings(int arr[], int n, int i)
{

    if (i==0) {  
        printArray(arr, n);
        return;
    }

    arr[i-1] = 0;
    binaryStrings(arr, n, i-1);

    arr[i-1] = 1;
    binaryStrings(arr, n, i-1);
}


// Driver Code
int main()
{
    int n = 3;
    int *arr = new int[4];
    // approach 1
    // binaryStrings(arr, n, 0);

    // approach 2
    binaryStrings(arr, n , n);

    return 0;
}

//  g++ -o binarystrings.out binarystrings.cpp -ansi -pedantic -Wall -Werror -std=c++11 
//  ./binarystrings.out

// outout for 3
// 0 0 0 
// 1 0 0 
// 0 1 0 
// 1 1 0 
// 0 0 1 
// 1 0 1 
// 0 1 1 
// 1 1 1

// Recurrance relation for this algorithm where P = n! (n-r)!
// The base operation being 
// n! = n . n-1 . n-2 .... 2 . 1
// n-1! = n-1 . n-2 ...... 2 . 1 

// (n) =