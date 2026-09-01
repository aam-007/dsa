/*
A basic linked list implimentation:

create a struct called node, with a data variable (to store data), and
a pointer next to point towards other nodes

*/

#include <iostream>

struct Node{
    int data;
    Node* next; 
};

int main(){
    
    // creating nodes:
    Node* head = new Node; // creates a pointer "head" which is set to a dynammically allocated Node (dynamic allocation done using keyword "new")
    Node* second = new Node;
    Node* third = new Node;
    Node* tail = new Node;
    
    head->data = 10; // from head, get data and set it to 10 (setting value)
    head->next = second;  // from head, get next, and set it to the second node's pointer (pointing to next node)

    second->data = 20;
    second->next = third; 

    third->data = 30;
    third->next = tail; //pointer which points to nothing

    tail->data = 40;
    tail->next = nullptr; 

    Node* temp = head;

    while (temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next; 
    }
    return 0; 
}