#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include<map>
using namespace std;
 
// Approach 1 : sorting algorithm
//O(N log N) 
int kthsmallest_comparisionsort(int arr[], int n, int kth){
    sort(arr,arr+n);
    return arr[kth-1];
}

// Approach 2 : Find k'th smallest element in an array using min-heap
// O(n)
int kthSmallest(vector<int> const &vec, int k)
{
    // create an empty min-heap and initialize it with all elements
    // `use std::greater` as the comparison function for min-heap
    priority_queue<int, vector<int>, greater<>> pq(vec.begin(), vec.end());
 
    while (--k) { // pop from min-heap exactly `k-1` times
        pq.pop();
    }
 
    return pq.top(); // return the root of min-heap
}

// Approach 3 : Kth smallest by using frequency map 
int kth_smallest_freqmap(map<int, int> m, int k){
    int freq = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        freq += (it->second); // adding the frequencies of each element
        if (freq >= k) // if at any point frequency >= to kth
            return it->first;
    }
    return -1; // returning -1 if k>size of the array 
}

int main()
{
    // vector<int> input = { 7, 4, 6, 3, 9, 1 };
    // const size_t k = 3;
 
    // cout << "k'th smallest array element is " <<
    //         findKthSmallest(input, k);
 

    // int arr[]={5,3,5,7,8,2,4,6};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // kthSmallest();


    int n = 5;
    int k = 2;
    vector<int> arr = { 12, 3, 5, 7, 19 };
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]] += 1; // mapping every element with it's frequency
    }
    cout<< "\n kth smallest "<< kth_smallest_freqmap(m,k);

    return 0;
}


