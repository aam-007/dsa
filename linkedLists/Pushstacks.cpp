#include <iostream>

struct Node{
    int data;
    Node* next; 
};

void push(Node*& top, int value){

    Node* newNode = new Node; // create an empty node and let newNode point to it 

    newNode->data=value; //from new node, get data and set it to value 
    newNode->next = top; // from newNode get next and set it to top

    top = newNode; // set top to new node 
}


int main() {

    Node* top = nullptr;

    push(top, 10);
    push(top, 20);
    push(top, 30);

    // Display stack
    Node* temp = top; // create a pointer temp and set it to top

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}