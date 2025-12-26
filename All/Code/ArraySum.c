/*
 * Advanced Array Operations Toolkit v2.0
 * Features: Array manipulation, analysis, sorting,
 *           searching, statistics, and transformations
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

// Function prototypes
void arraySum();
void arrayProduct();
void arrayAverage();
void findMinMax();
void arraySearch();
void arraySort();
void arrayReverse();
void arrayRotate();
void removeDuplicates();
void arrayMerge();
void arrayIntersection();
void arrayStatistics();
void arrayPartition();
void secondLargest();
void pairSumFinder();
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║        Advanced Array Operations Toolkit v2.0             ║\n");
    printf("║         Comprehensive Array Analysis System                ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        if(choice == 0) break;
        
        switch(choice) {
            case 1:
                arraySum();
                break;
            case 2:
                arrayProduct();
                break;
            case 3:
                arrayAverage();
                break;
            case 4:
                findMinMax();
                break;
            case 5:
                arraySearch();
                break;
            case 6:
                arraySort();
                break;
            case 7:
                arrayReverse();
                break;
            case 8:
                arrayRotate();
                break;
            case 9:
                removeDuplicates();
                break;
            case 10:
                arrayMerge();
                break;
            case 11:
                arrayIntersection();
                break;
            case 12:
                arrayStatistics();
                break;
            case 13:
                arrayPartition();
                break;
            case 14:
                secondLargest();
                break;
            case 15:
                pairSumFinder();
                break;
            case 16:
                printf("\n--- Array Operations Guide ---\n");
                printf("\n• Sum: Add all elements\n");
                printf("• Sort: Arrange in order\n");
                printf("• Search: Find element position\n");
                printf("• Merge: Combine two arrays\n");
                printf("• Statistics: Mean, median, mode\n");
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Array Operations Toolkit!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  BASIC OPERATIONS                                       │\n");
    printf("│  [1]  Array Sum                                         │\n");
    printf("│  [2]  Array Product                                     │\n");
    printf("│  [3]  Array Average                                     │\n");
    printf("│  [4]  Find Min & Max                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ARRAY MANIPULATION                                     │\n");
    printf("│  [5]  Array Search                                      │\n");
    printf("│  [6]  Array Sort                                        │\n");
    printf("│  [7]  Array Reverse                                     │\n");
    printf("│  [8]  Array Rotate                                      │\n");
    printf("│  [9]  Remove Duplicates                                 │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ADVANCED OPERATIONS                                    │\n");
    printf("│  [10] Merge Arrays                                      │\n");
    printf("│  [11] Array Intersection                                │\n");
    printf("│  [12] Array Statistics                                  │\n");
    printf("│  [13] Array Partition (Even/Odd)                        │\n");
    printf("│  [14] Second Largest Element                            │\n");
    printf("│  [15] Pair Sum Finder                                   │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  [16] Operations Guide                                  │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void arraySum() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX) {
        printf("Error: Array size must be between 1 and %d!\n", MAX);
        return;
    }
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    printf("\n--- Array Sum ---\n");
    printf("Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\nSum: %lld\n", sum);
}

void arrayProduct() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long product = 1;
    for(int i = 0; i < n; i++) {
        product *= arr[i];
    }
    
    printf("\n--- Array Product ---\n");
    printf("Product: %lld\n", product);
}

void arrayAverage() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    printf("\n--- Array Average ---\n");
    printf("Sum: %lld\n", sum);
    printf("Average: %.2f\n", (double)sum / n);
}

void findMinMax() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0], max = arr[0];
    int minIdx = 0, maxIdx = 0;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            minIdx = i;
        }
        if(arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }
    
    printf("\n--- Min & Max ---\n");
    printf("Minimum: %d (at index %d)\n", min, minIdx);
    printf("Maximum: %d (at index %d)\n", max, maxIdx);
    printf("Range: %d\n", max - min);
}

void arraySearch() {
    int n, arr[MAX], key;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    printf("\n--- Array Search ---\n");
    printf("Positions found at: ");
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("%d ", i);
            count++;
        }
    }
    
    if(count == 0)
        printf("Not found");
    else
        printf("\nOccurrences: %d", count);
    printf("\n");
}

void arraySort() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Array Sort ---\n");
    printf("Original: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    // Bubble sort
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("\nSorted:   ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void arrayReverse() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Array Reverse ---\n");
    printf("Original: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    for(int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    
    printf("\nReversed: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void arrayRotate() {
    int n, arr[MAX], k;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter rotation count: ");
    scanf("%d", &k);
    k = k % n;
    
    printf("\n--- Array Rotate ---\n");
    printf("Original: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int temp[MAX];
    for(int i = 0; i < n; i++) {
        temp[i] = arr[(i + k) % n];
    }
    
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    
    printf("\nRotated:  ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void removeDuplicates() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Remove Duplicates ---\n");
    printf("Original: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    int unique[MAX], uniqueCount = 0;
    
    for(int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for(int j = 0; j < uniqueCount; j++) {
            if(arr[i] == unique[j]) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            unique[uniqueCount++] = arr[i];
        }
    }
    
    printf("\nUnique:   ");
    for(int i = 0; i < uniqueCount; i++)
        printf("%d ", unique[i]);
    printf("\nRemoved %d duplicates\n", n - uniqueCount);
}

void arrayMerge() {
    int n1, n2, arr1[MAX], arr2[MAX], merged[MAX * 2];
    
    printf("\nEnter first array size: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("\nEnter second array size: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    for(int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for(int i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];
    
    printf("\n--- Merge Arrays ---\n");
    printf("Merged array: ");
    for(int i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);
    printf("\n");
}

void arrayIntersection() {
    int n1, n2, arr1[MAX], arr2[MAX];
    
    printf("\nEnter first array size: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("\nEnter second array size: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    
    printf("\n--- Array Intersection ---\n");
    printf("Common elements: ");
    
    int found = 0;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                found++;
                break;
            }
        }
    }
    
    if(found == 0)
        printf("None");
    printf("\n");
}

void arrayStatistics() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long sum = 0;
    int min = arr[0], max = arr[0];
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    
    // Sort for median
    int sorted[MAX];
    for(int i = 0; i < n; i++)
        sorted[i] = arr[i];
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    double median;
    if(n % 2 == 0)
        median = (sorted[n/2 - 1] + sorted[n/2]) / 2.0;
    else
        median = sorted[n/2];
    
    printf("\n--- Array Statistics ---\n");
    printf("Count: %d\n", n);
    printf("Sum: %lld\n", sum);
    printf("Mean: %.2f\n", (double)sum / n);
    printf("Median: %.2f\n", median);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Range: %d\n", max - min);
}

void arrayPartition() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\n--- Array Partition ---\n");
    printf("Even elements: ");
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }
    
    printf("\nOdd elements:  ");
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void secondLargest() {
    int n, arr[MAX];
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int first = INT_MIN, second = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    
    printf("\n--- Second Largest ---\n");
    printf("Largest: %d\n", first);
    printf("Second Largest: %d\n", second);
}

void pairSumFinder() {
    int n, arr[MAX], target;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter target sum: ");
    scanf("%d", &target);
    
    printf("\n--- Pair Sum Finder ---\n");
    printf("Pairs with sum %d:\n", target);
    
    int found = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("(%d, %d) ", arr[i], arr[j]);
                found++;
            }
        }
    }
    
    if(found == 0)
        printf("No pairs found");
    printf("\n");
}