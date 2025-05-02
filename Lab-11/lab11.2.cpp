// Program to perform functions of Hash ADT - Quadratic Probing implementation.
#include <stdio.h>
#define SIZE 10

class HashTable {
private:
    int table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hash(int key);
    void insert(int key);
    void search(int key);
    void remove(int key);
    void display();
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            ht.insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            ht.remove(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            ht.search(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            break;
        default:
            printf("Invalid option!\n");
        }
    } while (choice != 5);

    return 0;
}

int HashTable :: hash(int key) {
    return key % SIZE;
}

//Insertion of the given value in the hash table
void HashTable :: insert(int key) {
    int idx = hash(key);
    int i = 0;
    while (table[(idx + i * i) % SIZE] != -1 && table[(idx + i * i) % SIZE] != -2) {
        i++;
        if (i == SIZE) {
            printf("Hash Table is full!\n");
            return;
        }
    }
    table[(idx + i * i) % SIZE] = key;
    printf("Inserted %d\n", key);
}

//Search the given value in the hash table
void HashTable :: search(int key) {
    int idx = hash(key);
    int i = 0;
    while (table[(idx + i * i) % SIZE] != -1) {
        if (table[(idx + i * i) % SIZE] == key) {
            printf("Found at index %d\n", (idx + i * i) % SIZE);
            return;
        }
        i++;
        if (i == SIZE) break;
    }
    printf("Not found!\n");
}

//Deletion of the given value in the hash table
void HashTable :: remove(int key) {
    int idx = hash(key);
    int i = 0;
    while (table[(idx + i * i) % SIZE] != -1) {
        if (table[(idx + i * i) % SIZE] == key) {
            table[(idx + i * i) % SIZE] = -2;
            printf("Deleted %d\n", key);
            return;
        }
        i++;
        if (i == SIZE) break;
    }
    printf("Key not found!\n");
}

//Display the hash table
void HashTable :: display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("Index %d: %d\n", i, table[i]);
}