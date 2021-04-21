//
// Created by altanai on 4/12/21.
//
#include <iostream>
#include <string>
using namespace std;
// Counting Substrings: In a given text, find the number of substrings that start with an A and end with B

// For a string of size n
// Substrings start character A can be in any position i where i >=0 and < n-1
// Substring’s end character B after start character A determines the count
//
// Algorithm SubstringSearch (T[0..n-1])
// Search substrings whose start character is A and end character is B
// Inout : array of 0.. N-1 characters
// Output : Number of substrings with start A and end B
//
//Count <-0
//for i <- 0 to n-2 do
//    if T[i] = A do
//        for j <-i to n-1 do
//            If T[j] = B do
//                count <- count +1
//return count

int countsubstring1(string text, int n , char startchar, char endchar) {

    // base cases
    if (n == 1)
        return 1;
    if (n <= 0)
        return 0;

    int count = 0; // Number of A's seen

    // Count of substrings that starts with an A at a given position i (0 ≤ i<n − 1) in the text is equal to the number of B’s to the right of that position.
    for (int i = 0; i < n-1; i++) {
        if (text[i] == startchar) {
            for(int j = i; j<n ;j++){    // scan to all end char following the startchar
                if (text[j] == endchar) {
                    count++;
                }
            }
        }
    }
    return count;
}


// optimization
int countsubstring2(string text, int n , char startchar, char endchar) {

    int countA = 0; // Number of A's seen
    int totalcount = 0;

    cout<< "\n text "<< text;
    cout<< "\n textsize "<< n;
    cout<< "\n startchar "<< startchar;
    cout<< "\n endchar "<< endchar<<"\n";

    for (int i = 0; i < n; i++) {
        if (text[i] == startchar) {
            countA ++ ;
        } else if (text[i] == endchar) {
            totalcount = totalcount+ countA;
        }
    }

    return totalcount;
}

int main() {

    string text = "CABAAXBYA";
    int textsize = text.length();
    char startchar = 'A', endchar= 'B';

    cout << "Count substring1 \n";
    cout<< countsubstring1(text, textsize, startchar, endchar);

    cout << "Count substring2 \n ";
    cout<< countsubstring2(text, textsize, startchar, endchar);
}


//  g++ -o substring.out  countsubstring.cpp
//  ./substring.out