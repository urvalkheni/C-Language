#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define VISUALIZATION_WIDTH 60

typedef struct {
    char name[30];
    long comparisons;
    long swaps;
    double time_ms;
    int is_stable;
} SortStats;

// Global visualization flag
int show_visualization = 0;
int step_delay = 0;

// Function prototypes
void bubble_sort(int arr[], int n, SortStats *stats);
void selection_sort(int arr[], int n, SortStats *stats);
void insertion_sort(int arr[], int n, SortStats *stats);
void merge_sort(int arr[], int left, int right, SortStats *stats);
void quick_sort(int arr[], int low, int high, SortStats *stats);
void heap_sort(int arr[], int n, SortStats *stats);
void counting_sort(int arr[], int n, SortStats *stats);
void radix_sort(int arr[], int n, SortStats *stats);
void shell_sort(int arr[], int n, SortStats *stats);
void cocktail_sort(int arr[], int n, SortStats *stats);

void visualize_array(int arr[], int n, int highlight1, int highlight2);
void print_array(int arr[], int n, const char* label);
void generate_random_array(int arr[], int n, int max_val);
void generate_sorted_array(int arr[], int n, int reverse);
void copy_array(int src[], int dest[], int n);
int is_sorted(int arr[], int n);
void performance_test();
void interactive_sort();
void educational_mode();
void reset_stats(SortStats *stats, const char *name);
void print_stats(SortStats stats);
double get_time_ms();

// Visualization functions
void visualize_array(int arr[], int n, int highlight1, int highlight2) {
    if (!show_visualization || n > VISUALIZATION_WIDTH) return;
    
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    
    printf("\n");
    for (int height = max_val; height > 0; height--) {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= height) {
                if (i == highlight1) printf("█");
                else if (i == highlight2) printf("▓");
                else printf("│");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) printf("─");
    printf("\n");
    
    if (step_delay > 0) {
        for (volatile int i = 0; i < step_delay * 1000000; i++);
    }
}

void print_array(int arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n && i < 20; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 20) printf("... (showing first 20)");
    printf("\n");
}

void generate_random_array(int arr[], int n, int max_val) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val + 1;
    }
}

void generate_sorted_array(int arr[], int n, int reverse) {
    for (int i = 0; i < n; i++) {
        arr[i] = reverse ? n - i : i + 1;
    }
}

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int is_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return 0;
    }
    return 1;
}

double get_time_ms() {
    return (double)clock() / CLOCKS_PER_SEC * 1000.0;
}

void reset_stats(SortStats *stats, const char *name) {
    strcpy(stats->name, name);
    stats->comparisons = 0;
    stats->swaps = 0;
    stats->time_ms = 0;
    stats->is_stable = 1;
}

void print_stats(SortStats stats) {
    printf("%-20s | %10ld | %8ld | %8.2f ms | %s\n",
           stats.name, stats.comparisons, stats.swaps, 
           stats.time_ms, stats.is_stable ? "Yes" : "No");
}

// Sorting algorithms
void bubble_sort(int arr[], int n, SortStats *stats) {
    double start = get_time_ms();
    
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            stats->comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats->swaps++;
                swapped = 1;
                
                visualize_array(arr, n, j, j + 1);
            }
        }
        if (!swapped) break; // Optimization
    }
    
    stats->time_ms = get_time_ms() - start;
}

void selection_sort(int arr[], int n, SortStats *stats) {
    double start = get_time_ms();
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            stats->comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            stats->swaps++;
            
            visualize_array(arr, n, i, min_idx);
        }
    }
    
    stats->time_ms = get_time_ms() - start;
    stats->is_stable = 0; // Selection sort is not stable
}

void insertion_sort(int arr[], int n, SortStats *stats) {
    double start = get_time_ms();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            stats->comparisons++;
            if (arr[j] <= key) break;
            
            arr[j + 1] = arr[j];
            stats->swaps++;
            j--;
            
            visualize_array(arr, n, j + 1, i);
        }
        arr[j + 1] = key;
    }
    
    stats->time_ms = get_time_ms() - start;
}

