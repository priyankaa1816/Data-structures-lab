//Program to implement a stack using linked list
#include <stdio.h>
#include <stdlib.h>

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };
    Node* top;
public:
    Stack() { 
        top = nullptr;
    }
    void push();
    void pop();
    void peek();
    ~Stack(); 
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
            continue;
        }
        if (choice == 2) {
            s.pop();
            continue;
        }
        if (choice == 3) {
            s.peek();
            continue;
        }
        if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }
        printf("Invalid choice, try again.\n");
    }
    return 0;
}
// Function to push a new node onto the stack
void Stack::push() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter character to push: ");
    scanf(" %c", &newNode->data);
    newNode->next = top;
    top = newNode;
    printf("%c pushed to stack.\n", newNode->data);
}
// Function to remove the top node from the stack and free its memory
void Stack::pop() {
    if (top==NULL) {
        printf("Stack underflow! cannot pop.\n");
        return;
    }
    Node* temp = top;
    printf("%c popped from stack.\n", temp->data);
    top = top->next;
    free(temp);
}
// Function to retrieve the top element without removing it
void Stack::peek() {
    if (top==NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %c\n", top->data);
}
// Destructor to release all allocated memory in the stack
Stack::~Stack() {
    while (top!=NULL) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}
