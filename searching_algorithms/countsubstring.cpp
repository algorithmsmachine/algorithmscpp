//
// Created by altanai on 4/12/21.
//
#include <iostream>
#include <string>
using namespace std;
// Counting Substrings: In a given text, find the number of substrings that start with an A and end with a B

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
//            If T[j] =B do
//                count <- count +1
//return count

void countsubstring1(string text,char startchar, char endchar) {
    int count = 0; // Number of A's seen
    int total = 0;
    cout << total << '.';
}


// optimization
void countsubstring2(string text, char startchar, char endchar) {

    int count = 0; // Number of A's seen
    int total = 0;
    for (int i = 0; i < text.length(); i++) {
        if (i == startchar) {
            count += 1;
        } else if (i == endchar) {
            total += count;
        }
    }
    cout << total << '.';
}

int main() {
    cout << "Count substring1 \n";
    countsubstring1("CABAAXBYA", 'A', 'B');

    cout << "Count substring2 \n ";
    countsubstring2("CABAAXBYA", 'A', 'B');
}


//  g++ -o substring.out  countsubstring.cpp
//  ./substring.out