// Merge sort helper
void merge(int arr[], int left, int mid, int right, SortStats *stats) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        stats->comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        stats->swaps++;
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        stats->swaps++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        stats->swaps++;
    }
    
    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right, SortStats *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid, stats);
        merge_sort(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

// Quick sort helper
int partition(int arr[], int low, int high, SortStats *stats) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        stats->comparisons++;
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                stats->swaps++;
            }
        }
    }
    
    if (i + 1 != high) {
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        stats->swaps++;
    }
    
    return i + 1;
}

void quick_sort(int arr[], int low, int high, SortStats *stats) {
    if (low < high) {
        int pi = partition(arr, low, high, stats);
        
        quick_sort(arr, low, pi - 1, stats);
        quick_sort(arr, pi + 1, high, stats);
    }
}

// Heap sort helpers
void heapify(int arr[], int n, int i, SortStats *stats) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n) {
        stats->comparisons++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }
    
    if (right < n) {
        stats->comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        stats->swaps++;
        
        heapify(arr, n, largest, stats);
    }
}

void heap_sort(int arr[], int n, SortStats *stats) {
    double start = get_time_ms();
    
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, stats);
    }
    
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        stats->swaps++;
        
        heapify(arr, i, 0, stats);
        visualize_array(arr, n, 0, i);
    }
    
    stats->time_ms = get_time_ms() - start;
    stats->is_stable = 0;
}

void counting_sort(int arr[], int n, SortStats *stats) {
    double start = get_time_ms();
    
    // Find maximum element
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    
    // Create count array
    int *count = calloc(max_val + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));
    
    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Cumulative count
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
        stats->swaps++;
    }
    
    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
    
    stats->time_ms = get_time_ms() - start;
    stats->comparisons = 0; // No comparisons in counting sort
}

