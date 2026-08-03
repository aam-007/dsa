#include <iostream>
using namespace std;

const int MAX = 10;

struct Stack{
    int stack[MAX];
    int top=-1;
} s;

bool isOverflow(const Stack &s){
    return (s.top==MAX-1);
}

bool isUnderflow(const Stack &s){
    return (s.top==-1);
}

void push(Stack &s, int item){
    if (isOverflow(s)){
        cout << "Cannot push. Overflow!";
        return;
    }

    s.top++;
    s.stack[s.top] = item;
}

int pop (Stack &s){
    if (isUnderflow(s)){
        cout << "Cannot pop. Underflow!";
        return -1;
    }

    int popedItem = s.stack[s.top];
    s.top--;
    return popedItem;
}

int peek(const Stack &s){
    if (isUnderflow(s)){
        cout << "Empty";
        return -1; 
    }
    return s.stack[s.top];
}

void disp(const Stack &s){
    for (int k=s.top; k>=0; k-- ){
        cout << s.stack[k] << '\n';
    }
}

int size(const Stack &s){
    return s.top+1;
}

int main() {
    int choice, item;

    do {
        cout << "\n===== STACK OPERATIONS =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Check Overflow\n";
        cout << "7. Check Underflow\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> item;
                push(s, item);
                break;

            case 2:
                item = pop(s);
                if (item != -1)
                    cout << "Popped element: " << item << '\n';
                break;

            case 3:
                item = peek(s);
                if (item != -1)
                    cout << "Top element: " << item << '\n';
                break;

            case 4:
                if (isUnderflow(s))
                    cout << "Stack is empty.\n";
                else {
                    cout << "Stack contents (Top to Bottom):\n";
                    disp(s);
                }
                break;

            case 5:
                cout << "Current size: " << size(s) << '\n';
                break;

            case 6:
                if (isOverflow(s))
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is Not Full.\n";
                break;

            case 7:
                if (isUnderflow(s))
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is Not Empty.\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}