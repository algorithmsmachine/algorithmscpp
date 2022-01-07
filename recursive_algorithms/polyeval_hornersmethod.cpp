// Horner’s method 
// evaluate polynomial in O(n) time

//  example of 2x3 – 6x2 + 2x – 1.
// can be evaluated as ((2x – 6)x + 2)x – 1. 


// Algorithm 
// initialize result as coefficient of x^n
// repeatedly multiply result with x and add next coefficient to result. 
// return result. 

#include <iostream>
using namespace std;

//calculate poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
	int result = poly[0]; // Initialize result

	// Solve value of polynomial using Horner's method
	for (int i=1; i<n; i++)
		result = result*x + poly[i];

	return result;
}

// Driver program 
int main()
{
	// 2x^3 - 6x^2 + 2^x - 1 where x = 3
	int poly[] = {2, -6, 2, -1};
	int x = 3;
	int n = sizeof(poly)/sizeof(poly[0]);
	cout << "Value of polynomial is " << horner(poly, n, x);
	return 0;
}
