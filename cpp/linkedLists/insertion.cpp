#include <iostream>

namespace DynamicMemeory::LinkedLists{
    struct Node{
        int data;
        Node* next; 
    };

    void insert(Node*& head){
        int numOfElements;
        std::cout << "Entrer num of elements: "; std::cin>>numOfElements; std::cout<<'\n'; 

        Node* tail {nullptr}; 

        for (auto k{0}; k<numOfElements; ++k){
            int item;
            std::cout << "Entrer num: "; std::cin>>item; std::cout<<'\n'; 

            Node* block = new Node {item, nullptr};

            if (head==nullptr){
                head = block;
                tail = block; 
            }

            else{
                tail->next = block;
                tail = block; 
            }
            
        }
    }

    void disp(const Node* head){
        while (head != nullptr){
            std::cout << head->data << " -> ";
            head = head->next; // ~~ head = head + 1 OR ++head
        }

        std::cout<<"nullptr"; 
    }

    void clear(Node* &head){
        while (head!=nullptr){
            Node* temp = head;
            head = head->next; 
            delete temp; 
        }
    }
}

int main(){
    DynamicMemeory::LinkedLists::Node* head {nullptr}; 

    DynamicMemeory::LinkedLists::insert(head);
    DynamicMemeory::LinkedLists::disp(head);
    DynamicMemeory::LinkedLists::clear(head);

    return 0; 


}