//Implementation of Priority Queue using Max Heap
#include <stdio.h>
#define MAX 100
class MaxHeap {
    int heap[MAX];
    int size;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
MaxHeap() {
        size = 0;
    }
    void insert(int val);
    void deleteMax();
    void display();
    void search(int key);
    void heapSort();
};
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        int temp = heap[index];
        heap[index] = heap[(index - 1) / 2];
        heap[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}
void MaxHeap::heapifyDown(int index) {
    int largest = index;
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        largest = index;
        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest;
        } else {
            break;
        }
    }
}
void MaxHeap::insert(int val) {
    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
    printf("%d inserted.\n", val);
}
void MaxHeap::deleteMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Deleted element: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}
void MaxHeap::display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
void MaxHeap::search(int key) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == key) {
            printf("%d found at index %d\n", key, i);
            return;
        }
    }
    printf("%d not found in the heap.\n", key);
}
void MaxHeap::heapSort() {
    int originalSize = size;
    int temp[MAX];
    for (int i = 0; i < size; i++)
        temp[i] = heap[i];

    printf("Sorted elements (descending): ");
    while (size > 0) {
        printf("%d ", heap[0]);
        deleteMax();
    }
    printf("\n");
    for (int i = 0; i < originalSize; i++)
        heap[i] = temp[i];
    size = originalSize;
}
int main() {
    MaxHeap pq;
    int choice, value;
    do {
        printf("\n--- Priority Queue using Max Heap ---\n");
        printf("1. Insert\n");
        printf("2. Delete (Max)\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Sort (Heap Sort)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            pq.insert(value);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &value);
            pq.search(value);
            break;
        case 5:
            pq.heapSort();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
