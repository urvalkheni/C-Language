#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_STUDENTS 500
#define MAX_SUBJECTS 20
#define MAX_SEMESTERS 8
#define MAX_NAME_LEN 100
#define DATA_FILE "cgpa_database.dat"
#define REPORT_FILE "cgpa_report.txt"

typedef struct {
    char code[10];
    char name[50];
    int credits;
    float marks;
    char grade;
    float gradePoints;
} Subject;

typedef struct {
    int semester;
    Subject subjects[MAX_SUBJECTS];
    int subjectCount;
    float sgpa;
    int totalCredits;
} Semester;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char rollNumber[20];
    char department[50];
    char batch[10];
    char email[MAX_NAME_LEN];
    char phone[15];
    Semester semesters[MAX_SEMESTERS];
    int semesterCount;
    float cgpa;
    float totalCredits;
    char overallGrade[20];
    char status[20]; // Regular, Probation, Dean's List
    int backlogCount;
    float attendancePercentage;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void loadData();
void saveData();
void addStudent();
void addSemesterData();
void calculateGrades();
void displayStudentProfile();
void generateTranscript();
void classStatistics();
void departmentAnalysis();
void gradeDistribution();
void scholarshipEligible();
void probationList();
void rankingSystem();
void performanceTrends();
void comparativeAnalysis();
void advancedReports();
void exportData();
void importData();
float calculateSGPA(Semester *sem);
float calculateCGPA(Student *student);
char getLetterGrade(float marks);
float getGradePoints(char grade);
void updateGPASystem();
void detailedAnalytics();
void predictiveAnalysis();

void loadData() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        fread(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("✓ Database loaded: %d students found.\n", studentCount);
    } else {
        printf("No existing database found. Starting fresh.\n");
        studentCount = 0;
    }
}

void saveData() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file) {
        fwrite(&studentCount, sizeof(int), 1, file);
        fwrite(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("✓ Database saved successfully!\n");
    } else {
        printf("✗ Error saving database!\n");
    }
}

char getLetterGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else if (marks >= 50) return 'E';
    else return 'F';
}

float getGradePoints(char grade) {
    switch (grade) {
        case 'A': return 10.0;
        case 'B': return 8.0;
        case 'C': return 6.0;
        case 'D': return 4.0;
        case 'E': return 2.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

float calculateSGPA(Semester *sem) {
    float totalGradePoints = 0;
    int totalCredits = 0;
    
    for (int i = 0; i < sem->subjectCount; i++) {
        totalGradePoints += sem->subjects[i].gradePoints * sem->subjects[i].credits;
        totalCredits += sem->subjects[i].credits;
    }
    
    sem->totalCredits = totalCredits;
    return totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
}

float calculateCGPA(Student *student) {
    float totalGradePoints = 0;
    int totalCredits = 0;
    
    for (int i = 0; i < student->semesterCount; i++) {
        for (int j = 0; j < student->semesters[i].subjectCount; j++) {
            Subject *sub = &student->semesters[i].subjects[j];
            totalGradePoints += sub->gradePoints * sub->credits;
            totalCredits += sub->credits;
        }
    }
    
    student->totalCredits = totalCredits;
    return totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    Student *s = &students[studentCount];
    
    printf("\n=== ADD NEW STUDENT ===\n");
    s->id = studentCount + 1;
    
    printf("Enter student name: ");
    scanf(" %[^\n]", s->name);
    
    printf("Enter roll number: ");
    scanf(" %[^\n]", s->rollNumber);
    
    printf("Enter department: ");
    scanf(" %[^\n]", s->department);
    
    printf("Enter batch year: ");
    scanf(" %[^\n]", s->batch);
    
    printf("Enter email: ");
    scanf(" %[^\n]", s->email);
    
    printf("Enter phone: ");
    scanf(" %[^\n]", s->phone);
    
    printf("Enter attendance percentage: ");
    scanf("%f", &s->attendancePercentage);
    
    // Initialize defaults
    s->semesterCount = 0;
    s->cgpa = 0.0;
    s->totalCredits = 0;
    s->backlogCount = 0;
    strcpy(s->status, "Regular");
    strcpy(s->overallGrade, "Not Calculated");
    
    studentCount++;
    printf("✓ Student added successfully with ID: %d\n", s->id);
    saveData();
}

void addSemesterData() {
    int studentId, semesterNum;
    printf("Enter student ID: ");
    scanf("%d", &studentId);
    
    Student *student = NULL;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            student = &students[i];
            break;
        }
    }
    
    if (!student) {
        printf("Student not found!\n");
        return;
    }
    
    printf("Enter semester number (1-8): ");
    scanf("%d", &semesterNum);
    
    if (semesterNum < 1 || semesterNum > 8) {
        printf("Invalid semester number!\n");
        return;
    }
    
    Semester *sem = &student->semesters[student->semesterCount];
    sem->semester = semesterNum;
    
    printf("Enter number of subjects: ");
    scanf("%d", &sem->subjectCount);
    
    printf("\nEnter subject details:\n");
    for (int i = 0; i < sem->subjectCount; i++) {
        Subject *sub = &sem->subjects[i];
        
        printf("\nSubject %d:\n", i + 1);
        printf("Subject code: ");
        scanf(" %[^\n]", sub->code);
        
        printf("Subject name: ");
        scanf(" %[^\n]", sub->name);
        
        printf("Credits: ");
        scanf("%d", &sub->credits);
        
        printf("Marks (0-100): ");
        scanf("%f", &sub->marks);
        
        sub->grade = getLetterGrade(sub->marks);
        sub->gradePoints = getGradePoints(sub->grade);
        
        if (sub->grade == 'F') {
            student->backlogCount++;
        }
    }
    
    sem->sgpa = calculateSGPA(sem);
    student->semesterCount++;
    student->cgpa = calculateCGPA(student);
    
    // Update overall grade and status
    if (student->cgpa >= 9.0) {
        strcpy(student->overallGrade, "Outstanding");
        strcpy(student->status, "Dean's List");
    } else if (student->cgpa >= 8.0) {
        strcpy(student->overallGrade, "Excellent");
        strcpy(student->status, "Honor Roll");
    } else if (student->cgpa >= 7.0) {
        strcpy(student->overallGrade, "Very Good");
        strcpy(student->status, "Regular");
    } else if (student->cgpa >= 6.0) {
        strcpy(student->overallGrade, "Good");
        strcpy(student->status, "Regular");
    } else if (student->cgpa >= 5.0) {
        strcpy(student->overallGrade, "Average");
        strcpy(student->status, "Regular");
    } else {
        strcpy(student->overallGrade, "Below Average");
        strcpy(student->status, "Probation");
    }
    
    printf("\n✓ Semester data added successfully!\n");
    printf("SGPA for Semester %d: %.2f\n", semesterNum, sem->sgpa);
    printf("Updated CGPA: %.2f\n", student->cgpa);
    
    saveData();
}

