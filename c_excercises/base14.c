// Add 2 numbers in abse 14 

// 1. Convert both i/p base 14 numbers to base 10.
// 2. Add numbers.
// 3. Convert the result back to base 14.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Todo: doesnt work 
int convertToBase10(char c){
    if(c>='0' && c<='9')
        return c-'0';
    else if(c>='A' && c<='D')
        return c-'A'+10;
    // assert(0);
}

int convertToBase14(int n){
    if(n>=0 && n<=9){
        return n+'0';
    }else if(n>=10 && n<=14){
        return n-10+'A';
    }
    // assert(0);
}

int main(){

    // for base 14 
    // 0..9 then A,B,C,D,E
    char *num1base14 = "DC2"; 
    char *num2base14 = "0A3";
    char *resultbase14= (char*) malloc(sizeof(char)*(sizeof(num1base14+1))) ;
    // Add digots one by one
    // start form back and use carry 
    bool carry = 0;
    for(int i=sizeof(num1base14)-1; i>=0; i--){
        // get the value of each digit
        int num1 = convertToBase10(num1base14[i]);
        int num2 = convertToBase10(num2base14[i]);

        // add the digits
        int sum = num1 + num2 + carry;

        // if sum is greater than 9 then carry is 1
        if(sum > 9){
            carry = 1;
            sum = sum - 10;
        }else{
            carry = 0;
        }

        // print the sum
        // printf("%d", sum);
        resultbase14[i+1]= convertToBase14(sum);
    }

        if(carry==0){
            printf("%s" , resultbase14);
            return 0;
        }
        resultbase14[0]='1';
        printf("%s" , resultbase14);
        return 0;

}