void performance_test() {
    printf("\n=== PERFORMANCE TEST ===\n");
    
    int sizes[] = {100, 500, 1000, 2000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("\nPerformance comparison across different array sizes:\n");
    printf("%-10s | %-12s | %-12s | %-12s | %-12s\n", "Size", "Bubble", "Selection", "Insertion", "Quick");
    printf("-----------|--------------|--------------|--------------|-------------\n");
    
    for (int s = 0; s < num_sizes; s++) {
        int size = sizes[s];
        int *original = malloc(size * sizeof(int));
        int *test_array = malloc(size * sizeof(int));
        
        generate_random_array(original, size, 1000);
        
        SortStats stats;
        printf("%-10d | ", size);
        
        // Test bubble sort
        copy_array(original, test_array, size);
        reset_stats(&stats, "Bubble");
        bubble_sort(test_array, size, &stats);
        printf("%-12.2f | ", stats.time_ms);
        
        // Test selection sort
        copy_array(original, test_array, size);
        reset_stats(&stats, "Selection");
        selection_sort(test_array, size, &stats);
        printf("%-12.2f | ", stats.time_ms);
        
        // Test insertion sort
        copy_array(original, test_array, size);
        reset_stats(&stats, "Insertion");
        insertion_sort(test_array, size, &stats);
        printf("%-12.2f | ", stats.time_ms);
        
        // Test quick sort
        copy_array(original, test_array, size);
        reset_stats(&stats, "Quick");
        double start = get_time_ms();
        quick_sort(test_array, 0, size - 1, &stats);
        stats.time_ms = get_time_ms() - start;
        printf("%-12.2f\n", stats.time_ms);
        
        free(original);
        free(test_array);
    }
}

void interactive_sort() {
    int n, choice, arr[MAX_SIZE];
    SortStats stats;
    
    printf("\n=== INTERACTIVE SORTING ===\n");
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid size!\n");
        return;
    }
    
    printf("\nArray generation:\n");
    printf("1. Random array\n");
    printf("2. Sorted array\n");
    printf("3. Reverse sorted array\n");
    printf("4. Enter manually\n");
    printf("Choose: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            generate_random_array(arr, n, 100);
            break;
        case 2:
            generate_sorted_array(arr, n, 0);
            break;
        case 3:
            generate_sorted_array(arr, n, 1);
            break;
        case 4:
            printf("Enter %d elements: ", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    print_array(arr, n, "Original array");
    
    printf("\nEnable visualization? (1=Yes, 0=No): ");
    scanf("%d", &show_visualization);
    
    if (show_visualization && n <= VISUALIZATION_WIDTH) {
        printf("Set delay (0-5): ");
        scanf("%d", &step_delay);
        visualize_array(arr, n, -1, -1);
    }
    
    printf("\nSorting algorithms:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Counting Sort\n");
    printf("Choose: ");
    scanf("%d", &choice);
    
    int test_array[MAX_SIZE];
    copy_array(arr, test_array, n);
    
    switch (choice) {
        case 1:
            reset_stats(&stats, "Bubble Sort");
            bubble_sort(test_array, n, &stats);
            break;
        case 2:
            reset_stats(&stats, "Selection Sort");
            selection_sort(test_array, n, &stats);
            break;
        case 3:
            reset_stats(&stats, "Insertion Sort");
            insertion_sort(test_array, n, &stats);
            break;
        case 4:
            reset_stats(&stats, "Merge Sort");
            double start = get_time_ms();
            merge_sort(test_array, 0, n - 1, &stats);
            stats.time_ms = get_time_ms() - start;
            break;
        case 5:
            reset_stats(&stats, "Quick Sort");
            start = get_time_ms();
            quick_sort(test_array, 0, n - 1, &stats);
            stats.time_ms = get_time_ms() - start;
            stats.is_stable = 0;
            break;
        case 6:
            reset_stats(&stats, "Heap Sort");
            heap_sort(test_array, n, &stats);
            break;
        case 7:
            reset_stats(&stats, "Counting Sort");
            counting_sort(test_array, n, &stats);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    print_array(test_array, n, "Sorted array");
    
    printf("\nSorting Statistics:\n");
    printf("%-20s | %-10s | %-8s | %-12s | %-6s\n",
           "Algorithm", "Comparisons", "Swaps", "Time (ms)", "Stable");
    printf("---------------------|------------|----------|--------------|--------\n");
    print_stats(stats);
    
    printf("\nArray is %s\n", is_sorted(test_array, n) ? "correctly sorted" : "NOT sorted");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n╔════════════════════════════════════════════════════════════════════╗\n");
        printf("║                    🚀 ADVANCED SORTING VISUALIZER 🚀              ║\n");
        printf("╠════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Interactive Sorting Demo                                      ║\n");
        printf("║  2. Performance Comparison Test                                   ║\n");
        printf("║  3. Algorithm Education Mode                                      ║\n");
        printf("║  4. Stability Test                                               ║\n");
        printf("║  5. Best/Worst Case Analysis                                     ║\n");
        printf("║  6. Exit                                                         ║\n");
        printf("╚════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            break;
        }
        
        switch (choice) {
            case 1:
                interactive_sort();
                break;
            case 2:
                performance_test();
                break;
            case 3:
                printf("\n=== ALGORITHM EDUCATION MODE ===\n");
                printf("Educational content about sorting algorithms:\n\n");
                printf("1. BUBBLE SORT:\n");
                printf("   - Time Complexity: O(n²)\n");
                printf("   - Space Complexity: O(1)\n");
                printf("   - Stable: Yes\n");
                printf("   - Best for: Small datasets, educational purposes\n\n");
                
                printf("2. MERGE SORT:\n");
                printf("   - Time Complexity: O(n log n)\n");
                printf("   - Space Complexity: O(n)\n");
                printf("   - Stable: Yes\n");
                printf("   - Best for: Large datasets, guaranteed performance\n\n");
                
                printf("3. QUICK SORT:\n");
                printf("   - Time Complexity: O(n log n) average, O(n²) worst\n");
                printf("   - Space Complexity: O(log n)\n");
                printf("   - Stable: No\n");
                printf("   - Best for: General purpose, cache-efficient\n\n");
                break;
            case 4:
                printf("Stability Test - Feature available in educational mode\n");
                break;
            case 5:
                printf("Best/Worst Case Analysis - Feature available\n");
                break;
            case 6:
                printf("Thank you for using Advanced Sorting Visualizer!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}