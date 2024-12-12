#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void string_operations();
void dynamic_memory_allocation();
void file_operations();
void pointer_operations();
void structure_union_operations();

// Main Function
int main() {
    int choice;

    // If-Else Example
    printf("Enter a number: ");
    scanf("%d", &choice);
    if (choice > 0) {
        printf("The number is positive\n");
    } else if (choice == 0) {
        printf("The number is zero\n");
    } else {
        printf("The number is negative\n");
    }

    // Switch Case Example
    switch (choice) {
        case 1:
            printf("Choice is one\n");
            break;
        case 2:
            printf("Choice is two\n");
            break;
        default:
            printf("Other choice\n");
    }

    // Conditional Operator
    printf("The absolute value of %d is %d\n", choice, (choice < 0 ? -choice : choice));

    // Loops Example (For Loop)
    printf("For Loop Example: Counting from 1 to 5\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While Loop Example
    printf("While Loop Example: Counting from 1 to 5\n");
    int i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    // Do-While Loop Example
    printf("Do-While Loop Example: Counting from 1 to 5\n");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");

    // Goto Statement Example
    printf("Goto Example: Counting from 1 to 5\n");
    i = 1;
    start:
        if (i <= 5) {
            printf("%d ", i);
            i++;
            goto start;
        }
    printf("\n");

    // Continue and Break Example
    printf("Continue and Break Example: Skipping 3\n");
    for (i = 1; i <= 5; i++) {
        if (i == 3) {
            continue; // Skip 3
        }
        if (i == 4) {
            break; // Stop after 4
        }
        printf("%d ", i);
    }
    printf("\n");

    // Arrays Example
    int arr1D[5] = {1, 2, 3, 4, 5};
    int arr2D[2][2] = {{1, 2}, {3, 4}};
    printf("1D Array Example: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr1D[i]);
    }
    printf("\n");

    printf("2D Array Example: ");
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", arr2D[i][j]);
        }
    }
    printf("\n");

    // String Operations
    string_operations();

    // Dynamic Memory Allocation
    dynamic_memory_allocation();

    // File Operations
    file_operations();

    // Pointer Operations
    pointer_operations();

    // Structure and Union Operations
    structure_union_operations();

    return 0;
}

// String Operations
void string_operations() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[40];

    // String Length
    printf("Length of str1: %lu\n", strlen(str1));

    // String Comparison
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    // String Copy
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // String Reverse
    strrev(str1);
    printf("Reversed string: %s\n", str1);

    // Find Substring
    if (strstr(str2, "orl")) {
        printf("Substring found in str2\n");
    }

    // String Concatenation
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

// Dynamic Memory Allocation
void dynamic_memory_allocation() {
    int *ptr;
    ptr = (int *)malloc(sizeof(int) * 5);

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }

    printf("Dynamically allocated array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr); // Free allocated memory
}

// File Operations
void file_operations() {
    FILE *file;
    file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(file, "Hello, file operations!\n");

    fclose(file);

    file = fopen("example.txt", "r");
    char line[100];
    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            printf("File content: %s", line);
        }
        fclose(file);
    }
}

// Pointer Operations
void pointer_operations() {
    int x = 10;
    int *ptr = &x;

    printf("Value of x: %d\n", *ptr);  // Dereferencing pointer
    printf("Address of x: %p\n", (void *)ptr);

    // Pointer to array
    int arr[] = {1, 2, 3};
    int *arr_ptr = arr;
    printf("Array element using pointer: %d\n", *(arr_ptr + 1));  // Accessing second element
}

// Structure and Union Operations
void structure_union_operations() {
    // Structure Example
    struct Person {
        char name[50];
        int age;
    };
    struct Person person1 = {"Alice", 30};

    // Union Example
    union Data {
        int i;
        float f;
    };
    union Data data;
    data.i = 10;
    
    printf("Structure Example: Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Union Example: Data (int): %d\n", data.i);

    // Array of Structure
    struct Person people[2] = {{"Bob", 25}, {"Charlie", 28}};
    printf("Array of Structures: %s, %d\n", people[0].name, people[0].age);
}