void displayStudentProfile() {
    int studentId;
    printf("Enter student ID: ");
    scanf("%d", &studentId);
    
    Student *student = NULL;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            student = &students[i];
            break;
        }
    }
    
    if (!student) {
        printf("Student not found!\n");
        return;
    }
    
    printf("\n╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                           STUDENT PROFILE                                                ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID: %-6d  Name: %-50s  Roll: %-15s ║\n", student->id, student->name, student->rollNumber);
    printf("║ Department: %-20s  Batch: %-8s  Status: %-20s ║\n", student->department, student->batch, student->status);
    printf("║ Email: %-50s  Phone: %-15s ║\n", student->email, student->phone);
    printf("║ CGPA: %-6.2f  Grade: %-15s  Credits: %-6.0f  Attendance: %-6.1f%% ║\n", 
           student->cgpa, student->overallGrade, student->totalCredits, student->attendancePercentage);
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                         SEMESTER WISE PERFORMANCE                                        ║\n");
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    
    for (int i = 0; i < student->semesterCount; i++) {
        Semester *sem = &student->semesters[i];
        printf("║ Semester %d: SGPA = %-6.2f  Credits = %-3d  Subjects = %-2d                                    ║\n", 
               sem->semester, sem->sgpa, sem->totalCredits, sem->subjectCount);
        
        for (int j = 0; j < sem->subjectCount; j++) {
            Subject *sub = &sem->subjects[j];
            printf("║   %-8s %-30s Credits:%-2d Marks:%-6.1f Grade:%-2c GP:%-4.1f                ║\n", 
                   sub->code, sub->name, sub->credits, sub->marks, sub->grade, sub->gradePoints);
        }
        printf("║                                                                                                      ║\n");
    }
    
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

