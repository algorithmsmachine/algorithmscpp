// Recussive string reversal

#include<iostream>
using namespace std;
#define MAX 10

char* stringreverse(char str[]){

    static char revstr[MAX];
    static int i=0;
    if(*str){
        stringreverse(str+1);
        revstr[i++]= *str;
    }
    return revstr;
}

int main(){
    char str[MAX];
    printf("enyer string upto 10 chars");
    scanf("%s", str);
    cout<< stringreverse(str);
}
