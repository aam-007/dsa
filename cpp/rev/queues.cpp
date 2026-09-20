#include <iostream>
#include <cstddef>

/*
Queue

Front _ _ _ _ _ Rear

Funcs
bool isEmpty()
bool isFull()
void enQueue()
void deQueue()
void peek()
void back()
void disp()


Prog structure:

namespace QueueDS
MAX {10}
struct Queue {arr, front, back }

*/

namespace QueueDS{
    constexpr std::size_t MAX {10};

    struct Queue{
        int arr[MAX];
        int front{-1};
        int back{-1};
    };

    bool isEmpty(const Queue &q){
        return (q.front == -1);
    }

    bool isFull(const Queue &q){
        return (q.back == MAX-1);
    }

    void enQueue(Queue &q, int  item){
        if (isFull(q)){
            std::cout << "Queue is full!";
            return;
        }
        if (isEmpty(q)){
            q.front = 0;
            q.back = 0;
        } else {++q.back;}

        q.arr[q.back] = item;
    }
}
