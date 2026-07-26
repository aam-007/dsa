#include <iostream>
using namespace std;

void decimalToBinary(int n);

int main(){
    decimalToBinary(10);
    return 0; 
}

void decimalToBinary(int n){
    if (n==0){
        return;
    }

    decimalToBinary(n/2);
    cout << n%2; 
}
