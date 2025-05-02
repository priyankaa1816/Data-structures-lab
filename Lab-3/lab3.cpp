//OPERATIONS PERFORMED IN ADT
#include <stdio.h>
#define MAX 5

class ADT{
private:
    int arr[MAX];
    int size;

    // Function to check if the list is full
    int checkFull() {
        return size >= MAX;
    }

    // Function to reverse array
    void reverse(int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

public:
    ADT() {
        size = 0;
    }

    // Insert at the beginning
    void insertBeginning(int value) {
        if (checkFull()) {
            printf("List is full!\n");
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];  
        }
        arr[0] = value;  
        size++;
    }

    // Insert at the end
    void insertEnd(int value) {
        if (checkFull()) {
            printf("List is full!\n");
            return;
        }
        arr[size] = value;
        size++;
    }

    // Insert at a specific position
    void insertPosition(int pos, int value) {
        if (checkFull()) {
            printf("List is full!\n");
            return;
        }
        if (pos < 1 || pos > size + 1) {
            printf("Invalid position!\n");
            return;
        }
        for (int i = size; i >= pos; i--) {
            arr[i] = arr[i - 1];  
        }
        arr[pos - 1] = value;  
        size++;
    }

    // Delete at the beginning
    void deleteBeginning() {
        if (size == 0) {
            printf("List is empty!\n");
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];  
        }
        size--;
    }

    // Delete at the end
    void deleteEnd() {
        if (size == 0) {
            printf("List is empty!\n");
            return;
        }
        size--;
    }

    // Delete at a given position
    void deletePosition(int pos) {
        if (size == 0) {
            printf("List is empty!\n");
            return;
        }
        if (pos < 1 || pos > size) {
            printf("Invalid position!\n");
            return;
        }
        for (int i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];  
        }
        size--;
    }

    // Search for a value
    void search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                printf("Element %d found at index %d.\n", value, i);
                return;
            }
        }
        printf("Element %d not found.\n", value);
    }

    // Display the array
    void display() {
        if (size == 0) {
            printf("List is empty!\n");
            return;
        }
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
           printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // Rotate the array by k positions
    void rotate(int k) {
        if (size == 0) {
            printf("List is empty!\n");
            return;
        }
        k = k % size;  
        if (k == 0){
            return;  
        }
        // Reverse the entire array
        reverse(0, size - 1);

        // Reverse the first k elements
        reverse(0, k - 1);

        // Reverse the remaining elements
        reverse(k, size - 1);
    }
};

int main() {
    ADT list;
    int choice, value, pos, k;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Rotate\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            list.insertBeginning(value);
            continue;
        }

        if (choice == 2) {
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            list.insertEnd(value);
            continue;
        }

        if (choice == 3) {
            printf("Enter position and value to insert: ");
            scanf("%d %d", &pos, &value);
            list.insertPosition(pos, value);
            continue;
        }

        if (choice == 4) {
            list.deleteBeginning();
            continue;
        }

        if (choice == 5) {
            list.deleteEnd();
            continue;
        }

        if (choice == 6) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            list.deletePosition(pos);
            continue;
        }

        if (choice == 7) {
            printf("Enter value to search: ");
            scanf("%d", &value);
            list.search(value);
            continue;
        }

        if (choice == 8) {
            list.display();
            continue;
        }

        if (choice == 9) {
            printf("Enter number of positions to rotate: ");
            scanf("%d", &k);
            list.rotate(k);
            continue;
        }

        if (choice == 10) {
            printf("Exiting program...\n");
            break;
        }

        printf("Invalid choice!\n");
    }

    return 0;
} 