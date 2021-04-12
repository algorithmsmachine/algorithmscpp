// Linear congruential generator (LCG)
// Simple algorithm that yields a sequence of pseudo-randomized numbers calculated with a discontinuous piecewise linear equation
// prev = (A * prev + C) % M;

#include <iostream>
#include <cmath>

static const int A = 1664525; // mutiplier 
static const int C = 1013904223; // increment
static const int m = pow(2,32); // modulus

int rand()
{
    static int prev = 1;
    prev = (A * prev + C) % m;
    return prev;
}

int main(int argc, char **argv)
{
    for(int i=0; i<10; i++)
    std::cout << rand() << " - " ;
    return 0;
}

// output 1 

// g++ -o randomgenerator LinearCongruentialPseudoRandomGenerator.cpp
// ./randomgenerator

// Ref : https://stackoverflow.com/questions/30696522/linear-congruential-generator-in-c
// https://en.wikipedia.org/wiki/Numerical_Recipes