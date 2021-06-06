#include<iostream>
using namespace std;

struct{
    int item;
    int priority;
};

// priroty queues using arrays
// insert : adding element at end O(1) 
// gethighestpriority : linear seraching all item for highesr priority O(n)
// delete : expensive as it involves to move all elemenet 1 space 

// priority queues using heaps 
// insert : O(logn)
// gethighestpriroty : O(1)
// delete : O(logn)
