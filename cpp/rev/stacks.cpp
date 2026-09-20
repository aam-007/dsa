#include <iostream>

namespace Stacks {
    constexpr int MAX {100};

    struct stack{
        int arr[MAX];
        int top{-1};
        int item;
    };

    bool isOverFlow(const stack &s){
        return (s.top==MAX-1);
    }
    bool isUnderFlow(const stack &s){
        return (s.top==-1);
    }

    void push(stack &s){
        if (isOverFlow(s)){
            std::cout << "Overflow!";
        }

        ++s.top;
        s.arr[s.top] = s.item;
        std::cout << "Element added to stack";

    }

    int pop(stack &s){
        if (isUnderFlow(s)){
            return -1;
        }

        int poppedItem{s.top};
        --s.top; 
        return poppedItem;
    }
}