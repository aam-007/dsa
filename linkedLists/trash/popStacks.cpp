#include <iostream>
using namespace std;

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
        cout << "Stack is empty" << endl;
        return;
    }

    Node* temp = top;
    cout << temp->data << '\n'; 

    top = top->next;

    delete temp;
}

// DISPLAY
void display(Node* top) {

    Node* temp = top;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* top = nullptr;

    push(top, 10);
    push(top, 20);
    push(top, 30);

    cout << "Stack: ";
    display(top);

    pop(top);

    cout << "After pop: ";
    display(top);

    return 0;
}