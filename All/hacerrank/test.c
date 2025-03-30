#include <stdio.h>
#include "arraylib.h"

#define CAPACITY 100

int main() {
    int arr[CAPACITY];
    int size = 0;

    // Insert elements of array
    insert(arr,&size,CAPACITY,10);
    insert(arr,&size,CAPACITY,30);
    insert(arr,&size,CAPACITY,20);
    insert(arr,&size,CAPACITY,50);
    insert(arr,&size,CAPACITY,40);

    printf("Array after insertion :: ");
    displayArray(arr,size);

    // Sorting the array
    bubbleSort(arr,size);
    printf("Array after Bubble Sort :: ");
    displayArray(arr,size);

    // Deletion the array
    deleteElement(arr,&size,2);
    printf("Array after deletion at index 2 :: ");
    displayArray(arr,size);

    // Reverse the array
    reverseArray(arr,size);
    printf("Array after reversing :: ");
    displayArray(arr,size);

    return 0;
}
