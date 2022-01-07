// nearest power of 4 that will get you to an input number without going over 

// for example if 66 is input 3 will be returned. The program must be done
// recursively

#include <iostream>

// T(n)=T(n/4)+1 for n>1 
// T(1)=1

int power4helper(int y, int pow){
    if(y/4==0){
        return pow;
    }
    return power4helper(y/4,pow+1);
}
int power4(int y){
    return power4helper(y,0);
}
int main() {
    int input;
    int output;
    std::cout<<"Input your number \n";
    std::cin>>input;
    output=power4(input);
    std::cout<<"output is "<<output;
}