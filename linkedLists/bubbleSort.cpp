#include <iostream>
#include <utility>

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* newNode1 = new Node;
    Node* newNode2 = new Node;
    Node* newNode3 = new Node;
    Node* newNode4 = new Node;

    newNode1->data = 10;
    newNode1->next = newNode2;

    newNode2->data = 9;
    newNode2->next = newNode3;

    newNode3->data = 1;
    newNode3->next = newNode4;

    newNode4->data = 67;
    newNode4->next = nullptr;


    // BUBBLE SORT
    Node* temp = newNode1;

    for (; temp != nullptr; temp = temp->next) {

        Node* current = newNode1;

        for (; current->next != nullptr; current = current->next) {

            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
            }
        }
    }


    // DISPLAY
    for (temp = newNode1; temp != nullptr; temp = temp->next) {
        std::cout << temp->data << " ";
    }

    return 0;
}