void classStatistics() {
    if (studentCount == 0) {
        printf("No students in database!\n");
        return;
    }
    
    printf("\n=== CLASS STATISTICS ===\n");
    
    float totalCGPA = 0, highest = 0, lowest = 10.0;
    int deansList = 0, probation = 0, regular = 0;
    float cgpaSum[10] = {0}; // For CGPA ranges
    int cgpaCount[10] = {0};
    
    for (int i = 0; i < studentCount; i++) {
        Student *s = &students[i];
        totalCGPA += s->cgpa;
        
        if (s->cgpa > highest) highest = s->cgpa;
        if (s->cgpa < lowest && s->cgpa > 0) lowest = s->cgpa;
        
        if (strcmp(s->status, "Dean's List") == 0) deansList++;
        else if (strcmp(s->status, "Probation") == 0) probation++;
        else regular++;
        
        // CGPA distribution
        int range = (int)(s->cgpa);
        if (range < 10) cgpaCount[range]++;
    }
    
    float averageCGPA = totalCGPA / studentCount;
    
    printf("📊 OVERALL STATISTICS\n");
    printf("Total Students: %d\n", studentCount);
    printf("Average CGPA: %.2f\n", averageCGPA);
    printf("Highest CGPA: %.2f\n", highest);
    printf("Lowest CGPA: %.2f\n", lowest);
    
    printf("\n📈 STATUS DISTRIBUTION\n");
    printf("Dean's List: %d (%.1f%%)\n", deansList, 100.0 * deansList / studentCount);
    printf("Regular: %d (%.1f%%)\n", regular, 100.0 * regular / studentCount);
    printf("Probation: %d (%.1f%%)\n", probation, 100.0 * probation / studentCount);
    
    printf("\n📊 CGPA DISTRIBUTION\n");
    for (int i = 9; i >= 0; i--) {
        if (cgpaCount[i] > 0) {
            printf("%.1f - %.1f: %d students (%.1f%%)\n", 
                   (float)i, (float)i + 0.9, cgpaCount[i], 100.0 * cgpaCount[i] / studentCount);
        }
    }
}

void departmentAnalysis() {
    printf("\n=== DEPARTMENT WISE ANALYSIS ===\n");
    
    // Count unique departments
    char departments[50][50];
    int deptCount[50] = {0};
    float deptCGPA[50] = {0};
    int uniqueDepts = 0;
    
    for (int i = 0; i < studentCount; i++) {
        int found = 0;
        for (int j = 0; j < uniqueDepts; j++) {
            if (strcmp(students[i].department, departments[j]) == 0) {
                deptCount[j]++;
                deptCGPA[j] += students[i].cgpa;
                found = 1;
                break;
            }
        }
        
        if (!found && uniqueDepts < 50) {
            strcpy(departments[uniqueDepts], students[i].department);
            deptCount[uniqueDepts] = 1;
            deptCGPA[uniqueDepts] = students[i].cgpa;
            uniqueDepts++;
        }
    }
    
    printf("📊 DEPARTMENT PERFORMANCE\n");
    for (int i = 0; i < uniqueDepts; i++) {
        float avgCGPA = deptCGPA[i] / deptCount[i];
        printf("%-20s: %d students, Average CGPA: %.2f\n", 
               departments[i], deptCount[i], avgCGPA);
    }
}

void rankingSystem() {
    printf("\n=== STUDENT RANKING SYSTEM ===\n");
    
    // Create array of indices for sorting
    int indices[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        indices[i] = i;
    }
    
    // Sort by CGPA (bubble sort for simplicity)
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[indices[j]].cgpa < students[indices[j + 1]].cgpa) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("🏆 TOP PERFORMERS\n");
    printf("%-5s %-25s %-15s %-20s %-8s %-15s\n", 
           "Rank", "Name", "Roll Number", "Department", "CGPA", "Status");
    printf("─────────────────────────────────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < studentCount && i < 20; i++) {
        Student *s = &students[indices[i]];
        printf("%-5d %-25s %-15s %-20s %-8.2f %-15s\n", 
               i + 1, s->name, s->rollNumber, s->department, s->cgpa, s->status);
    }
}

void scholarshipEligible() {
    printf("\n=== SCHOLARSHIP ELIGIBLE STUDENTS ===\n");
    
    printf("🎓 MERIT SCHOLARSHIP (CGPA >= 8.5)\n");
    printf("%-25s %-15s %-20s %-8s %-12s\n", 
           "Name", "Roll Number", "Department", "CGPA", "Attendance");
    printf("─────────────────────────────────────────────────────────────────────────────────\n");
    
    int count = 0;
    for (int i = 0; i < studentCount; i++) {
        Student *s = &students[i];
        if (s->cgpa >= 8.5 && s->attendancePercentage >= 75.0 && s->backlogCount == 0) {
            printf("%-25s %-15s %-20s %-8.2f %-12.1f%%\n", 
                   s->name, s->rollNumber, s->department, s->cgpa, s->attendancePercentage);
            count++;
        }
    }
    
    printf("\nTotal eligible students: %d\n", count);
}

