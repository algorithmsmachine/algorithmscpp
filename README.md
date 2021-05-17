# Algorithms 

Contents 
- Recursive and iterative algorithms and their T(n)
- Search and sort algorithms and their T(n) 
- Divide and conquer algorithms 
- Brute Force algorithms ( TSP)
- Trees (BT, BST , Heap , priority queues)
- Graphs ( direcetd, undirected , BFS , DFS , topological sort)
- Greedy algorithms 
- Dynamic programing
- Scheduling algorithms 

More details at https://programmingaltanai.wordpress.com/ 

## Time efficiency

Time efficiency is analyzed by determining the number of repetitions of the “basic operation”. It almost always depends on the size of the
input
-  “Basic operation”: the operation that contributes most towards the running time of the algorithm

If T(n) is the run time , Cop is the cost of basic operation and C(n) is the number of time the basic operation is excuted

    T(n) ≈ Cop ⨉ C(n)


### Compiling a C program 
The phases  of gcc Compiler converts a C program into an executable. 
1. Pre-processing
    This can be further broken down into 
    - Removal of Comments
    - Expansion of Macros
    - Expansion of the included files.
    - Conditional compilation

2. Compilation , is converting to assembly language for assembler

    gcc -Wall -save-temps ll.c -o ll.out 

3. Assembly

4. Linking - linking function call with defs and adding aextra ocee for setting up env



## Help/Hints 

1. Corrupt memeory errors **segmentation fault (core dumped) **

Core Dump/Segmentation fault is caused by accessing memory that “does not belong to you.” 
When a piece of code tries to do read and write operation in a read only location in memory or freed block of memory, it is known as core dump.


### Note 

There is a .githook file to remove binaries ( .out) before pushing to git. I suggest anyone using this repo to add the same process as well.



**References**

Sites 
- Standford University course on Algorithm Design and Analysis by Tim Tim Roughgarden 
- CS 161 https://web.stanford.edu/class/archive/cs/cs161/cs161.1138/
- Git https://github.com/TheAlgorithms/C-Plus-Plus 
- Github.io pages - https://walkccc.github.io/CLRS/
- MIT openCourseware - Introduction to Algorithms https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/ 
- Video Lectures http://videolectures.net/mit6046jf05_introduction_algorithms/

Books 
- Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein( CLRS )
    - MIT press - Introduction to Algorithms, Third Edition https://mitpress.mit.edu/books/introduction-algorithms-third-edition
    