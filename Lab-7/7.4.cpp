//Program to remove immediate left character of '+' character in a string
#include <stdio.h>
#include <string.h>
#define SIZE 100  
class Stack {
private:
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top < SIZE - 1) {
            arr[++top] = c;
        }
    }
    void pop() {
        if (top >= 0) {
            top--;
        }
    }
    void display() {
        for (int i = 0; i <= top; i++) {
            printf("%c", arr[i]);
        }
        printf("\n");
    }
};
//Function to process the string
void processString(char str[]) {
    Stack s;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '+') {
            s.pop(); 
        } else {
            s.push(str[i]); 
        }
    }
    s.display();  
}
int main() {
    char input[SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    printf("Output: ");
    processString(input);
    return 0;
}
