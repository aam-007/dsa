#include <iostream>

struct Node {
    int data;
    Node* next;
};

// PUSH
void push(Node*& top, int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// POP
void pop(Node*& top) {
    if (top == nullptr) {
        std::cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;

    top = top->next;

    delete temp;
}

// DISPLAY
void disp(Node* top) {
    if (top == nullptr) {
        std::cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << "\n";
}

int main() {

    // Empty stack
    Node* top = nullptr;

    // Push elements
    push(top, 10);
    push(top, 20);
    push(top, 30);
    push(top, 40);

    std::cout << "Stack after pushing: ";
    disp(top);

    // Pop one element
    pop(top);

    std::cout << "Stack after popping: ";
    disp(top);

    // Pop another element
    pop(top);

    std::cout << "Stack after popping again: ";
    disp(top);

    return 0;
}