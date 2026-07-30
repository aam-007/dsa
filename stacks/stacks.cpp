#include <iostream>
using namespace std;

const int MAX = 5;

// Structure
struct Stack
{
    int arr[MAX];
    int top;
};

// Function Prototypes
void initialize(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack &s, int item);
void pop(Stack &s);
void peek(Stack s);
void display(Stack s);

int main()
{
    Stack s;

    initialize(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    display(s);

    peek(s);

    pop(s);

    display(s);

    return 0;
}

// Function Definitions

void initialize(Stack &s)
{
    s.top = -1;
}

bool isEmpty(Stack s)
{
    return (s.top == -1);
}

bool isFull(Stack s)
{
    return (s.top == MAX - 1);
}

void push(Stack &s, int item)
{
    if (isFull(s))
    {
        cout << "Stack Overflow\n";
        return;
    }

    s.top++;
    s.arr[s.top] = item;
}

void pop(Stack &s)
{
    if (isEmpty(s))
    {
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Popped element: " << s.arr[s.top] << endl;
    s.top--;
}

void peek(Stack s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Top element: " << s.arr[s.top] << endl;
}

void display(Stack s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements (Top to Bottom): ";

    for (int i = s.top; i >= 0; i--)
    {
        cout << s.arr[i] << " ";
    }

    cout << endl;
}