#include <iostream>

namespace QueueDS {

    const int MAX = 10;

    struct Queue {
        int arr[MAX];
        int front;
        int rear;
    };

    // Initialize Queue
    void init(Queue &q) {
        q.front = -1;
        q.rear = -1;
    }

    // Check if queue is empty
    bool isEmpty(const Queue &q) {
        return (q.front == -1);
    }

    // Check if queue is full
    bool isFull(const Queue &q) {
        return (q.rear == MAX - 1);
    }

    // Current size
    int size(const Queue &q) {
        if (isEmpty(q))
            return 0;

        return q.rear - q.front + 1;
    }

    // Insert element
    void enqueue(Queue &q, int value) {

        if (isFull(q)) {
            std::cout << "Queue Overflow!\n";
            return;
        }

        if (isEmpty(q))
            q.front = 0;

        q.arr[++q.rear] = value;

        std::cout << value << " inserted.\n";
    }

    // Remove element
    void dequeue(Queue &q) {

        if (isEmpty(q)) {
            std::cout << "Queue Underflow!\n";
            return;
        }

        std::cout << q.arr[q.front] << " removed.\n";

        if (q.front == q.rear) {
            // Queue becomes empty
            q.front = -1;
            q.rear = -1;
        }
        else {
            q.front++;
        }
    }

    // Front element
    int peekFront(const Queue &q) {

        if (isEmpty(q)) {
            std::cout << "Queue Empty!\n";
            return -1;
        }

        return q.arr[q.front];
    }

    // Rear element
    int peekRear(const Queue &q) {

        if (isEmpty(q)) {
            std::cout << "Queue Empty!\n";
            return -1;
        }

        return q.arr[q.rear];
    }

    // Display queue
    void display(const Queue &q) {

        if (isEmpty(q)) {
            std::cout << "Queue is Empty.\n";
            return;
        }

        std::cout << "Queue : ";

        for (int i = q.front; i <= q.rear; i++)
            std::cout << q.arr[i] << " ";

        std::cout << '\n';
    }

} // namespace QueueDS
int main() {

    using namespace QueueDS;

    Queue q;
    init(q);

    int choice, value;

    while (true) {

        std::cout << "\n===== QUEUE MENU =====\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Peek Front\n";
        std::cout << "4. Peek Rear\n";
        std::cout << "5. Display\n";
        std::cout << "6. Size\n";
        std::cout << "7. Is Empty?\n";
        std::cout << "8. Is Full?\n";
        std::cout << "9. Exit\n";

        std::cout << "\nEnter Choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                if (!isEmpty(q))
                    std::cout << "Front = " << peekFront(q) << '\n';
                break;

            case 4:
                if (!isEmpty(q))
                    std::cout << "Rear = " << peekRear(q) << '\n';
                break;

            case 5:
                display(q);
                break;

            case 6:
                std::cout << "Size = " << size(q) << '\n';
                break;

            case 7:
                std::cout << (isEmpty(q) ? "Queue is Empty\n"
                                         : "Queue is NOT Empty\n");
                break;

            case 8:
                std::cout << (isFull(q) ? "Queue is Full\n"
                                        : "Queue is NOT Full\n");
                break;

            case 9:
                std::cout << "Exiting...\n";
                return 0;      // or break; after the loop

            default:
                std::cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
