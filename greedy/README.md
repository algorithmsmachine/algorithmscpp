# Greedy Algorithms 

greedy algorithm is an algorithm that constructs an object X one step at a time,
at each step choosing the locally best option

- "Choose activities in ascending order of finishing times."

## Minimum Spanning Trees

## Prim's Algorithm

## Dijkstra's Algorithm

Can find nodes using BFS (Breath-First Search) or DFS (Depth-First Search)
Applicable only to Directed Acyclic Graphs (DAG) , with non negative weights 

Runtime using standard application 
- BFS Search / processing edges and nodes O(n+m) 
- find lowest code node O(n^2)

Runtime using binary heap as data structure 
- O(m logn)

Runtime using Fibonacci Heap Data structure 
- O (m + nlogn) 