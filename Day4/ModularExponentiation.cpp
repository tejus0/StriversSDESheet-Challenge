#include <bits/stdc++.h> // Include all standard libraries to reduce lines of code.

long long power(long long x,long long n,long long m){ // Define a function called power which takes in three long long integers.
    long long ans=1; // Set a variable called ans equal to 1.
    while(n){ // While loop runs as long as n is not zero.
        if(n&1){  // If n is an odd number,
            ans = (ans*x)%m; // Compute the remainder when ans times x is divided by m and assign it to ans.
        }
        x= (x*x)%m; // Compute the remainder when x is squared and divided by m and assign it to x.
        n =n>>1; // Right shift n by 1 bit.
    }
    return (ans)%m; // Return the remainder when ans is divided by m.
}

int modularExponentiation(int x, int n, int m) { // Define a function called modularExponentiation that takes in three integers.
    long long num = power((long long)x,(long long)n,(long long)m); // Set a long long variable called num equal to the result of calling the power function with the arguments x, n, and m.
    return num; // Return the value of num.
}