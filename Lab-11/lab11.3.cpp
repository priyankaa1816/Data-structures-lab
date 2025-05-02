// Program to perform functions of Hash ADT - Separate chaining implementation.
#include <stdio.h>
#define SIZE 10

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class HashTable {
private:
    Node* table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
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

int hash(int key) {
    return key % SIZE;
}

//Insertion of the given value in the hash table
void HashTable :: insert(int key) {
    int idx = hash(key);
    Node* newNode = new Node(key);
    newNode->next = table[idx];
    table[idx] = newNode;
    printf("Inserted %d\n", key);
}

//Search the given value in the hash table
void HashTable :: search(int key) {
    int idx = hash(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->data == key) {
            printf("Found at index %d\n", idx);
            return;
        }
        temp = temp->next;
    }
    printf("Not found!\n");
}

//Deletion of the given value in the hash table
void HashTable :: remove(int key) {
    int idx = hash(key);
    Node* temp = table[idx];
    Node* prev = NULL;
    while (temp) {
        if (temp->data == key) {
            if (prev)
                prev->next = temp->next;
            else
                table[idx] = temp->next;
            delete temp;
            printf("Deleted %d\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key not found!\n");
}

//Display the hash table
void HashTable :: display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}