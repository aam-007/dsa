#include <stdio.h>
#include <string.h>

#define MAX 10

char stack[MAX][100];
int top =-1;

int isFull(){
    return top == MAX-1;
}

int isEmpty(){
    return top == -1;
}

void push(char operation[]){
    if (isFull){
        printf("stack full");
        return; 
    }

    ++top;
    strcpy(stack[top], operation); 

    printf("operation added"); 

}

void undo(){
    if (isEmpty){
        printf("stack empty");
        return; 
    }

    printf("undoing: %s", stack[top]);
    --top; 
}

void display(){
    if (isEmpty()){
        printf("stack is empty"); 
        return; 
    }

    for (int i =0; i<=top; ++i){
        printf("%s\n", stack[i]); 
    }
}
int main() {
    int choice;
    char operation[100];

    while (1) {

        printf("\n1. Add Operation\n");
        printf("2. Undo\n");
        printf("3. Display Operations\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter operation: ");
                scanf(" %99[^\n]", operation);

                push(operation);
                break;

            case 2:
                undo();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}