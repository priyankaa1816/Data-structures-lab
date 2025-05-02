//Program of main function
#include "robin.h"
int main() {
    int quantum;
    printf("Enter the fixed time quantum: ");
    scanf("%d", &quantum);
    RoundRobin RR(quantum);
    int choice, val;
    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert Process\n");
        printf("2. Execute Process\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else if (choice == 1) {
            printf("Enter process execution time: ");
            scanf("%d", &val);
            RR.insertProcess(val);
            RR.displayQueue();
        } else if (choice == 2) {
            RR.executeProcess();
            RR.displayQueue();
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}