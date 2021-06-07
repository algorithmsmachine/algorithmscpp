#include <iostream>
using namespace std;
 
// int summation(int a[], int n)
// {
//     int total = (n + 1) * (n + 2) / 2;
//     for (int i = 0; i <= n-1; i++)
//         total -= a[i];
//     return total;
// }

// int MissingNumber(int a[]){
//     int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10  };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int miss = summation(arr, n);
//     return miss;
// } 

int matchindex(int arr[], int l, int r){
    if(l>r) return -1;
    int m = (l+r)/2;
    if(arr[m]=m) return m ;
    else if(arr[m]>m) matchindex(arr,l,m-1);
    else matchindex(arr,m+1,r);
}

int FindIndexKey(int a[]){
    int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10  };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = matchindex(arr, 0, n);
    cout << miss;
}

// approach 1 : Kth missing number in sorted ordered array 
// O(n)
int kthmissingnumber(int arr[], int n , int kth){
    int missngnum=0;
    int contigiousdiff =0;
    bool flag=0;
    for(int i=0;i<n-1;i++){                 // 1. iterated on all elemets
        contigiousdiff = arr[i+1]-arr[i]-1; // 2. Take diff between consequitive elems
        if(contigiousdiff >= kth){          // 3. check if diff >= kth
            missngnum = arr[i]+kth;         // 3.1. missing num = arr[i] + kth
            flag = 1;                       
            break;
        }else{
            kth-=contigiousdiff;            // 3.2 else keep iterating 
        }
    }

    if(flag)
        return missngnum;
    else
        return  -1;
}


//approach 2 : Kth missing element i arr using binary serach 
// int kthmissingnumber_bs(int arr[],int n , int kth){
//     int l = 0, r = n - 1, m;
//     while(l <= r){
//     m = (l + r)/2;
//     int lm = arr[m] -(m + 1);
//     if( lm ==kth){
//         if(m > 0 && (arr[m - 1] - m) == kth){
//             r = m - 1;
//             continue;
//         }
//         return arr[m]-1;
//     }
//     if(lm < kth){
//         l=m+1;
//     }else if(kth < lm ){
//         r = m-1;
//     }

//     if(r < 0)
//         return kth;
//     int less = arr[l] - (l + 1);
//         kth -= less;
   
//       // Return arr[u] + k
//     return arr[r] + kth;
// }


int main(){   
    // int arr[] = {0};
    // cout << MissingNumber(arr);

    // FindIndexKey(arr);

    int arr[] = {2, 3, 5, 9, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << kthmissingnumber(arr, n,1 );
}