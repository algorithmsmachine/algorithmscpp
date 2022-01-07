#include<iostream>
using namespace std ;

// check palindrome using recussion 
bool palindrome_checker(char str[], int l , int r){
    cout << "left "<< l << " right "<< r<< endl;
    if(l>=0){
        if(str[l]!= str[r]) return false;
        palindrome_checker(str,--l,++r);
    }
    return true;
}

int main(){
    char str[]={'n','i','t','i','n'};
    int n = sizeof(str)/sizeof(str[0]);
    
    int l , r;
    if(n%2==0){
        l = n/2-1;
        r = n/2;
    }else{
        l= n/2-1;
        r= n/2+1;
    }

    cout << palindrome_checker(str, l, r);
    return 0;
}