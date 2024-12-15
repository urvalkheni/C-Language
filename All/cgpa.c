#include <stdio.h>
#include <string.h>
#define NUM_STUDENTS 10
// Structure to store student data
struct Student {
    char name[50];
    int rollNumber;
    float marks[5]; // 5 subjects
    float percentage;
    char grade;
    char result[20];
};
// Function to calculate percentage and grade
void calculateGrade(struct Student *student) {
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += student->marks[i];
    }
    student->percentage = total / 5;

    if (student->percentage >= 85) {
        student->grade = 'A';
        strcpy(student->result, "Distinction");
    } else if (student->percentage >= 60) {
        student->grade = 'B';
        strcpy(student->result, "First Class");
    } else if (student->percentage >= 40) {
        student->grade = 'C';
        strcpy(student->result, "Pass");
    } else {
        student->grade = 'F';
        strcpy(student->result, "Fail");
    }
}
// Main function
int main() {
    struct Student students[NUM_STUDENTS];
    printf("Enter details for %d students:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]%*c", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        calculateGrade(&students[i]);
    }
    printf("\nStudent Results:\n");
    printf("-------------------------------------------------------------\n");
    printf("Roll No | Name           | Percentage | Grade | Result       \n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%-8d | %-14s | %-10.2f | %-5c | %-12s\n",
               students[i].rollNumber,
               students[i].name,
               students[i].percentage,
               students[i].grade,
               students[i].result);
    }
    printf("-------------------------------------------------------------\n");
    return 0;
}
