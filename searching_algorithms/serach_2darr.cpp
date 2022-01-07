#include<iostream>
using namespace std;
#define M 3
#define N 3
// Approach 1: Linear serach 
// int search(int mat[2][2], int n, int x){
//     if (n == 0)        return -1;
//     for(int i = 0; i < n; i++){ //traverse through the matrix
//         for(int j = 0; j < n; j++){
//             if(mat[i][j] == x){
//                 cout<<"Element found at ("<< i << ", " << j << ")\n";
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// Approach 2 : binary serach on each row
// O(n log n) algorithm
int binaryserach(int arr[], int l , int r , int key){
    if(l>=r) return -1;
    int m = (l+r)/2;
    if(arr[m]==key) {
        cout << " found it ";
        return m;
    }
    if(key<arr[m])
        return binaryserach(arr,l,m, key);
    else
        return binaryserach(arr,m+1,r, key);
}

void search_1darr(int arr[N],  int key){

    cout << binaryserach(arr,0,M,key );
    // int low = 0;
    // int high = M - 1;
    // while (low <= high) {
    //     int mid = low + (high - low) / 2;
 
    //     if (key == arr[mid]) return true;
 
    //     if (key < arr[mid][0])
    //         high = mid - 1;
    //     else
    //         low = mid + 1;
    // }
    // return false;
}

//O(n) reduce-and-conquer algorithm
void search_2darr(int arr[M][N],  int key){

    if (key < arr[0][0] || key > arr[M-1][N-1])
        cout<< " out of range";

    int low = 0;
    int high = M - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        // if the element lies in the range this row then call 1-D binary search on this row
        if (key >= arr[mid][0] && key <= arr[mid][N - 1])
            search_1darr(arr[mid], key);
 
        if (key < arr[mid][0])
            high = mid - 1;
        else
            low = mid + 1;
    }


    // int i=0;
    // while(i<m){
    //     binaryserach(arr, 0, m, 2);
    //     i++;
    // }
}
int main(){
    int n=3, m =3;
    int arr2[M][N]={ {1,2,3},
                   {4,5,6},
                   {7,8,9} };
    int key =7;

    // funnily i havent found the bext way to pass 2d awaay in paramso put it in main fnction 
    search_2darr(arr2,key);
    return 1;
}