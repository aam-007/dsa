// recusrive GCD

#include <iostream>

int gcd(int a, int b){
    if (b==0){
        return a; // base case
    }

    return gcd(b, a%b); 
}

int main(){
    int a {18};
    int b {12};

    gcd(a, b); 
    return 0; 
}