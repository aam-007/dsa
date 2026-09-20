#include <iostream>
#include <cstddef>

namespace QueueDS {

constexpr std::size_t MAX{10};

enum class STATE {
    underflow,
    overflow,
    ok
};

struct Data {
    int arr[MAX];
    int front{-1};
    int back{-1};
};

STATE isOverflow(const Data &d) {
    if (d.back == static_cast<int>(MAX) - 1)
        return STATE::overflow;

    return STATE::ok;
}

STATE isUnderflow(const Data &d) {
    if (d.front == -1)
        return STATE::underflow;

    return STATE::ok;
}

STATE enQueue(Data &d, int item) {

    if (isOverflow(d) == STATE::overflow)
        return STATE::overflow;

    if (d.front == -1)
        d.front = 0;

    ++d.back;
    d.arr[d.back] = item;

    return STATE::ok;
}

STATE deQueue(Data &d) {

    if (isUnderflow(d) == STATE::underflow)
        return STATE::underflow;

    if (d.front == d.back) {
        d.front = -1;
        d.back = -1;
    }
    else {
        ++d.front;
    }

    return STATE::ok;
}

int peek(const Data &d) {

    if (isUnderflow(d) == STATE::underflow) {
        std::cout << "Queue is empty!\n";
        return -1;
    }

    return d.arr[d.front];
}

int rear(const Data &d) {

    if (isUnderflow(d) == STATE::underflow) {
        std::cout << "Queue is empty!\n";
        return -1;
    }

    return d.arr[d.back];
}

void display(const Data &d) {

    if (isUnderflow(d) == STATE::underflow) {
        std::cout << "Queue is empty!\n";
        return;
    }

    std::cout << "Queue: ";

    for (int i = d.front; i <= d.back; ++i)
        std::cout << d.arr[i] << ' ';

    std::cout << '\n';
}

} // namespace QueueDS

int main() {

    QueueDS::Data d;

    int choice;
    int item;

    while (true) {

        std::cout << "\n===== QUEUE MENU =====\n";
        std::cout << "1. Display Queue\n";
        std::cout << "2. Enqueue\n";
        std::cout << "3. Check Empty\n";
        std::cout << "4. Check Full\n";
        std::cout << "5. Dequeue\n";
        std::cout << "6. Peek\n";
        std::cout << "7. Rear\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                QueueDS::display(d);
                break;

            case 2:

                std::cout << "Enter value: ";
                std::cin >> item;

                if (QueueDS::enQueue(d, item) == QueueDS::STATE::overflow)
                    std::cout << "Queue Overflow! Cannot insert.\n";
                else {
                    std::cout << "Element inserted.\n";
                    QueueDS::display(d);
                }

                break;

            case 3:

                if (QueueDS::isUnderflow(d) == QueueDS::STATE::underflow)
                    std::cout << "Queue is empty.\n";
                else
                    std::cout << "Queue is not empty.\n";

                break;

            case 4:

                if (QueueDS::isOverflow(d) == QueueDS::STATE::overflow)
                    std::cout << "Queue is full.\n";
                else
                    std::cout << "Queue is not full.\n";

                break;

            case 5:

                if (QueueDS::deQueue(d) == QueueDS::STATE::underflow)
                    std::cout << "Queue Underflow! Nothing to delete.\n";
                else {
                    std::cout << "Element removed.\n";
                    QueueDS::display(d);
                }

                break;

            case 6: {

                int value = QueueDS::peek(d);

                if (value != -1)
                    std::cout << "Front element: " << value << '\n';

                break;
            }

            case 7: {

                int value = QueueDS::rear(d);

                if (value != -1)
                    std::cout << "Rear element: " << value << '\n';

                break;
            }

            case 0:

                std::cout << "Goodbye!\n";
                return 0;

            default:

                std::cout << "Invalid choice.\n";
        }
    }
}