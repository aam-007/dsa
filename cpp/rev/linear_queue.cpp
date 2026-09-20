#include <iostream>
#include <cstddef>

namespace LDS {

constexpr std::size_t MAX{10};

enum class STATUS {
    OVERFLOW,
    UNDERFLOW,
    OK
};

struct Queue {
    int arr[MAX];
    int front{-1};
    int rear{-1};
};

STATUS isOverflow(const Queue& q) {
    if (q.rear == static_cast<int>(MAX) - 1)
        return STATUS::OVERFLOW;

    return STATUS::OK;
}

STATUS isUnderflow(const Queue& q) {
    if (q.front == -1)
        return STATUS::UNDERFLOW;

    return STATUS::OK;
}

STATUS enQueue(Queue& q, int item) {
    if (isOverflow(q) == STATUS::OVERFLOW) {
        std::cout << "Queue full!\n";
        return STATUS::OVERFLOW;
    }

    if (q.front == -1)
        q.front = 0;

    q.arr[++q.rear] = item;

    return STATUS::OK;
}

STATUS deQueue(Queue& q) {
    if (isUnderflow(q) == STATUS::UNDERFLOW) {
        std::cout << "Queue empty!\n";
        return STATUS::UNDERFLOW;
    }

    ++q.front;

    if (q.front > q.rear) {
        q.front = -1;
        q.rear = -1;
    }

    return STATUS::OK;
}

STATUS peek(const Queue& q) {
    if (isUnderflow(q) == STATUS::UNDERFLOW) {
        std::cout << "Queue empty!\n";
        return STATUS::UNDERFLOW;
    }

    std::cout << "Front element: " << q.arr[q.front] << '\n';
    return STATUS::OK;
}

STATUS back(const Queue& q) {
    if (isUnderflow(q) == STATUS::UNDERFLOW) {
        std::cout << "Queue empty!\n";
        return STATUS::UNDERFLOW;
    }

    std::cout << "Rear element: " << q.arr[q.rear] << '\n';
    return STATUS::OK;
}

STATUS display(const Queue& q) {
    if (isUnderflow(q) == STATUS::UNDERFLOW) {
        std::cout << "Queue empty!\n";
        return STATUS::UNDERFLOW;
    }

    std::cout << "Queue: ";

    for (int i = q.front; i <= q.rear; ++i)
        std::cout << q.arr[i] << ' ';

    std::cout << '\n';

    return STATUS::OK;
}

int size(const Queue& q) {
    if (isUnderflow(q) == STATUS::UNDERFLOW)
        return 0;

    return q.rear - q.front + 1;
}

bool isEmpty(const Queue& q) {
    return isUnderflow(q) == STATUS::UNDERFLOW;
}

} // namespace LDS

int main() {
    LDS::Queue q;

    LDS::enQueue(q, 10);
    LDS::enQueue(q, 20);
    LDS::enQueue(q, 30);

    LDS::display(q);

    LDS::peek(q);
    LDS::back(q);

    std::cout << "Size: " << LDS::size(q) << '\n';

    LDS::deQueue(q);
    LDS::display(q);

    LDS::deQueue(q);
    LDS::deQueue(q);

    LDS::display(q);

    return 0;
}
