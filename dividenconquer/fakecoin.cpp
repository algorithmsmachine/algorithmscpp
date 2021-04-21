//  Fake Coin problem / Coin weighing

//You have nine coins. Two of them are fake, and are lighter than the rest. You
//have a scale with two sides. You can put an arbitrary number of coins on each
//sides and observe if the two sides have equal weight or not, and which side is
//lighter.

//Procedure for identifying one fake coin out of three: 
//compare two coins, leaving one coin aside.
//if the weighing shows different weights
//then
//the lighter coin is the fake one,
//else
//the remaining coin is fake

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// Approach 1 : decrease-by-constant-factor 2 algorithm 
// The fake coin problem can be solved recursively using the decrease-by-constant factor strategy.
int findfakecoin2(int arr[], int l, int r){    
    int lastcoin;

    cout << "\n findfakecoin2 between " << l << " to " << r;

    if(r==l ){ // only one coin 
        return r;
    }

    if((r-l) <= 1){ // two coins to compare 
        cout << "\n Only 2 elements left to compare l "<< l << ":"<<  arr[l] << " and r "<< r << ":"<< arr[r];;
        if(arr[l] < arr[r]) return l;
        else return r;
    }

    if( (r+1)%2 != 0) { // separate out remaining coins
        cout << "\n pile not equally divisible by 2, keep last coin seprate at "<< r;
        lastcoin = r;
        r--;
    }

    int m = (r-l)/2;
    cout << "\n divide middle at "<< m;
    int sumpile1=0, sumpile2=0;
    for (int i=0; i <= m ; i++){

        sumpile1 += arr[i];
        sumpile2 += arr[m+1+i];
    }

    cout << "\n sum of pile 1 " << sumpile1;
    cout << "\n sum of piles 2 " << sumpile2;

    if(sumpile1 < sumpile2){
        findfakecoin2(arr,0,m);
    }else if(sumpile2 < sumpile1){
        findfakecoin2(arr, m+1,r);
    }else{
        return lastcoin;
    }
}


// Approach 2 :  decrease-by-constant-factor 3 algorithm 
// if n = 1 then
//    the coin is fake
// else
//    divide the coins into piles of A = ceiling(n/3), B = ceiling(n/3), and C = n-2*ceiling(n/3)
//    weigh A and B
//    if the scale balances then
//       iterate with C
//    else
//       iterate with the lighter of A and B

int dividebyfactor3(int arr[], int l, int r){

    cout << "\n dividebyfactor3 between " << l << " to " << r;
    if(r<=0 || r-l==0) return l; // one position for fake coin in pile 

    int sumpile[3]={0};
    int t = (r+1-l)/3;
    cout << "\n divide at 1/3 t "<< t;

    for (int i=0; i < t; i++){    // make 3 piles
        sumpile[0] += arr[l+i];
        sumpile[1] += arr[l+t+i];
        sumpile[2] += arr[l+2*t+i];
    }

    cout << "\n sum of piles " << sumpile[0] << " : " << sumpile[1] << " : " << sumpile[2];
 
    if(sumpile[0] == sumpile[1] && sumpile[0] == sumpile[2]){
        cout << "\n sum of all piles is same  " << sumpile[0];
        return -1;
    }
    else if (sumpile[1] == sumpile[2] ){
        cout << "\n sum of pile 1 " << sumpile[0] << " is the smallest from other sum of piles " << sumpile[2];
        dividebyfactor3(arr, l, l+t-1);
    }else if ( sumpile[0] == sumpile[2] ){
        cout << "\n sum of pile 2 " << sumpile[1] << " is the smallest from other sum of piles " << sumpile[2];
        dividebyfactor3(arr, l+t, l+2*t-1);
    }else{
        cout << "\n sum of pile 3 " << sumpile[2] << " is the smallest from other sum of piles " << sumpile[0];
        dividebyfactor3(arr, l+2*t, l+r);
    }

}


int findfakecoin3(int arr[], int n, int l, int r){

    cout << "\n Total coins " <<  n;

    if(n <1){ // no coin to compare
        return -1;
    }

    if(n==1 ){ // only one coin 
        return r;
    }

    if(n==2 ){ // two coins to compare 
        cout << "\n Only 2 elements left to compare l "<< l << ":"<<  arr[l] << " and r "<< r << ":"<< arr[r];;
        if(arr[l] < arr[r]) return l;
        else return r;
    }

    int lastcoins[2];
    if(r==(n-1)){  //Fake coin exists in last coins, compare them
        if( ceil(n%3) > 0) {
            cout << "\n pile of n "<< n <<" is not equally divisible by 3, keep last coins seprate ";
            lastcoins[0] = n-1;
            cout << "\n last coin index " << lastcoins[0] ;
            r--;
        }
        if( ceil(n%3) > 1){
            lastcoins[1] = n-2;
            cout << "\n second last coin " << lastcoins[1] ;
            r--;
        }
    }

    int posfake = dividebyfactor3( arr, l, r);
    if(posfake==-1){
        cout << "\n Fake coin exists in last coins, compare them ";
        if(lastcoins[0] < lastcoins[1]){
            return lastcoins[0];
        }else {
            return lastcoins[1];
        }
    }else{
        return posfake;
    }
}

int main(){
    int coins[]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,5} ;
    // int coins[]={10,10,10,9,10,10,10,10} ;
    // int coins[]={10,10,10,9,10,10,10,10,10} ;
    // int coins[]={10,10,10,9,10} ;
    // int coins[]={10,9,10} ;
    // int coins[]={10,9};
    // int coins[]={9};
    // int coins[]={};
    int n = sizeof(coins) / sizeof(coins[0]);

    // int position = findfakecoin2(coins,0,n-1);
    // cout << "\n Fake coin position "<< position << "-" << coins[position];

    int position = findfakecoin3(coins, n, 0,n-1);
    cout << "\n Fake coin position "<< position << "-" << coins[position];

}

// g++ -o fakecoin.out fakecoin.cpp
//./fakecoin.out