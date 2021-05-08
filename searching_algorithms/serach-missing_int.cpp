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
 

//  void doSomething(int n) {
//    if (n <= 1) {
//       cout << "MATH" << endl;
//       cout << "MATH" << endl;
//    } else {
//       cout << "MATH" << endl;
//       cout << "MATH" << endl;
//       doSomething(n/3);
//    }
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

// Driver Code
int main()
{   
    int arr[] = {0};
    // cout << MissingNumber(arr);

    // doSomething(7);

    FindIndexKey(arr);
}