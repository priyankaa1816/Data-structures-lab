//Program to implement stack using array
#include <stdio.h>
#define SIZE 5

class Stack {
private:
    char stack[SIZE];
    int top;

public:
    Stack() {
        top = -1; 
    } 
    void push();
    void pop();
    void peek();
    
};

int main() {
    Stack s;
    int choice;
    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            s.push();
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.peek();
        }
        else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }
        else{
            printf("Invalid choice, try again.\n");
        }
        
    }
    return 0;
}
//Function to push character in array
void Stack::push() {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    char ch;
    printf("Enter character to push: ");
    scanf(" %c", &ch);
    stack[++top] = ch;
    printf("%c pushed to stack.\n", ch);
} 
// Function to pop character from array
void Stack::pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    printf("%c popped from stack.\n", stack[top--]);
}
// Function to display top in array
void Stack:: peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %c\n", stack[top]);
}