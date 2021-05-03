# Decrease-and-conquer algorithm 
Used in Euclidean algorithm to compute the greatest common divisor (GCD) of two numbers by reducing the numbers to smaller and smaller equivalent subproblems
- Inserion Sort

# Divide and conquer algorithms 

Divide and conquer is an algorithm design paradigm which finds application in various areas
- fake coin problem
- sorting ( quicksort , merge sort )
- multiplying large numbers ( Karatsuba algorithm) 
- Strassen algorithm for matrix multiplication
- finding the closest pair of points, 
- syntactic analysis (e.g., top-down parsers), and 
- computing the discrete Fourier transform (FFT)

Features of D&C algos  
- suited for execution in multi-processor machines, especially shared-memory systems
- cache-oblivious - make efficient use of memory caches for smaller sub problems rather than accessing slower main memeory.
- usually implemented as recursive procedures , with sub problems stored in procedural call stack
- can also be implemented by a non-recursive program that stores the partial sub-problems in some explicit data structure, such as a stack, queue, or priority queue . This is used in breadth first recurssion and branch and bound

Divide by factor 

## Debugging help 

**Issue 1** trigerring gcc protection mechanism to detect buffer overflow errors
```
*** stack smashing detected ***: <unknown> terminated
```
