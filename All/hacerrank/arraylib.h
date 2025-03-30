#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <stdio.h>

void insert(int arr[], int *size, int capacity, int value);
void deleteElement(int arr[], int *size, int index);
void bubbleSort(int arr[], int size);
void displayArray(int arr[], int size);
void reverseArray(int arr[], int size);

#endif
