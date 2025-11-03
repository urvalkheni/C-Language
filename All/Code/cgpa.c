/*
 * Advanced Student Grade Management System v2.0
 * Features: CGPA calculation, grade analysis, statistics,
 *           student records, and comprehensive academic tracking
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 20
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    int rollNo;
    int numSubjects;
    float marks[MAX_SUBJECTS];
    float grades[MAX_SUBJECTS];
    float sgpa;
    float cgpa;
    char letterGrade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void addStudent();
void calculateSGPA(int index);
void calculateCGPA();
void displayStudent(int index);
void displayAllStudents();
void findTopStudent();
void findAverageGPA();
void gradeDistribution();
void studentRanking();
void searchStudent();
void updateStudent();
void deleteStudent();
void subjectWiseAnalysis();
void passFailAnalysis();
void gradeConversion();
char getLetterGrade(float gpa);
void displayMenu();

int main() {
    int choice;
    
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║    Advanced Student Grade Management System v2.0          ║\n");
    printf("║         Comprehensive Academic Tracking System            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    do {
        displayMenu();
        printf("\nEnter your choice (0-16): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                calculateCGPA();
                break;
            case 3:
                displayAllStudents();
                break;
            case 4:
                findTopStudent();
                break;
            case 5:
                findAverageGPA();
                break;
            case 6:
                gradeDistribution();
                break;
            case 7:
                studentRanking();
                break;
            case 8:
                searchStudent();
                break;
            case 9:
                updateStudent();
                break;
            case 10:
                deleteStudent();
                break;
            case 11:
                subjectWiseAnalysis();
                break;
            case 12:
                passFailAnalysis();
                break;
            case 13:
                gradeConversion();
                break;
            case 14: {
                int idx;
                printf("\nEnter student index (1-%d): ", studentCount);
                scanf("%d", &idx);
                if(idx >= 1 && idx <= studentCount) {
                    displayStudent(idx - 1);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 15: {
                printf("\n--- System Statistics ---\n");
                printf("Total students: %d\n", studentCount);
                printf("Max capacity: %d\n", MAX_STUDENTS);
                printf("Available slots: %d\n", MAX_STUDENTS - studentCount);
                break;
            }
            case 16:
                printf("\n--- Grading Scale ---\n");
                printf("A+: 9.0 - 10.0\n");
                printf("A:  8.0 - 8.9\n");
                printf("B+: 7.0 - 7.9\n");
                printf("B:  6.0 - 6.9\n");
                printf("C:  5.0 - 5.9\n");
                printf("D:  4.0 - 4.9\n");
                printf("F:  Below 4.0\n");
                break;
            case 0:
                break;
            default:
                printf("\n✗ Invalid choice!\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); getchar();
        }
        
    } while(choice != 0);
    
    printf("\n✓ Thank you for using Grade Management System!\n");
    return 0;
}

void displayMenu() {
    printf("\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│                    MAIN MENU                            │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  STUDENT MANAGEMENT                                     │\n");
    printf("│  [1]  Add New Student                                   │\n");
    printf("│  [2]  Calculate CGPA for All                            │\n");
    printf("│  [3]  Display All Students                              │\n");
    printf("│  [8]  Search Student                                    │\n");
    printf("│  [9]  Update Student Record                             │\n");
    printf("│  [10] Delete Student                                    │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  ANALYSIS & REPORTS                                     │\n");
    printf("│  [4]  Find Top Student                                  │\n");
    printf("│  [5]  Find Average GPA                                  │\n");
    printf("│  [6]  Grade Distribution                                │\n");
    printf("│  [7]  Student Ranking                                   │\n");
    printf("│  [11] Subject-wise Analysis                             │\n");
    printf("│  [12] Pass/Fail Analysis                                │\n");
    printf("├─────────────────────────────────────────────────────────┤\n");
    printf("│  UTILITIES                                              │\n");
    printf("│  [13] Grade Conversion Calculator                       │\n");
    printf("│  [14] Display Individual Student                        │\n");
    printf("│  [15] System Statistics                                 │\n");
    printf("│  [16] Grading Scale Reference                           │\n");
    printf("│  [0]  Exit                                              │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
}

void addStudent() {
    if(studentCount >= MAX_STUDENTS) {
        printf("\n✗ Maximum student limit reached!\n");
        return;
    }
    
    printf("\n--- Add New Student ---\n");
    Student *s = &students[studentCount];
    
    printf("Enter student name: ");
    getchar();
    fgets(s->name, MAX_NAME, stdin);
    s->name[strcspn(s->name, "\n")] = 0;
    
    printf("Enter roll number: ");
    scanf("%d", &s->rollNo);
    
    printf("Enter number of subjects: ");
    scanf("%d", &s->numSubjects);
    
    if(s->numSubjects > MAX_SUBJECTS) {
        printf("Maximum %d subjects allowed!\n", MAX_SUBJECTS);
        s->numSubjects = MAX_SUBJECTS;
    }
    
    for(int i = 0; i < s->numSubjects; i++) {
        printf("Enter marks for subject %d (0-100): ", i + 1);
        scanf("%f", &s->marks[i]);
        
        // Convert marks to grade points (10-point scale)
        if(s->marks[i] >= 90) s->grades[i] = 10.0;
        else if(s->marks[i] >= 80) s->grades[i] = 9.0;
        else if(s->marks[i] >= 70) s->grades[i] = 8.0;
        else if(s->marks[i] >= 60) s->grades[i] = 7.0;
        else if(s->marks[i] >= 50) s->grades[i] = 6.0;
        else if(s->marks[i] >= 40) s->grades[i] = 5.0;
        else s->grades[i] = 0.0;
    }
    
    calculateSGPA(studentCount);
    s->cgpa = s->sgpa; // Initially CGPA = SGPA
    s->letterGrade = getLetterGrade(s->cgpa);
    
    studentCount++;
    printf("\n✓ Student added successfully!\n");
}

void calculateSGPA(int index) {
    Student *s = &students[index];
    float sum = 0;
    
    for(int i = 0; i < s->numSubjects; i++) {
        sum += s->grades[i];
    }
    
    s->sgpa = sum / s->numSubjects;
}

void calculateCGPA() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    printf("\n--- Calculate CGPA ---\n");
    for(int i = 0; i < studentCount; i++) {
        students[i].cgpa = students[i].sgpa;
        students[i].letterGrade = getLetterGrade(students[i].cgpa);
    }
    
    printf("✓ CGPA calculated for all students!\n");
}

void displayStudent(int index) {
    Student *s = &students[index];
    
    printf("\n┌────────────────────────────────────────┐\n");
    printf("│         STUDENT REPORT CARD            │\n");
    printf("├────────────────────────────────────────┤\n");
    printf("│ Name: %-32s │\n", s->name);
    printf("│ Roll No: %-28d │\n", s->rollNo);
    printf("├────────────────────────────────────────┤\n");
    
    for(int i = 0; i < s->numSubjects; i++) {
        printf("│ Subject %2d: %5.1f marks (GP: %.1f)   │\n", 
               i + 1, s->marks[i], s->grades[i]);
    }
    
    printf("├────────────────────────────────────────┤\n");
    printf("│ SGPA:  %.2f                            │\n", s->sgpa);
    printf("│ CGPA:  %.2f                            │\n", s->cgpa);
    printf("│ Grade: %c                              │\n", s->letterGrade);
    printf("└────────────────────────────────────────┘\n");
}

void displayAllStudents() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    printf("\n--- All Students ---\n\n");
    printf("%-5s %-25s %-10s %-8s %-8s %-6s\n", 
           "Sr.", "Name", "Roll No", "SGPA", "CGPA", "Grade");
    printf("─────────────────────────────────────────────────────────────\n");
    
    for(int i = 0; i < studentCount; i++) {
        printf("%-5d %-25s %-10d %-8.2f %-8.2f %-6c\n",
               i + 1, students[i].name, students[i].rollNo,
               students[i].sgpa, students[i].cgpa, students[i].letterGrade);
    }
}

void findTopStudent() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int topIndex = 0;
    for(int i = 1; i < studentCount; i++) {
        if(students[i].cgpa > students[topIndex].cgpa) {
            topIndex = i;
        }
    }
    
    printf("\n--- Top Student ---\n");
    displayStudent(topIndex);
}

void findAverageGPA() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    float totalCGPA = 0, totalSGPA = 0;
    for(int i = 0; i < studentCount; i++) {
        totalCGPA += students[i].cgpa;
        totalSGPA += students[i].sgpa;
    }
    
    printf("\n--- Average GPA ---\n");
    printf("Average SGPA: %.2f\n", totalSGPA / studentCount);
    printf("Average CGPA: %.2f\n", totalCGPA / studentCount);
    printf("Total students: %d\n", studentCount);
}

void gradeDistribution() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int gradeCount[7] = {0}; // A+, A, B+, B, C, D, F
    
    for(int i = 0; i < studentCount; i++) {
        char grade = students[i].letterGrade;
        if(grade == 'A' && students[i].cgpa >= 9.0) gradeCount[0]++;
        else if(grade == 'A') gradeCount[1]++;
        else if(grade == 'B' && students[i].cgpa >= 7.0) gradeCount[2]++;
        else if(grade == 'B') gradeCount[3]++;
        else if(grade == 'C') gradeCount[4]++;
        else if(grade == 'D') gradeCount[5]++;
        else gradeCount[6]++;
    }
    
    printf("\n--- Grade Distribution ---\n\n");
    printf("Grade  | Count | Percentage\n");
    printf("-------+-------+-----------\n");
    printf("A+     | %5d | %6.2f%%\n", gradeCount[0], (gradeCount[0] * 100.0) / studentCount);
    printf("A      | %5d | %6.2f%%\n", gradeCount[1], (gradeCount[1] * 100.0) / studentCount);
    printf("B+     | %5d | %6.2f%%\n", gradeCount[2], (gradeCount[2] * 100.0) / studentCount);
    printf("B      | %5d | %6.2f%%\n", gradeCount[3], (gradeCount[3] * 100.0) / studentCount);
    printf("C      | %5d | %6.2f%%\n", gradeCount[4], (gradeCount[4] * 100.0) / studentCount);
    printf("D      | %5d | %6.2f%%\n", gradeCount[5], (gradeCount[5] * 100.0) / studentCount);
    printf("F      | %5d | %6.2f%%\n", gradeCount[6], (gradeCount[6] * 100.0) / studentCount);
}

void studentRanking() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    // Create a sorted copy of indices
    int indices[MAX_STUDENTS];
    for(int i = 0; i < studentCount; i++) {
        indices[i] = i;
    }
    
    // Bubble sort by CGPA
    for(int i = 0; i < studentCount - 1; i++) {
        for(int j = 0; j < studentCount - i - 1; j++) {
            if(students[indices[j]].cgpa < students[indices[j + 1]].cgpa) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("\n--- Student Ranking ---\n\n");
    printf("%-5s %-25s %-8s %-6s\n", "Rank", "Name", "CGPA", "Grade");
    printf("──────────────────────────────────────────────\n");
    
    for(int i = 0; i < studentCount; i++) {
        int idx = indices[i];
        printf("%-5d %-25s %-8.2f %-6c\n",
               i + 1, students[idx].name, students[idx].cgpa, students[idx].letterGrade);
    }
}

void searchStudent() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int rollNo;
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNo);
    
    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollNo == rollNo) {
            displayStudent(i);
            return;
        }
    }
    
    printf("\n✗ Student not found!\n");
}

void updateStudent() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int rollNo;
    printf("\nEnter roll number to update: ");
    scanf("%d", &rollNo);
    
    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollNo == rollNo) {
            printf("\nUpdating student: %s\n", students[i].name);
            printf("Enter number of subjects: ");
            scanf("%d", &students[i].numSubjects);
            
            for(int j = 0; j < students[i].numSubjects; j++) {
                printf("Enter marks for subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
                
                if(students[i].marks[j] >= 90) students[i].grades[j] = 10.0;
                else if(students[i].marks[j] >= 80) students[i].grades[j] = 9.0;
                else if(students[i].marks[j] >= 70) students[i].grades[j] = 8.0;
                else if(students[i].marks[j] >= 60) students[i].grades[j] = 7.0;
                else if(students[i].marks[j] >= 50) students[i].grades[j] = 6.0;
                else if(students[i].marks[j] >= 40) students[i].grades[j] = 5.0;
                else students[i].grades[j] = 0.0;
            }
            
            calculateSGPA(i);
            students[i].cgpa = students[i].sgpa;
            students[i].letterGrade = getLetterGrade(students[i].cgpa);
            
            printf("\n✓ Student updated successfully!\n");
            return;
        }
    }
    
    printf("\n✗ Student not found!\n");
}

void deleteStudent() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int rollNo;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &rollNo);
    
    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollNo == rollNo) {
            printf("Deleting student: %s\n", students[i].name);
            
            for(int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            
            studentCount--;
            printf("\n✓ Student deleted successfully!\n");
            return;
        }
    }
    
    printf("\n✗ Student not found!\n");
}

void subjectWiseAnalysis() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    printf("\n--- Subject-wise Analysis ---\n\n");
    
    int maxSubjects = 0;
    for(int i = 0; i < studentCount; i++) {
        if(students[i].numSubjects > maxSubjects) {
            maxSubjects = students[i].numSubjects;
        }
    }
    
    for(int sub = 0; sub < maxSubjects; sub++) {
        float total = 0, count = 0;
        for(int i = 0; i < studentCount; i++) {
            if(sub < students[i].numSubjects) {
                total += students[i].marks[sub];
                count++;
            }
        }
        
        if(count > 0) {
            printf("Subject %d: Average = %.2f (Students: %.0f)\n", 
                   sub + 1, total / count, count);
        }
    }
}

void passFailAnalysis() {
    if(studentCount == 0) {
        printf("\n✗ No students in database!\n");
        return;
    }
    
    int pass = 0, fail = 0;
    for(int i = 0; i < studentCount; i++) {
        if(students[i].cgpa >= 4.0) {
            pass++;
        } else {
            fail++;
        }
    }
    
    printf("\n--- Pass/Fail Analysis ---\n");
    printf("Passed: %d (%.2f%%)\n", pass, (pass * 100.0) / studentCount);
    printf("Failed: %d (%.2f%%)\n", fail, (fail * 100.0) / studentCount);
}

void gradeConversion() {
    float marks;
    printf("\nEnter marks (0-100): ");
    scanf("%f", &marks);
    
    float gp;
    if(marks >= 90) gp = 10.0;
    else if(marks >= 80) gp = 9.0;
    else if(marks >= 70) gp = 8.0;
    else if(marks >= 60) gp = 7.0;
    else if(marks >= 50) gp = 6.0;
    else if(marks >= 40) gp = 5.0;
    else gp = 0.0;
    
    printf("\nMarks: %.1f\n", marks);
    printf("Grade Point: %.1f\n", gp);
    printf("Letter Grade: %c\n", getLetterGrade(gp));
}

char getLetterGrade(float gpa) {
    if(gpa >= 9.0) return 'A';
    else if(gpa >= 8.0) return 'A';
    else if(gpa >= 7.0) return 'B';
    else if(gpa >= 6.0) return 'B';
    else if(gpa >= 5.0) return 'C';
    else if(gpa >= 4.0) return 'D';
    else return 'F';
}
