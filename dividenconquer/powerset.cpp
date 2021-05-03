// Power Set 

// generating the power set of a set of n elements. 
// The power set of a set S is the set of all the subsets of S, including the empty set and S itself.
// Decrease-by-one algorithm 

// S = {a, b, c} then
// P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}. 

#include<iostream>
using namespace std;
#include<string>
#include<math.h>


// approach 1 : iterative 
// Run for binary counter = 000 to 111
// Value of Counter            Subset
//     000                    -> Empty set
//     001                    -> a
//     010                    -> b
//     011                    -> ab
//     100                    -> c
//     101                    -> ac
//     110                    -> bc
//     111                    -> abc
// void powerset(char arr[] , int n){

//     // string p[]={{},arr};
//     int pn = pow(2,n);
//     for(int i=0; i<pn; i++){
//         for(int j=0; j<n; j++){
//             /* Check if jth bit in the counter i is set
//             If set then print jth element from set */
//             if(i & (1<<j))
//                 cout << arr[j];
//         }
//         cout<< endl;
//     }
// }


// approach 2 : recursive 
// void powerset(char arr[] , int n, string parr[]){

//     parr={"empty"};
//     int pn = pow(2,n);

//     return;
// }
// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
// void powerset(string str, int index = -1, string curr = "")
// {
//     int n = str.length();
  
//     // base case
//     if (index == n)
//         return;
  
//     // First print current subset
//     cout << curr << "\n";
  
//     // Try appending remaining characters
//     // to current subset
//     for (int i = index + 1; i < n; i++) {
  
//         curr += str[i];
//         powerset(str, i, curr);
  
//         // Once all subsets beginning with initial "curr" are printed, 
//         // remove last character to consider a different prefix of subsets.
//         curr.erase(curr.size() - 1);
//     }
//     return;
// }


//approach 3 :  subsets of A = {a 1 , . . . , a n } can be divided into two groups: those that do not contain a n and those that do.
// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerset(string str, int index = 0, string curr = "")
{
    int n = str.length();
  
    // base case
    if (index == n) {
        cout << curr << endl;
        return;
    }
    // two cases for every character. 
    //(i) Consider current character as part of current subset 
    //(ii) Do not consider current character as part of current subset.
    powerset(str, index + 1, curr + str[index]);
    powerset(str, index + 1, curr);
}

// Approach 4 : pick each element one by one from the input set, then generate subset for the same  

int main(){
    char arr[]={'a','b','c'};
    int n = sizeof(arr)/sizeof(arr[0]);

    // appriach 1 
    // powerset(arr, n);

    // string *parr[]={};
    // powerset(arr, n, &parr);
    // cout<< parr;

    string str = "abc";
    powerset(str);

    return 0;
}

// g++ -o powerset.out powerset.cpp
// ./powerset.out