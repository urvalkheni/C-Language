#include "arraylib.h"

void insert(int arr[], int *size, int capacity, int value) {
    if (*size >= capacity) {
        printf("Array is full!\n");
        return;
    }
    arr[(*size)++] = value;
}
void deleteElement(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
