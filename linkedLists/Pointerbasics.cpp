#include <iostream>

int main(){
    int x = 10;
    int *p = &x;  // pointer p points towards value stored in x 
    *p = 50; // changing value using pointer
    std::cout << x; 
    return 0; 
}