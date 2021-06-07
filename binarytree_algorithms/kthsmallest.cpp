#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Function to find the k'th smallest element in an
// array using min-heap
int findKthSmallest(vector<int> const &vec, int k)
{
    // create an empty min-heap and initialize it with all elements
    // `use std::greater` as the comparison function for min-heap
    priority_queue<int, vector<int>, greater<>> pq(vec.begin(), vec.end());
 
    // pop from min-heap exactly `k-1` times
    while (--k) {
        pq.pop();
    }
 
    // return the root of min-heap
    return pq.top();
}
 
int main()
{
    vector<int> input = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 3;
 
    cout << "k'th smallest array element is " <<
            findKthSmallest(input, k);
 
    return 0;
}


