// frequency of a number in sorted array 
#include<iostream>
using namespace std;

// Approach 1 : Linear serach O(n)
int freq_linearserach(int arr[], int n , int k){
    int freq=0;
    for ( int i =0;i<n;i++){
        if(arr[i]==k)
            freq++;
    }
    return freq;
}


// Approach 2 : frequency using binary serach  O(Log n + count) 
int bs(int arr[], int l , int r , int k){
    if(r < l) return -1;
    int m = l + (r - l) / 2;
    if(k==arr[m])
        return m;
    if(k<arr[m])
        return bs(arr,l,m-1,k);
    else
        return bs(arr,m+1,r,k);
}
int freq_bs(int arr[], int n , int k){
    int location = bs(arr, 0, n-1,k );
    if (location == -1)
        return 0;

    int count = 1;
    int left = location - 1;
    while (left >= 0 && arr[left] == k)
        count++, left--;

    int right = location + 1;
    while (right < n && arr[right] == k)
        count++, right++;
 
    return count;
}

int main(){
     int arr[]={4,4,5,6,9,13,16};
     int n = sizeof(arr)/sizeof(arr[0]);
    //  cout << freq_linearserach(arr, n , 4);
    cout << freq_bs(arr, n, 4);
}