#include <iostream>
#include <cstddef>

constexpr std::size_t MAX {10};

bool isOverflow(const std::size_t stack[], const int top){
    if (top == MAX-1){
        std::cout << "overflow!";
        std::cout << '\n';
    }
    std::cout << "not overflow!" << '\n'; 
    return false;
}

bool isUnderflow (const std::size_t stack[], const int top){
    if (top == -1){
        std::cout << "Is Underflow!" << '\n';
        return true;
    }

    std::cout << "not underflow \n";
    return false;
}

int main(){
    std::size_t stack[MAX] = {};
    int top{-1};

    isOverflow(stack, top); 
    isUnderflow(stack, top); 

    return 0;
}