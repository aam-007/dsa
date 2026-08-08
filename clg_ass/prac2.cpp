#include <iostream>
#include <cstddef>

// lds => linear data struct
namespace lds{

    constexpr std::size_t MAX {10};

    struct Stack{
        int arr[MAX];
        int top{-1}; //init stack
    };

    bool isEmpty(const Stack &s){
        return (s.top==-1);
    }

    bool isFull(const Stack &s){
        return (s.top == MAX-1);
    }

    void push(Stack &s, const int item){
        if (isFull(s)){
            std::cout << "overflow! array full!" << '\n';
            return;
        }

        ++s.top;
        s.arr[s.top] = item;

    }

    void pop(Stack &s){
        if (isEmpty(s)){
            std::cout << "array empty! underflow" << '\n';
            return;
        }

        --s.top;
    }

    int peek (const Stack &s){
        if (isEmpty(s)){
            std::cout << "empty!";
            return -1;
        }

        return s.arr[s.top];
    }

    void display(const Stack &s){
        if (isEmpty(s)){
            std::cout << "empty!";
            return;
        }

        for (int k{s.top}; k>=0; --k){
            std::cout << s.arr[k] <<'\n';
        }
    }
}
int main() {

    lds::Stack s;

    int item, choice;

    while (true) {
        std::cout << "\n=== Stack Operations ===\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek (Top Element)\n";
        std::cout << "4. Display Stack\n";
        std::cout << "5. Check if Stack is Empty\n";
        std::cout << "6. Check if Stack is Full\n";
        std::cout << "7. Exit\n";

        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << '\n';

        switch (choice) {

        case 1:
            std::cout << "Enter element to push: ";
            std::cin >> item;
            lds::push(s, item);
            std::cout << '\n';
            std::cout << "element pushed" << '\n';
            break;

        case 2:
            lds::pop(s);
            std::cout << "Element popped!\n";
            break;

        case 3:
            if (!lds::isEmpty(s))
                std::cout << "Top element: " << lds::peek(s) << '\n';
            break;

        case 4:
            std::cout << "Stack contents:\n";
            lds::display(s);
            std::cout << '\n';
            break;

        case 5:
            if (lds::isEmpty(s))
                std::cout << "Stack is empty.\n";
            else
                std::cout << "Stack is not empty.\n";
            break;

        case 6:
            if (lds::isFull(s))
                std::cout << "Stack is full.\n";
            else
                std::cout << "Stack is not full.\n";
            break;

        case 7:
            std::cout << "Exiting...\n";
            return 0;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
