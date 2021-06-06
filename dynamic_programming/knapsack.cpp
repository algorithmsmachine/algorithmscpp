#include <iostream>
using namespace std;
// int max(int x, int y) {
//    return (x > y) ? x : y;
// }
// //Build table K[][] in bottom up manner
// int knapSack(int W, int w[], int v[], int n) {
//    int i, wt;
//    int K[n+1][W+1];
//    for (i = 0; i <= n; i++) {
//         for (wt = 0; wt <= W; wt++) {
//             if (i == 0 || wt == 0)
//                 K[i][wt] = 0;
//             else if (w[i-1] <= wt)
//                 K[i][wt] = max(v[i-1] + K[i-1][wt- w[i-1]], K[i-1][wt]);
//             else
//                 K[i][wt] = K[i-1][wt];
//       }
//    }

//    for(int i =0 ; i <= n ; i++){
//         for( int j=0; j <= W ; j++){
//             cout<< K[i][j] << " ";
//         }
//         cout<<endl;
//    }


//    return K[n][W];
// }
// int main() {
//    int n=5; 
//    int W=6;
//    int v[n]={25,20,15,40,50};
//    int w[n]={3,2,1,4,5};
//    cout << knapSack(W, w, v, n)<<endl;
//    return 0;
// }


// CPP code for Dynamic Programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
#define X 5
#define Y 5

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

//C++ does not allow to pass an entire array as an argument to a function. However, You can pass a pointer to an array
// void printArr( int arr[X][Y]){
//     for ( int i = 0; i< X; i++){
//         for (int j = 0; j<= Y; j++){
//             cout << arr[i][j]<< '\t';
//         }
//         cout << '\n';
//     }
// } 


// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            int wti = wt[i-1];
            int vali = val[i-1];

            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wti <= w)
                K[i][w] = max(vali + K[i-1][w-wti], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
 
    // stores the result of Knapsack
    int res = K[n][W];   
    printf("Largest Value in knaosack %d\n", res);
    // printArr(K);
    for ( int i = 0; i<=n; i++){
        for (int j = 0; j<=W; j++){
            cout << K[i][j]<< '\t';
        }
        cout << '\n';
    }

    w = W;
    for (i = n; i > 0 && res > 0; i--) {
         
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;       
        else {
 
            // This item is included.
            cout << "Item "<< i - 1 << " Weight "<< wt[i - 1] << " , Value "<< val[i - 1]<< endl;

            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}
 
// Driver code
int main()
{
    //    int n=5; 
    //    int W=6;
    //    int v[n]={};
    //    int w[n]={};

    // int val[] = {25,20,15,40,50 };
    // int wt[] = {3,2,1,4,5 };
    // int W = 6;

    int val[] = {10,40,30,50 };
    int wt[] = {5,4,6,3 };
    int W = 10;

    int n = sizeof(val) / sizeof(val[0]);
     
    printknapSack(W, wt, val, n);
     
    return 0;
}

// g++ knapsack.cpp -o knapsack.out
// ./knapsack.out

// Largest Value in knaosack 90
// 0       0       0       0       0       0       0       0       0       0       0
// 0       0       0       0       0       10      10      10      10      10      10
// 0       0       0       0       40      40      40      40      40      50      50
// 0       0       0       0       40      40      40      40      40      50      70
// 0       0       0       50      50      50      50      90      90      90      90
// Item 3 Weight 3 , Value 50
// Item 1 Weight 4 , Value 40