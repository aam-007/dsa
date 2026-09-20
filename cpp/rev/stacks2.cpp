#include <iostream>

// Linear Data Structures
namespace lds {

constexpr int MAX{10};

struct Stack {
    int arr[MAX];
    int top{-1};
};

bool isOverflow(const Stack &s) {
    return (s.top == MAX - 1);
}

bool isUnderflow(const Stack &s) {
    return (s.top == -1);
}

void display(const Stack &s) {
    if (isUnderflow(s)) {
        std::cout << "Underflow (Stack empty)!\n";
        return;
    }

    std::cout << "Stack elements (Top to Bottom):\n";
    for (int k = s.top; k >= 0; --k) {
        std::cout << s.arr[k] << '\n';
    }
}

void push(Stack &s, int item) {
    if (isOverflow(s)) {
        std::cout << "Overflow! Stack is full!\n";
        return;
    }

    s.arr[++s.top] = item;
    std::cout << item << " pushed into stack.\n";
}

int pop(Stack &s) {
    if (isUnderflow(s)) {
        std::cout << "Underflow! Stack is empty!\n";
        return -1;
    }

    return s.arr[s.top--];
}

int peek(const Stack &s) {
    if (isUnderflow(s)) {
        std::cout << "Underflow! Stack is empty!\n";
        return -1;
    }

    return s.arr[s.top];
}

} // namespace lds

int main() {
    lds::Stack s{};
    int choice;
    int item;

    while (true) {
        std::cout << "\n===== STACK MENU =====\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item: ";
                std::cin >> item;
                lds::push(s, item);
                break;

            case 2:
                item = lds::pop(s);
                if (item != -1)
                    std::cout << "Popped: " << item << '\n';
                break;

            case 3:
                item = lds::peek(s);
                if (item != -1)
                    std::cout << "Top element: " << item << '\n';
                break;

            case 4:
                lds::display(s);
                break;

            case 5:
                std::cout << "Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
