
// C++ program to Count Inversions in an array

// Let A[0..n−1] be an array of n distinct real numbers. A pair (A[i], A[j]) is said to be an inversion if 
// these numbers are out of order, i.e., i < j but A[i] > A[j]. 
// Design an O(n log n) algorithm for counting the number of inversions.

// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// If the array is already sorted, then the inversion count is 0, but 
// if the array is sorted in the reverse order, the inversion count is the maximum. 
#include <bits/stdc++.h>
using namespace std;


// double for loop approach :
// -  O(n^2) Time complexity which is bad 
// -  O(1) space complexity since no extra space is required 
// int getInvCount(int arr[], int n)
// {
// 	int inv_count = 0;
// 	for (int i = 0; i < n - 1; i++)
// 		for (int j = i + 1; j < n; j++)
// 			if (arr[i] > arr[j]){
//                 cout << "\n"<< arr[i] <<" - " << arr[j];
//             	inv_count++;
//             }
    
//     cout << "\n";
// 	return inv_count;
// }






// Driver Code
int main()
{
	int arr[] = { 1,4,3 ,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Number of inversions are "
		<< getInvCount(arr, n);
	return 0;
}

// g++ inversion.cpp -o inversion -ansi -pedantic -Wall -Werror -std=c++11 
// ./inversion 

