#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    cout << gcd(24, 16);
    return 0; 
}

int gcd(int a, int b){
    if (b==0){
        return a; // base case
    }

    return gcd(b, a%b);
}