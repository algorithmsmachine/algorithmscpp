#include<iostream>
#include<climits>
using namespace std;


// Approach 1 : contigious subarray
// O(n^2)
int contigious_subarray(int arr[], int n){
    int sumlast = INT_MIN, sumnow =0;
    for( int i=0;i<n;i++){
        sumnow += arr[i];
        if(sumlast < sumnow){
            sumlast = sumnow;
        }
        if(sumnow < 0) {
            sumnow = 0;
        }
    }
    return sumlast;
}

// Approach 2 : Divide and conquer contigious subarray ( similar to Merge Sort )
// T(n) = 2T(n/2) + Θ(n) 
// case II of Master Method and solution of the recurrence is Θ(nLogn).
int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int maxcrossingsum(int arr[], int l , int m , int r){

    int lsum = INT_MIN, sumnow=0;
    for(int i=m; i>=l; i--){
        sumnow+=arr[i];
        if(lsum < sumnow){
            lsum= sumnow;
        }
    }

    int rsum = INT_MIN;
    sumnow =0;
    for(int i=m+1; i<=r; i++){
        sumnow+=arr[i];
        if(rsum < sumnow){
            rsum= sumnow;
        }
    }

    return max (lsum + rsum , lsum , rsum );
}

int dccontigious_subarray(int arr[], int l , int r){
    if(l==r)
        return arr[l];

    int m = (l+r)/2;
    return max(dccontigious_subarray(arr, l, m ), 
                dccontigious_subarray( arr, m+1,r),
                maxcrossingsum(arr,l,m,r));
}


int main(){
    // int arr[]={-5,1,7,-2,4,0};
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout << contigious_subarray(arr,n);
    cout << dccontigious_subarray(arr,0, n-1);
}