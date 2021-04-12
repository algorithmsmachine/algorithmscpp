// chessboard and grain
//  If a chessboard were to have wheat placed upon each square such that one grain were placed on the first square, two on the second, four on the third, and so on (doubling the number of grains on each subsequent square), how many grains of wheat would be on the chessboard at the finish?

//
// Created by @altanai on 31/03/21.
//

#include <iostream>
using namespace std;

int main() {
    cout << "chessboard and grain";
    uintmax_t grains = 1; // note int and long fail to evalute inetger size above 2^4 and 2^6 respectively 
    // even with uintmax_t , calculation does not proceed after 18446744073709551615 
    // chessboard has 64 squares
    // we start with 1 grain on first square
    for(int i=2; i<=64; i++){
        cout << "\n square number : " << i;
        grains += grains + (grains * grains);
        cout << " grains " << grains;
    }
    cout << "\n Total grains : " << grains;
}

// g++ -o chessgrain  chessgrain.cpp
// ./chessgrain

// Ref : https://en.wikipedia.org/wiki/Wheat_and_chessboard_problem#Solutions

// Num of grains of wheat on the first half of the chessboard is 1 + 2 + 4 + 8 + ... + 2,147,483,648, for a total of 4,294,967,295 (2^32 − 1) grains, or about 279 tonnes of wheat (assuming 65 mg as the mass of one grain of wheat).
// Num of grains of wheat on the second half of the chessboard is 2^32 + 2^33 + 2^34 + ... + 2^63, for a total of 2^64 − 2^32 grains.
// On the 64th square of the chessboard alone, there would be 263 = 9,223,372,036,854,775,808 grains, more than two billion times as many as on the first half of the chessboard.
// On the entire chessboard there would be 2^64 − 1 = 18,446,744,073,709,551,615 grains of wheat, weighing about 1,199,000,000,000 metric tons. 
// This is about 1,645 times the global production of wheat (729,000,000 metric tons in 2014 and 780.8 million tonnes in 2019)