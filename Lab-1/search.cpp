//SEARCHING PROGRAM

#include <stdio.h>
#include "sort.h"

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; 
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == key)
            return mid;
            
        else if (arr[mid] < key)
            left = mid + 1;

        else if (arr[mid]> key)
            right = mid - 1;
    }

    
    return -1;
}

int main() {
  
    int choice;
    int key;
    int arr[100];
    int size;
    printf("Enter size of elements:");
    scanf("%d", &size);
    for(int i=0; i<size;i++){
        scanf("%d", &arr[i]);
        }

    while (1) {
        printf("\nSearch Menu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        if (choice == 1) {
            printf("Enter the element to search for: ");
            scanf("%d", &key);
            int index = linearSearch(arr, size, key);
            if (index != -1) {
                printf("Element found at index: %d\n", index);
            } 
            else {
                printf("Element not found.\n");
            }
        } 
        else if (choice == 2) {
            
            bubbleSort(arr, size); 
            printf("Enter the element to search for: ");
            scanf("%d", &key);
            int index = binarySearch(arr, size, key);
            if (index != -1) {
                printf("Element found at index: %d\n", index);
            } 
            else {
                printf("Element not found.\n");
            }
        } 
        
        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice. try again.\n");
            continue; 
        }
    }

    return 0;
}