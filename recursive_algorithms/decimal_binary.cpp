// decimal to binary conversion 
#include<iostream>
using namespace std;

// time Complexity 
// decimal to binary algorithm contains a loop that depends on the value associated with the number 
// but the range is divided in half at each iteration. 
// Thus this is similar to the binary search algorithm and is of complexity O(log x)

// int Tobinary(int num ){
//     static long binarynum;
//     static int r, factor =1 ;

//     if(num !=0){
//         r = num%2;
//         binarynum = binarynum + r *factor;
//         factor *= 10;
//         Tobinary(num/2);
//     }
    
//     return binarynum;
// }

int Tobinary(int n)
{
    static int i;
    if(n<=1)
        return n;
    return Tobinary(n/2)*10+(n%2);
}

int main(){
    int num = 66;
    cout << Tobinary(num);

}