// median of 2 sorted arrays of diff sizes

#include <stdio.h>
#include<stdlib.h>


// Approach 1 : merge arrays and then 
//for odd count, median will be (m+n)/2
//for even count,  median will be average of elements at index ((m+n)/2 – 1) and (m+n)/2

// Approach 2 :
// first getting medians of the two sorted arrays

// if middle element of the smaller array is less than the middle element of the larger array
//       reduce the search space to the first half of the larger array and the second half of the smaller array.

// if  the middle element of the smaller array is greater than the middle element of the larger array then 
//       reduce the search space to the first half of the smaller array and second half of the larger array.

// In each step one half of each array is discarded. So the algorithm takes O(min(log m, log n)) time to reach the median value.
int median(int arr1[], int arr2, int a1, int a2){

    return 0;
}

void main(){
    int arr1[] = {-5, 3, 6, 12, 15},
        arr2[] = {-12, -10, -6, -3, 4, 10};

    printf("%d", median(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr2)/sizeof(arr2[0])));

}