#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Enter Student Marks: ");
    scanf("%f", &students[studentCount].marks);

    studentCount++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display!\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("----------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", 
               students[i].id, students[i].name, students[i].marks);
    }
    printf("----------------------------\n");
}

void searchStudent() {
    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student Found: ID: %d, Name: %s, Marks: %.2f\n",
                   students[i].id, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
