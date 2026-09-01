#include <iostream>

struct Node{
    int data;
    Node* next; 
}; 

void push(Node* &top, int value){
    Node* newNode = new Node; // creating a node
    newNode->data = value; 
    newNode->next = top; 

    top = newNode; 
}

int main(){
    Node* top = nullptr; 

    push(top, 100);
    push(top, 100);
    push(top, 100);
    push(top, 100);
    push(top, 100);

    Node* temp = top;

    while (temp!=nullptr){
        std::cout << temp->data << " ";
        temp = temp->next; 
    }

    return 0; 
}