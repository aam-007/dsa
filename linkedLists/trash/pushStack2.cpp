#include <iostream>

struct Node{
    int data;
    Node* next; 
}; 

void push(Node* &top, int value){
    Node* newNode = new Node; 
    newNode->data = value; 
    newNode->next = top;
    
    top = newNode; 

}

int main(){

    Node* top = nullptr; //initialise top. Points to nothing at first 

    push(top, 60);
    push(top, 90); 

    Node* temp = top;

    while (temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next; 
    }

    return 0; 
}