void generateTranscript() {
    int studentId;
    printf("Enter student ID for transcript: ");
    scanf("%d", &studentId);
    
    Student *student = NULL;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            student = &students[i];
            break;
        }
    }
    
    if (!student) {
        printf("Student not found!\n");
        return;
    }
    
    char filename[100];
    sprintf(filename, "transcript_%s.txt", student->rollNumber);
    
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error creating transcript file!\n");
        return;
    }
    
    fprintf(file, "╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    fprintf(file, "║                                        OFFICIAL TRANSCRIPT                                               ║\n");
    fprintf(file, "╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    fprintf(file, "║ Name: %-50s  Roll No: %-20s ║\n", student->name, student->rollNumber);
    fprintf(file, "║ Department: %-30s  Batch: %-15s ║\n", student->department, student->batch);
    fprintf(file, "║ CGPA: %-8.2f  Overall Grade: %-25s ║\n", student->cgpa, student->overallGrade);
    fprintf(file, "╠════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    
    for (int i = 0; i < student->semesterCount; i++) {
        Semester *sem = &student->semesters[i];
        fprintf(file, "║ SEMESTER %d                                              SGPA: %-6.2f  Credits: %-3d    ║\n", 
                sem->semester, sem->sgpa, sem->totalCredits);
        fprintf(file, "║                                                                                                      ║\n");
        
        for (int j = 0; j < sem->subjectCount; j++) {
            Subject *sub = &sem->subjects[j];
            fprintf(file, "║ %-8s %-35s Credits: %-2d  Grade: %-2c  Points: %-4.1f     ║\n", 
                    sub->code, sub->name, sub->credits, sub->grade, sub->gradePoints);
        }
        fprintf(file, "║                                                                                                      ║\n");
    }
    
    fprintf(file, "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    
    fclose(file);
    printf("✓ Transcript generated: %s\n", filename);
}

void advancedReports() {
    printf("\n=== ADVANCED REPORTS ===\n");
    printf("1. Performance Trends\n");
    printf("2. Grade Distribution\n");
    printf("3. Credit Analysis\n");
    printf("4. Attendance vs Performance\n");
    printf("5. Subject Difficulty Analysis\n");
    printf("Enter choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\n📈 PERFORMANCE TRENDS\n");
            // Analyze semester-wise CGPA trends
            for (int sem = 1; sem <= 8; sem++) {
                float totalSGPA = 0;
                int count = 0;
                
                for (int i = 0; i < studentCount; i++) {
                    for (int j = 0; j < students[i].semesterCount; j++) {
                        if (students[i].semesters[j].semester == sem) {
                            totalSGPA += students[i].semesters[j].sgpa;
                            count++;
                            break;
                        }
                    }
                }
                
                if (count > 0) {
                    printf("Semester %d: Average SGPA = %.2f (%d students)\n", 
                           sem, totalSGPA / count, count);
                }
            }
            break;
            
        case 4:
            printf("\n📊 ATTENDANCE vs PERFORMANCE CORRELATION\n");
            printf("%-15s %-12s %-8s\n", "Attendance", "Students", "Avg CGPA");
            printf("──────────────────────────────────────\n");
            
            float ranges[] = {90, 80, 70, 60, 0};
            for (int r = 0; r < 4; r++) {
                float totalCGPA = 0;
                int count = 0;
                
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].attendancePercentage >= ranges[r] && 
                        students[i].attendancePercentage < (r == 0 ? 100 : ranges[r-1])) {
                        totalCGPA += students[i].cgpa;
                        count++;
                    }
                }
                
                if (count > 0) {
                    printf("%-15s %-12d %-8.2f\n", 
                           r == 0 ? "90-100%" : 
                           r == 1 ? "80-89%" : 
                           r == 2 ? "70-79%" : "60-69%", 
                           count, totalCGPA / count);
                }
            }
            break;
            
        default:
            printf("Feature under development!\n");
    }
}

int main() {
    int choice;
    
    loadData();
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                            🎓 ADVANCED CGPA ANALYSIS SYSTEM 🎓                            ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Add Student                    11. Ranking System                                     ║\n");
        printf("║  2. Add Semester Data              12. Scholarship Eligible                               ║\n");
        printf("║  3. Display Student Profile        13. Generate Transcript                                ║\n");
        printf("║  4. Class Statistics               14. Department Analysis                                ║\n");
        printf("║  5. Grade Distribution             15. Advanced Reports                                   ║\n");
        printf("║  6. Performance Trends             16. Export Data                                        ║\n");
        printf("║  7. Probation List                 17. Import Data                                        ║\n");
        printf("║  8. Dean's List                    18. Backup Database                                    ║\n");
        printf("║  9. Subject Analysis               19. Analytics Dashboard                                ║\n");
        printf("║ 10. Comparative Analysis           20. Save & Exit                                        ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addSemesterData();
                break;
            case 3:
                displayStudentProfile();
                break;
            case 4:
                classStatistics();
                break;
            case 11:
                rankingSystem();
                break;
            case 12:
                scholarshipEligible();
                break;
            case 13:
                generateTranscript();
                break;
            case 14:
                departmentAnalysis();
                break;
            case 15:
                advancedReports();
                break;
            case 20:
                saveData();
                printf("💾 Database saved successfully!\n");
                printf("👋 Thank you for using Advanced CGPA Analysis System!\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}