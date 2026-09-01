#include <iostream>
#include <utility>

namespace DynamicMemory {

    struct Node {
        int data;
        Node* next;
    };

    void insert(Node*& n) {
        int numOfElements;

        std::cout << "Enter number of elements: ";
        std::cin >> numOfElements;

        Node* tail = nullptr;

        for (int k = 0; k < numOfElements; ++k) {
            int num;

            std::cout << "Enter number: ";
            std::cin >> num;

            Node* block = new Node{num, nullptr};

            // First node
            if (n == nullptr) {
                n = block;
                tail = block;
            }
            // Add subsequent nodes
            else {
                tail->next = block;
                tail = block;
            }
        }
    }

    void print(const Node* n) {
        while (n != nullptr) {
            std::cout << n->data << " -> ";
            n = n->next;
        }

        std::cout << "nullptr\n";
    }

    void destroy(Node*& n) {
        while (n != nullptr) {
            Node* temp = n;
            n = n->next;
            delete temp;
        }
    }
}

int main() {
    DynamicMemory::Node* head = nullptr;

    DynamicMemory::insert(head);

    std::cout << "\nLinked list: ";
    DynamicMemory::print(head);

    DynamicMemory::destroy(head);

    return 0;
}