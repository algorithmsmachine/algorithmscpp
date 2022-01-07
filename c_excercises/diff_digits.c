#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    // int n =983;
    int n =464;
    // int prevdigit=9;
    bool arr[10];
    for(int i=0;i<10;i++){
        arr[i]=false;
    }
    while (n>0)    {
        /* code */
        int digit = n%10;
        if(arr[digit]==true){
            printf("its repeated");
            return 0;
        }else{
            arr[digit]=true;
        }
        n=n/10;
    }
    printf("its all diff");
    return 0;
}