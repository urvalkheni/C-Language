/*
 * Advanced Array Operations Toolkit v2.0
 * Features: Search, sort, analysis, manipulation,
 *           and comprehensive array operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

// Function prototypes
void inputArray(int arr[], int size);
void displayArray(int arr[], int size);
void searchElement(int arr[], int size);
void findMissing(int arr[], int size);
void findDuplicates(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void reverseArray(int arr[], int size);
void findMinMax(int arr[], int size);
void arrayStatistics(int arr[], int size);
void removeElement(int arr[], int *size);
void insertElement(int arr[], int *size);
void mergeTwoArrays();
void arrayRotation(int arr[], int size);
void findFrequency(int arr[], int size);
void findSecondLargest(int arr[], int size);
void pairSum(int arr[], int size);
void removeDuplicates(int arr[], int *size);
void displayMenu();

// Main function
int main() {
    int choice, size = 0;
    int arr[MAX_SIZE];
    
    srand(time(NULL));
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║       Advanced Array Operations Toolkit v2.0              ║\n");
    printf("║        Comprehensive Array Management System               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-18): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Create/Input Array ---\n");
                printf("Enter array size: ");
                scanf("%d", &size);
                if(size > MAX_SIZE) {
                    printf("Error: Max size is %d\n", MAX_SIZE);
                    size = 0;
                    break;
                }
                inputArray(arr, size);
                printf("Array created successfully!\n");
                displayArray(arr, size);
                break;
                
            case 2:
                if(size == 0) {
                    printf("\nError: Array is empty! Create array first.\n");
                    break;
                }
                printf("\n--- Display Array ---\n");
                displayArray(arr, size);
                break;
                
            case 3:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                searchElement(arr, size);
                break;
                
            case 4:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findMissing(arr, size);
                break;
                
            case 5:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findDuplicates(arr, size);
                break;
                
            case 6:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                printf("\n--- Bubble Sort ---\n");
                bubbleSort(arr, size);
                printf("Array sorted successfully!\n");
                displayArray(arr, size);
                break;
                
            case 7:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                printf("\n--- Selection Sort ---\n");
                selectionSort(arr, size);
                printf("Array sorted successfully!\n");
                displayArray(arr, size);
                break;
                
            case 8:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                printf("\n--- Reverse Array ---\n");
                reverseArray(arr, size);
                printf("Array reversed successfully!\n");
                displayArray(arr, size);
                break;
                
            case 9:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findMinMax(arr, size);
                break;
                
            case 10:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                arrayStatistics(arr, size);
                break;
                
            case 11:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                removeElement(arr, &size);
                break;
                
            case 12:
                if(size >= MAX_SIZE) {
                    printf("\nError: Array is full!\n");
                    break;
                }
                insertElement(arr, &size);
                break;
                
            case 13:
                mergeTwoArrays();
                break;
                
            case 14:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                arrayRotation(arr, size);
                break;
                
            case 15:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findFrequency(arr, size);
                break;
                
            case 16:
                if(size < 2) {
                    printf("\nError: Need at least 2 elements!\n");
                    break;
                }
                findSecondLargest(arr, size);
                break;
                
            case 17:
                if(size < 2) {
                    printf("\nError: Need at least 2 elements!\n");
                    break;
                }
                pairSum(arr, size);
                break;
                
            case 18:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                removeDuplicates(arr, &size);
                break;
                
            case 0:
                printf("\n✓ Thank you for using Array Toolkit!\n");
                break;
                
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Create/Input Array                                │\n");
    printf("│  [2]  Display Array                                     │\n");
    printf("│  [3]  Search Element                                    │\n");
    printf("│  [4]  Find Missing Number                               │\n");
    printf("│  [5]  Find Duplicate Elements                           │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  SORTING & ARRANGEMENT                                  │\n");
    printf("│  [6]  Bubble Sort                                       │\n");
    printf("│  [7]  Selection Sort                                    │\n");
    printf("│  [8]  Reverse Array                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS & STATISTICS                                  │\n");
    printf("│  [9]  Find Min/Max                                      │\n");
    printf("│  [10] Array Statistics (Sum, Average, etc.)             │\n");
    printf("│  [15] Element Frequency                                 │\n");
    printf("│  [16] Find Second Largest                               │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MODIFICATION                                           │\n");
    printf("│  [11] Remove Element                                    │\n");
    printf("│  [12] Insert Element                                    │\n");
    printf("│  [18] Remove Duplicates                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED OPERATIONS                                    │\n");
    printf("│  [13] Merge Two Arrays                                  │\n");
    printf("│  [14] Array Rotation                                    │\n");
    printf("│  [17] Find Pair with Given Sum                          │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void inputArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("Array[%d]: ", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchElement(int arr[], int size) {
    int element, found = -1;
    printf("\n--- Search Element ---\n");
    printf("Enter element to search: ");
    scanf("%d", &element);
    
    for(int i = 0; i < size; i++) {
        if(arr[i] == element) {
            found = i;
            break;
        }
    }
    
    if(found != -1)
        printf("✓ Element %d found at index %d (position %d)\n", element, found, found+1);
    else
        printf("✗ Element %d not found in array\n", element);
}

void findMissing(int arr[], int size) {
    printf("\n--- Find Missing Number ---\n");
    printf("Assumes consecutive sequence from 1 to n with one missing\n");
    
    int n = size + 1;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    
    for(int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    
    int missing = expectedSum - actualSum;
    printf("Missing number: %d\n", missing);
}

void findDuplicates(int arr[], int size) {
    printf("\n--- Find Duplicates ---\n");
    bool found = false;
    
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                printf("Duplicate: %d (at positions %d and %d)\n", arr[i], i+1, j+1);
                found = true;
            }
        }
    }
    
    if(!found)
        printf("No duplicates found\n");
}

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void reverseArray(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void findMinMax(int arr[], int size) {
    printf("\n--- Min/Max ---\n");
    int min = arr[0], max = arr[0];
    int minIdx = 0, maxIdx = 0;
    
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
            minIdx = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }
    
    printf("Minimum: %d at index %d\n", min, minIdx);
    printf("Maximum: %d at index %d\n", max, maxIdx);
    printf("Range: %d\n", max - min);
}

void arrayStatistics(int arr[], int size) {
    printf("\n--- Array Statistics ---\n");
    
    int sum = 0, min = arr[0], max = arr[0];
    for(int i = 0; i < size; i++) {
        sum += arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    
    float average = (float)sum / size;
    
    printf("Size: %d elements\n", size);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Range: %d\n", max - min);
}

void removeElement(int arr[], int *size) {
    int index;
    printf("\n--- Remove Element ---\n");
    displayArray(arr, *size);
    printf("Enter index to remove (0 to %d): ", *size - 1);
    scanf("%d", &index);
    
    if(index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    
    for(int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    
    printf("Element removed successfully!\n");
    displayArray(arr, *size);
}

void insertElement(int arr[], int *size) {
    int index, value;
    printf("\n--- Insert Element ---\n");
    displayArray(arr, *size);
    printf("Enter index to insert (0 to %d): ", *size);
    scanf("%d", &index);
    
    if(index < 0 || index > *size) {
        printf("Invalid index!\n");
        return;
    }
    
    printf("Enter value: ");
    scanf("%d", &value);
    
    for(int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
    
    printf("Element inserted successfully!\n");
    displayArray(arr, *size);
}

void mergeTwoArrays() {
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];
    int size1, size2;
    
    printf("\n--- Merge Two Arrays ---\n");
    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter elements of first array:\n");
    inputArray(arr1, size1);
    
    printf("Enter size of second array: ");
    scanf("%d", &size2);
    printf("Enter elements of second array:\n");
    inputArray(arr2, size2);
    
    for(int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for(int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
    
    printf("\nMerged array:\n");
    displayArray(merged, size1 + size2);
}

void arrayRotation(int arr[], int size) {
    int k;
    printf("\n--- Array Rotation ---\n");
    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);
    
    k = k % size;
    
    for(int i = 0; i < k; i++) {
        int temp = arr[size - 1];
        for(int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    
    printf("Array rotated successfully!\n");
    displayArray(arr, size);
}

void findFrequency(int arr[], int size) {
    printf("\n--- Element Frequency ---\n");
    bool counted[MAX_SIZE] = {false};
    
    for(int i = 0; i < size; i++) {
        if(counted[i]) continue;
        
        int count = 1;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                count++;
                counted[j] = true;
            }
        }
        printf("Element %d appears %d time(s)\n", arr[i], count);
    }
}

void findSecondLargest(int arr[], int size) {
    printf("\n--- Second Largest Element ---\n");
    
    int first = arr[0], second = -1;
    
    for(int i = 1; i < size; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    if(second == -1)
        printf("No second largest element found\n");
    else
        printf("Second largest: %d\n", second);
}

void pairSum(int arr[], int size) {
    int target;
    printf("\n--- Find Pair with Given Sum ---\n");
    printf("Enter target sum: ");
    scanf("%d", &target);
    
    bool found = false;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] + arr[j] == target) {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
                found = true;
            }
        }
    }
    
    if(!found)
        printf("No pair found with sum %d\n", target);
}

void removeDuplicates(int arr[], int *size) {
    printf("\n--- Remove Duplicates ---\n");
    int newSize = 0;
    
    for(int i = 0; i < *size; i++) {
        bool isDuplicate = false;
        for(int j = 0; j < newSize; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            arr[newSize++] = arr[i];
        }
    }
    
    *size = newSize;
    printf("Duplicates removed successfully!\n");
    displayArray(arr, *size);
}