# Searching Algorithms 

## Linear / Sequential Serach
Searches for a given value in a given array sequentially .

- Worst case: Cworst( n)= O(n), occurs when the element to be searched is present at end or not present
- Best case: Cbest( n)= Ω(1), occurs when the element to be searched is present at the first position.
- Average case: Cavg(n)= Θ(n). occurs when the element to be searched is present at the Random position.

```
SequentialSearch2(A[0..n], K)

A[n] <- K
i<- 0 
while A[i] != K do 
    i <- i+1
if i<n return i 
else return -1
```
cpp implementation 
```
static int search(int arr[], int n, int x)
 {
     for (int i = 0; i < n; i++) {
         if (arr[i] == x)
             return i; // return  position if found
     }
     return -1; // not found
 }
```
Time complexity of above is O(n).

Improvement : if a given list is known to be sorted: searching in such a list can be stopped as soon as an element greater than or equal to the search key is encountered.

- Adv : simple to implement

- Disadv : inefficient and brute force application

## Pattern Matching Algorithm

Align the pattern against the first m characters of the text and start matching the corresponding pairs of characters from left to right until either : all the m pairs of the characters match (then the algorithm can stop) or mismatching pair is encountered.

In the latter case, shift the pattern one position to the right and resume the character comparisons

With text of length n and pattern of charecters m , last position in the text that can still be a beginning of a matching substring is n − m beyond that position, there are not enough characters to match the entire pattern

```
BruteForceStringMatch(T [0..n − 1], P[0..m − 1])

for i <- 0 to n-m 
    j <- 0
    while j < m and P[j] = T[i+j] do
        j <- j +1
    if j = m return i 
return -1
```

- Disadv : Worst Case : algorithm may have to make all m comparisons before shifting the pattern, and this can happen for each of the n − m + 1 tries hence m( n-m+1) comparisions which is O(nm) class

- Application : word search in a natural language text

## Binary Search
Comparing a search key K with the array’s middle element A[mid], stop if match found. Else compare with left half if K < A[mid] or right half if K > A[mid]

Decrease-by-a-constant-factor (2) algorithms usually run in logarithmic time.

l is first element
r is last element
x is number to be searched

```
int binarySearch(int arr[], int l, int r, int x)
{
    if (r>=l){
        int mid = l + (r - l)/2;    
 
        if (arr[mid] == x)
            return mid; // elem is in mid
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);   // chk to left
 
        return binarySearch(arr, mid+1, r, x); // chk to right
    }
    return -1;
}
```
Time complexity : O(Log n)

## Interpolation Search

Improvises on binary search. Selective search in ordered array based on search element

Search higher value of location index when element to be searched is closer to end of array value And search smaller value when closer to start of array value .
```
position = low + [ ( x  –  arr[low])   *   (  high – low ) / (   arr[high] – arr[low]    ) ]
```
The analysis of the algorithm’s efficiency shows that interpolation search uses fewer than log2 log2 n + 1 key comparisons on the average when searching in a list of n random keys.

## Jump search

Jump element search by jump size. If the jumped element > search element. Go back to previous jump location and do linear search to find the search element.

Optimal size of a block to be jumped / time complexity is O(√ n).

## Exponential Search

## Ternary Search

**References**
- Binary Serach https://en.wikipedia.org/wiki/Binary_search_algorithm#Running_time_and_cache_use 

Sources - https://programmingaltanai.wordpress.com/


