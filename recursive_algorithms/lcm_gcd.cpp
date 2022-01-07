// LCM and GCD 

#include<iostream>
#include<cmath>
using namespace std;


//  Euclidean algorithm to find GCD ( Greatest Common Divisor )
// gcd (a, b) = gcd(|a%b|, |a| ); where |a| >= |b|
// gcd(p, 0) = gcd(0, p) = |p|
// example :  gcd(12, 18) = gcd(18%12, 12) = gcd(6,12) = gcd(12%6, 6) = gcd(0, 6) = 6
int gcd(int a , int b ){       // a is bigger , b is smaller 
    if(a==0 || b==0) return a+b;
    else{
        int absa = abs(a);
        int absb = abs(b);
        int bigVal = max(absa, absb);
        int smallVal = min(absa, absb);
        return gcd(bigVal%smallVal, smallVal);
    }
}

int lcm(int a , int b){        // a is smaller , b is bigger 
    static int m = 0;
    m+=b;
    if((m%a == 0) && (m%b == 0))
        return m;
    else
        lcm(a,b);
}


// approach 2  :  Euclidean Algorithm
// lcm(a, b) = |a * b|/gcd(a, b).

int lcm2(int a, int b ){    
    return a*b / gcd(a,b);
}

int main(){
    int a=4;
    int b=6;

    int gcdnum;
    if(a>=b)
        gcdnum = gcd(a,b);  
    else
        gcdnum = gcd(b,a);

    int lcmnum;
    if(a<=b)
        lcmnum = lcm(a,b);
    else
        lcmnum = lcm(b,a);

    cout<< gcdnum << endl; // 
    cout<< lcmnum << endl; // lcm 4 and 6 should be 12 
    cout<< lcmnum << endl; // lcm 4 and 6 should be 12 
}