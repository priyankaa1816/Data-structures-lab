// Program of following operations doen in circular linked list as a headef file
#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H
#include <stdio.h>
#include <stdlib.h>
class RoundRobin {
    struct Node {
        int time;
        struct Node *next;
    } *head;

    int timeQuantum; 
public:
    RoundRobin(int quantum) {
        head = NULL;
        timeQuantum = quantum;
    }

    // Insert a process at the end of the circular linked list
    void insertProcess(int val) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->time = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
        } else {
            struct Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        printf("Process with %d time inserted.\n", val);
    }

    // Execute a process using Round-Robin scheduling
    void executeProcess() {
        if (head == NULL) {
            printf("No process in queue.\n");
            return;
        }
        struct Node *temp = head;
        printf("Executing process with %d time.\n", temp->time);
        int remainingTime = temp->time - timeQuantum;
        if (head->next == head) { 
            free(head);
            head = NULL;
        } else {
            struct Node *last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            free(head);
            head = last->next;
        }
        if (remainingTime > 0) {
            insertProcess(remainingTime);
        } else {
            printf("Process completed execution.\n");
        }
    }

    // Display the queue
    void displayQueue() {
        if (head == NULL) {
            printf("Queue is empty.\n");
            return;
        }
        struct Node *temp = head;
        printf("Processes in queue: ");
        do {
            printf("%d ", temp->time);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
};
#endif 