// Polynomial evluation
//
// Created by @altanai on 31/03/21.
//
#include <iostream>
using namespace std;

// Simple method to evaluate polynomial 
// calculate xn, multiply the value with cn, repeat the same steps for other terms and return the sum
// using simple loop for x^n 
// Time complexity : O(n^2)

// Algorithm PolynomialEvaluationviaBruteForce ( P[0..n] , x )
// Computes value of polynomial P by using brute force till degree n
// Input : Array p[0..n] of coeff for increasing order of degree upto n
// Output : evaluation of polynomial
// polysum <- 0.0
// for i <- n to 0 in reverseorder do 
//     powerx <-1  
//     for  j <- 1 to i do
//         powerx <-  powerx * x
//         polysum <- polysum + P[i] * powerx
// return polysm

// return sum of a1.x^n + a2.X^(n-1) + a3.x^(n-3) ....+ a1.x + a0
int polyeval(int poly[], int n , int x)
{
	double polysum = 0.0; // Initialize sum of polynomial
    // Use array index from 0 to n-1 , n elements 

	for (int i=n-1; i>=0; i--){
        int powerx = 1; // initilize power of x

        for (int j=1; j<=i; j++){
		    powerx = powerx*x; // compute  x^i
        }

        polysum = polysum + poly[n-1-i] * powerx;
        cout << "\n" << i << " poly coeff "<< poly[n-1-i] << " x^i " << powerx << "\n";
        // cout << "\n polysum" << polysum << "\n";
    }
	return polysum;
}


// Improved approach - right to left
int polyeval2(int poly[], int n , int x)
{
	double polysum = 0.0; // Initialize sum of polynomial
    // Use array index from 0 to n-1 , n elements 
    int powerx = 1; // initilize power of x
	for (int i=0; i<n; i++){
        polysum = polysum + poly[n-1-i] * powerx;
        // cout << "\n" << poly[n-1-i] << " . " << powerx << "\n";
        // cout << "\n polysum" << polysum << "\n";
        powerx = powerx*x;
    }
	return polysum;
}



// Horner’s Method
// Time complexity :  O(nLogn) 
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
	int polysum = poly[0]; // Initialize polysum
	for (int i=1; i<n; i++){
        cout << "\n" << poly[i] << " . " << x << "\n";
		polysum = polysum*x + poly[i];
    }

	return polysum;
}

// Driver program to test above function.
int main()
{
    // sample data 1 
    // int poly[] = {2, 1};
	// int x = 1;

    // Ssample Data 2
    // int poly[] = {3, 2, 1, 1};
	// int x = 2;

    // Ssample Data 3
	// Let us evaluate value of 7x^3 - 5x^2 + 4x - 2 where x is upto 3 degree
	int poly[] = {7, -5, 4, -2};
	int x = 3;

    // In C/C++ sizeof. always gives the number of bytes in the entire object, and arrays are treated as one object.
    // Sizeof gives size of the pointer, not the object(s) pointed to
    // To get length of array in cpp , o divide by the size of each element.
    int n = sizeof(poly)/sizeof(poly[0]);
    cout<< "\n Size of polynomial array " << n ;

    cout<< "\n Value of polynomial by simple evaluation is " << polyeval(poly, n, x); 
    // cout<< "\n Value of polynomial by better evaluation is " << polyeval2(poly, n, x); 
	// cout<< "\n Value of polynomial by horner method is " << horner(poly, n, x);

}

// g++ -o poly.out Polynomial_evaluation.cpp 
// ./poly.out 