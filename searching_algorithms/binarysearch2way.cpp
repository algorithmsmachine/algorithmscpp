#include<iostream>
using namespace std;

int binarysearch2way(int arr[], int l, int r, int val){
    while(r-l>1){
        int m = (l+r)/2;
        if(arr[m]<= val)   
            l=m;
        else r=m-1;
    }
    if(arr[l]==val) return l;
    return -1;  
}

int main(){
    int arr[]={2,4,6,7,8,9};
    int n =sizeof(arr)/sizeof(arr[0]);
    int val = 2;
    cout << binarysearch2way(arr,0,n-1,val);
    return 0;
}