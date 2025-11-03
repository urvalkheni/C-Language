/*
 * Advanced Array Min/Max Finder & Analyzer v2.0
 * Features: Min/Max operations, K-th largest/smallest,
 *           array statistics, and comprehensive analysis
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

// Function prototypes
void inputArray(int arr[], int size);
void displayArray(int arr[], int size);
void findMinMax(int arr[], int size);
void findKthLargest(int arr[], int size);
void findKthSmallest(int arr[], int size);
void findSecondLargest(int arr[], int size);
void findSecondSmallest(int arr[], int size);
void findMinMaxPositions(int arr[], int size);
void findLocalMaxima(int arr[], int size);
void findLocalMinima(int arr[], int size);
void findRange(int arr[], int size);
void findPeakElement(int arr[], int size);
void compareAdjacentElements(int arr[], int size);
void findMedian(int arr[], int size);
void sortArray(int arr[], int size);
void displayMenu();

int main() {
    int choice, size = 0;
    int arr[MAX_SIZE];
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Array Min/Max Finder & Analyzer v2.0          ║\n");
    printf("║         Comprehensive Array Analysis Tool                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-15): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n--- Input Array ---\n");
                printf("Enter array size (max %d): ", MAX_SIZE);
                scanf("%d", &size);
                if(size > MAX_SIZE || size <= 0) {
                    printf("Invalid size!\n");
                    size = 0;
                    break;
                }
                inputArray(arr, size);
                displayArray(arr, size);
                break;
                
            case 2:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                displayArray(arr, size);
                break;
                
            case 3:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findMinMax(arr, size);
                break;
                
            case 4:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findKthLargest(arr, size);
                break;
                
            case 5:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findKthSmallest(arr, size);
                break;
                
            case 6:
                if(size < 2) {
                    printf("\nError: Need at least 2 elements!\n");
                    break;
                }
                findSecondLargest(arr, size);
                break;
                
            case 7:
                if(size < 2) {
                    printf("\nError: Need at least 2 elements!\n");
                    break;
                }
                findSecondSmallest(arr, size);
                break;
                
            case 8:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findMinMaxPositions(arr, size);
                break;
                
            case 9:
                if(size < 3) {
                    printf("\nError: Need at least 3 elements!\n");
                    break;
                }
                findLocalMaxima(arr, size);
                break;
                
            case 10:
                if(size < 3) {
                    printf("\nError: Need at least 3 elements!\n");
                    break;
                }
                findLocalMinima(arr, size);
                break;
                
            case 11:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findRange(arr, size);
                break;
                
            case 12:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findPeakElement(arr, size);
                break;
                
            case 13:
                if(size < 2) {
                    printf("\nError: Need at least 2 elements!\n");
                    break;
                }
                compareAdjacentElements(arr, size);
                break;
                
            case 14:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                findMedian(arr, size);
                break;
                
            case 15:
                if(size == 0) {
                    printf("\nError: Array is empty!\n");
                    break;
                }
                sortArray(arr, size);
                displayArray(arr, size);
                break;
                
            case 0:
                printf("\n✓ Thank you for using Array Analyzer!\n");
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
    printf("│  ARRAY OPERATIONS                                       │\n");
    printf("│  [1]  Input Array                                       │\n");
    printf("│  [2]  Display Array                                     │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  MIN/MAX OPERATIONS                                     │\n");
    printf("│  [3]  Find Min & Max                                    │\n");
    printf("│  [4]  Find K-th Largest                                 │\n");
    printf("│  [5]  Find K-th Smallest                                │\n");
    printf("│  [6]  Find Second Largest                               │\n");
    printf("│  [7]  Find Second Smallest                              │\n");
    printf("│  [8]  Find Min/Max Positions                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED ANALYSIS                                      │\n");
    printf("│  [9]  Find Local Maxima                                 │\n");
    printf("│  [10] Find Local Minima                                 │\n");
    printf("│  [11] Find Range (Max - Min)                            │\n");
    printf("│  [12] Find Peak Element                                 │\n");
    printf("│  [13] Compare Adjacent Elements                         │\n");
    printf("│  [14] Find Median                                       │\n");
    printf("│  [15] Sort Array                                        │\n");
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
    printf("\nArray[%d]: ", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findMinMax(int arr[], int size) {
    printf("\n--- Find Min & Max ---\n");
    int min = arr[0], max = arr[0];
    
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Difference: %d\n", max - min);
}

void findKthLargest(int arr[], int size) {
    int k;
    printf("\n--- Find K-th Largest ---\n");
    printf("Enter K (1 to %d): ", size);
    scanf("%d", &k);
    
    if(k < 1 || k > size) {
        printf("Invalid K!\n");
        return;
    }
    
    int temp[MAX_SIZE];
    for(int i = 0; i < size; i++) temp[i] = arr[i];
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(temp[j] < temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    
    printf("%d-th largest element: %d\n", k, temp[k - 1]);
}

void findKthSmallest(int arr[], int size) {
    int k;
    printf("\n--- Find K-th Smallest ---\n");
    printf("Enter K (1 to %d): ", size);
    scanf("%d", &k);
    
    if(k < 1 || k > size) {
        printf("Invalid K!\n");
        return;
    }
    
    int temp[MAX_SIZE];
    for(int i = 0; i < size; i++) temp[i] = arr[i];
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    
    printf("%d-th smallest element: %d\n", k, temp[k - 1]);
}

void findSecondLargest(int arr[], int size) {
    printf("\n--- Find Second Largest ---\n");
    int first = INT_MIN, second = INT_MIN;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    if(second == INT_MIN)
        printf("No second largest element found\n");
    else
        printf("Second largest: %d\n", second);
}

void findSecondSmallest(int arr[], int size) {
    printf("\n--- Find Second Smallest ---\n");
    int first = INT_MAX, second = INT_MAX;
    
    for(int i = 0; i < size; i++) {
        if(arr[i] < first) {
            second = first;
            first = arr[i];
        } else if(arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    if(second == INT_MAX)
        printf("No second smallest element found\n");
    else
        printf("Second smallest: %d\n", second);
}

void findMinMaxPositions(int arr[], int size) {
    printf("\n--- Find Min/Max Positions ---\n");
    int minIdx = 0, maxIdx = 0;
    
    for(int i = 1; i < size; i++) {
        if(arr[i] < arr[minIdx]) minIdx = i;
        if(arr[i] > arr[maxIdx]) maxIdx = i;
    }
    
    printf("Minimum %d at index %d (position %d)\n", arr[minIdx], minIdx, minIdx + 1);
    printf("Maximum %d at index %d (position %d)\n", arr[maxIdx], maxIdx, maxIdx + 1);
    printf("Distance between them: %d positions\n", abs(maxIdx - minIdx));
}

void findLocalMaxima(int arr[], int size) {
    printf("\n--- Local Maxima ---\n");
    int count = 0;
    
    if(arr[0] > arr[1]) {
        printf("Local maximum: %d at index 0\n", arr[0]);
        count++;
    }
    
    for(int i = 1; i < size - 1; i++) {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            printf("Local maximum: %d at index %d\n", arr[i], i);
            count++;
        }
    }
    
    if(arr[size - 1] > arr[size - 2]) {
        printf("Local maximum: %d at index %d\n", arr[size - 1], size - 1);
        count++;
    }
    
    printf("\nTotal local maxima: %d\n", count);
}

void findLocalMinima(int arr[], int size) {
    printf("\n--- Local Minima ---\n");
    int count = 0;
    
    if(arr[0] < arr[1]) {
        printf("Local minimum: %d at index 0\n", arr[0]);
        count++;
    }
    
    for(int i = 1; i < size - 1; i++) {
        if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("Local minimum: %d at index %d\n", arr[i], i);
            count++;
        }
    }
    
    if(arr[size - 1] < arr[size - 2]) {
        printf("Local minimum: %d at index %d\n", arr[size - 1], size - 1);
        count++;
    }
    
    printf("\nTotal local minima: %d\n", count);
}

void findRange(int arr[], int size) {
    printf("\n--- Find Range ---\n");
    int min = arr[0], max = arr[0];
    
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Range: %d\n", max - min);
    printf("Midpoint: %.2f\n", (min + max) / 2.0);
}

void findPeakElement(int arr[], int size) {
    printf("\n--- Find Peak Element ---\n");
    
    if(size == 1) {
        printf("Peak: %d at index 0\n", arr[0]);
        return;
    }
    
    if(arr[0] >= arr[1]) {
        printf("Peak: %d at index 0\n", arr[0]);
    }
    
    for(int i = 1; i < size - 1; i++) {
        if(arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            printf("Peak: %d at index %d\n", arr[i], i);
        }
    }
    
    if(arr[size - 1] >= arr[size - 2]) {
        printf("Peak: %d at index %d\n", arr[size - 1], size - 1);
    }
}

void compareAdjacentElements(int arr[], int size) {
    printf("\n--- Compare Adjacent Elements ---\n");
    
    for(int i = 0; i < size - 1; i++) {
        printf("arr[%d]=%d vs arr[%d]=%d: ", i, arr[i], i+1, arr[i+1]);
        if(arr[i] > arr[i + 1])
            printf("Decreasing\n");
        else if(arr[i] < arr[i + 1])
            printf("Increasing\n");
        else
            printf("Equal\n");
    }
}

void findMedian(int arr[], int size) {
    printf("\n--- Find Median ---\n");
    
    int temp[MAX_SIZE];
    for(int i = 0; i < size; i++) temp[i] = arr[i];
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    
    if(size % 2 == 0) {
        printf("Median: %.2f\n", (temp[size/2 - 1] + temp[size/2]) / 2.0);
    } else {
        printf("Median: %d\n", temp[size/2]);
    }
}

void sortArray(int arr[], int size) {
    printf("\n--- Sorting Array ---\n");
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("Array sorted in ascending order.\n");
}