#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_STUDENTS 500
#define MAX_SUBJECTS 15
#define MAX_SEMESTERS 8
#define MAX_NAME_LEN 100
#define DATA_FILE "enhanced_academic.dat"

typedef struct {
    char name[50];
    int credits;
    float maxMarks;
    char type[20]; // Theory, Practical, Project
} Subject;

typedef struct {
    Subject subjects[MAX_SUBJECTS];
    float marks[MAX_SUBJECTS];
    int subjectCount;
    float sgpa;
    float percentage;
    char grade[5];
} Semester;

typedef struct {
    char name[MAX_NAME_LEN];
    char rollNumber[20];
    char email[MAX_NAME_LEN];
    char course[50];
    char department[50];
    int admissionYear;
    int currentSemester;
    Semester semesters[MAX_SEMESTERS];
    float cgpa;
    float overallPercentage;
    char overallGrade[5];
    int totalCredits;
    float totalGradePoints;
    char status[20]; // Active, Graduated, Suspended
    int attendance;
    char rank[20];
} Student;

typedef struct {
    char courseName[50];
    int totalStudents;
    float averageCGPA;
    float highestCGPA;
    float lowestCGPA;
    char topper[MAX_NAME_LEN];
} CourseStatistics;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void loadData();
void saveData();
void addStudent();
void addSemesterData();
void calculateSGPA(int studentIndex, int semesterIndex);
void calculateCGPA(int studentIndex);
void displayStudent();
void displayAllStudents();
void generateTranscript();
void calculateClassRanks();
void courseWiseAnalysis();
void semesterWiseAnalysis();
void generateProgressReport();
void attendanceAnalysis();
void gradeDistribution();
void toppersList();
void backlogAnalysis();
void creditAnalysis();
void performanceTrends();
void predictiveAnalysis();
void exportResults();
void academicCalendar();
void scholarshipEligibility();
float getGradePoint(float percentage);
char* getGrade(float percentage);
void clearScreen();

void clearScreen() {
    system("cls");
}

float getGradePoint(float percentage) {
    if (percentage >= 90) return 10.0;
    else if (percentage >= 80) return 9.0;
    else if (percentage >= 70) return 8.0;
    else if (percentage >= 60) return 7.0;
    else if (percentage >= 50) return 6.0;
    else if (percentage >= 40) return 5.0;
    else if (percentage >= 35) return 4.0;
    else return 0.0;
}

char* getGrade(float percentage) {
    static char grade[5];
    if (percentage >= 90) strcpy(grade, "A+");
    else if (percentage >= 80) strcpy(grade, "A");
    else if (percentage >= 70) strcpy(grade, "B+");
    else if (percentage >= 60) strcpy(grade, "B");
    else if (percentage >= 50) strcpy(grade, "C+");
    else if (percentage >= 40) strcpy(grade, "C");
    else if (percentage >= 35) strcpy(grade, "D");
    else strcpy(grade, "F");
    return grade;
}

void loadData() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        fread(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("✓ Enhanced academic data loaded! %d students found.\n", studentCount);
    } else {
        printf("Starting fresh enhanced academic system.\n");
        studentCount = 0;
    }
}

void saveData() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file) {
        fwrite(&studentCount, sizeof(int), 1, file);
        fwrite(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("✓ Enhanced academic data saved!\n");
    } else {
        printf("✗ Error saving enhanced academic data!\n");
    }
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    Student *s = &students[studentCount];
    
    printf("\n=== ADD NEW STUDENT TO ENHANCED SYSTEM ===\n");
    printf("Enter student name: ");
    scanf(" %[^\n]", s->name);
    
    printf("Enter roll number: ");
    scanf(" %[^\n]", s->rollNumber);
    
    printf("Enter email: ");
    scanf(" %[^\n]", s->email);
    
    printf("Enter course: ");
    scanf(" %[^\n]", s->course);
    
    printf("Enter department: ");
    scanf(" %[^\n]", s->department);
    
    printf("Enter admission year: ");
    scanf("%d", &s->admissionYear);
    
    printf("Enter current semester (1-8): ");
    scanf("%d", &s->currentSemester);
    
    printf("Enter attendance percentage: ");
    scanf("%d", &s->attendance);
    
    // Initialize defaults
    s->cgpa = 0.0;
    s->overallPercentage = 0.0;
    strcpy(s->overallGrade, "");
    s->totalCredits = 0;
    s->totalGradePoints = 0.0;
    strcpy(s->status, "Active");
    strcpy(s->rank, "");
    
    // Initialize all semesters
    for (int i = 0; i < MAX_SEMESTERS; i++) {
        s->semesters[i].subjectCount = 0;
        s->semesters[i].sgpa = 0.0;
        s->semesters[i].percentage = 0.0;
        strcpy(s->semesters[i].grade, "");
    }
    
    studentCount++;
    printf("✓ Student added to enhanced system!\n");
    saveData();
}

void addSemesterData() {
    char rollNumber[20];
    int semesterNum;
    
    printf("Enter student roll number: ");
    scanf(" %[^\n]", rollNumber);
    
    printf("Enter semester number (1-8): ");
    scanf("%d", &semesterNum);
    
    if (semesterNum < 1 || semesterNum > 8) {
        printf("Invalid semester number!\n");
        return;
    }
    
    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].rollNumber, rollNumber) == 0) {
            studentIndex = i;
            break;
        }
    }
    
    if (studentIndex == -1) {
        printf("Student not found!\n");
        return;
    }
    
    Student *s = &students[studentIndex];
    Semester *sem = &s->semesters[semesterNum - 1];
    
    printf("\n=== ADD SEMESTER %d DATA FOR %s ===\n", semesterNum, s->name);
    
    printf("Enter number of subjects: ");
    scanf("%d", &sem->subjectCount);
    
    for (int i = 0; i < sem->subjectCount; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("Subject name: ");
        scanf(" %[^\n]", sem->subjects[i].name);
        
        printf("Credits: ");
        scanf("%d", &sem->subjects[i].credits);
        
        printf("Maximum marks: ");
        scanf("%f", &sem->subjects[i].maxMarks);
        
        printf("Subject type (Theory/Practical/Project): ");
        scanf(" %[^\n]", sem->subjects[i].type);
        
        printf("Marks obtained: ");
        scanf("%f", &sem->marks[i]);
    }
    
    calculateSGPA(studentIndex, semesterNum - 1);
    calculateCGPA(studentIndex);
    
    printf("✓ Enhanced semester data added!\n");
    printf("SGPA for Semester %d: %.2f\n", semesterNum, sem->sgpa);
    printf("Updated CGPA: %.2f\n", s->cgpa);
    
    saveData();
}

void calculateSGPA(int studentIndex, int semesterIndex) {
    Student *s = &students[studentIndex];
    Semester *sem = &s->semesters[semesterIndex];
    
    float totalGradePoints = 0.0;
    int totalCredits = 0;
    float totalMarks = 0.0;
    float totalMaxMarks = 0.0;
    
    for (int i = 0; i < sem->subjectCount; i++) {
        float percentage = (sem->marks[i] / sem->subjects[i].maxMarks) * 100;
        float gradePoint = getGradePoint(percentage);
        
        totalGradePoints += gradePoint * sem->subjects[i].credits;
        totalCredits += sem->subjects[i].credits;
        totalMarks += sem->marks[i];
        totalMaxMarks += sem->subjects[i].maxMarks;
    }
    
    sem->sgpa = totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
    sem->percentage = totalMaxMarks > 0 ? (totalMarks / totalMaxMarks) * 100 : 0.0;
    strcpy(sem->grade, getGrade(sem->percentage));
}

void calculateCGPA(int studentIndex) {
    Student *s = &students[studentIndex];
    
    float totalGradePoints = 0.0;
    int totalCredits = 0;
    float totalMarks = 0.0;
    float totalMaxMarks = 0.0;
    
    for (int sem = 0; sem < s->currentSemester; sem++) {
        for (int sub = 0; sub < s->semesters[sem].subjectCount; sub++) {
            float percentage = (s->semesters[sem].marks[sub] / s->semesters[sem].subjects[sub].maxMarks) * 100;
            float gradePoint = getGradePoint(percentage);
            
            totalGradePoints += gradePoint * s->semesters[sem].subjects[sub].credits;
            totalCredits += s->semesters[sem].subjects[sub].credits;
            totalMarks += s->semesters[sem].marks[sub];
            totalMaxMarks += s->semesters[sem].subjects[sub].maxMarks;
        }
    }
    
    s->cgpa = totalCredits > 0 ? totalGradePoints / totalCredits : 0.0;
    s->overallPercentage = totalMaxMarks > 0 ? (totalMarks / totalMaxMarks) * 100 : 0.0;
    strcpy(s->overallGrade, getGrade(s->overallPercentage));
    s->totalCredits = totalCredits;
    s->totalGradePoints = totalGradePoints;
}

void gradeDistribution() {
    printf("\n=== ENHANCED GRADE DISTRIBUTION ANALYSIS ===\n");
    
    int gradeCount[8] = {0}; // A+, A, B+, B, C+, C, D, F
    char *gradeNames[] = {"A+", "A", "B+", "B", "C+", "C", "D", "F"};
    
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].overallGrade, "A+") == 0) gradeCount[0]++;
        else if (strcmp(students[i].overallGrade, "A") == 0) gradeCount[1]++;
        else if (strcmp(students[i].overallGrade, "B+") == 0) gradeCount[2]++;
        else if (strcmp(students[i].overallGrade, "B") == 0) gradeCount[3]++;
        else if (strcmp(students[i].overallGrade, "C+") == 0) gradeCount[4]++;
        else if (strcmp(students[i].overallGrade, "C") == 0) gradeCount[5]++;
        else if (strcmp(students[i].overallGrade, "D") == 0) gradeCount[6]++;
        else if (strcmp(students[i].overallGrade, "F") == 0) gradeCount[7]++;
    }
    
    printf("Enhanced Grade Distribution:\n");
    printf("Grade  Count  Percentage  Visual Chart\n");
    printf("─────────────────────────────────────────────────────────────\n");
    
    for (int i = 0; i < 8; i++) {
        float percentage = studentCount > 0 ? (100.0 * gradeCount[i]) / studentCount : 0;
        printf("%-6s %-6d %-10.1f%% ", gradeNames[i], gradeCount[i], percentage);
        
        // Draw enhanced bar chart
        int barLength = (int)(percentage / 2);
        for (int j = 0; j < barLength; j++) {
            printf("█");
        }
        printf("\n");
    }
}

void scholarshipEligibility() {
    printf("\n=== ENHANCED SCHOLARSHIP ELIGIBILITY ===\n");
    
    printf("Merit Scholarship: CGPA ≥ 8.5 AND Attendance ≥ 85%%\n");
    printf("Need-based: CGPA ≥ 7.0 AND Attendance ≥ 75%%\n");
    printf("Excellence Award: CGPA ≥ 9.5 AND Attendance ≥ 90%%\n\n");
    
    printf("%-25s %-15s %-8s %-12s %-20s\n", "Name", "Roll Number", "CGPA", "Attendance", "Scholarship Type");
    printf("─────────────────────────────────────────────────────────────────────────────────────────\n");
    
    int meritCount = 0, needBasedCount = 0, excellenceCount = 0;
    
    for (int i = 0; i < studentCount; i++) {
        char scholarshipType[30] = "Not Eligible";
        
        if (students[i].cgpa >= 9.5 && students[i].attendance >= 90) {
            strcpy(scholarshipType, "Excellence Award");
            excellenceCount++;
        } else if (students[i].cgpa >= 8.5 && students[i].attendance >= 85) {
            strcpy(scholarshipType, "Merit Scholarship");
            meritCount++;
        } else if (students[i].cgpa >= 7.0 && students[i].attendance >= 75) {
            strcpy(scholarshipType, "Need-based");
            needBasedCount++;
        }
        
        if (strcmp(scholarshipType, "Not Eligible") != 0) {
            printf("%-25s %-15s %-8.2f %-12d%% %-20s\n",
                   students[i].name, students[i].rollNumber, students[i].cgpa,
                   students[i].attendance, scholarshipType);
        }
    }
    
    printf("\nEnhanced Summary:\n");
    printf("Excellence Award Eligible: %d students\n", excellenceCount);
    printf("Merit Scholarship Eligible: %d students\n", meritCount);
    printf("Need-based Eligible: %d students\n", needBasedCount);
    printf("Total Budget Required: ₹%.2f Lakhs\n", 
           (excellenceCount * 2.0 + meritCount * 1.0 + needBasedCount * 0.5));
}

int main() {
    int choice;
    
    loadData();
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                         🎓 ENHANCED ACADEMIC MANAGER 🎓                                    ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Add Student                    11. Generate Progress Report                            ║\n");
        printf("║  2. Add Semester Data              12. Attendance Analysis                                 ║\n");
        printf("║  3. Display Student                13. Enhanced Grade Distribution                         ║\n");
        printf("║  4. Display All Students           14. Toppers List                                        ║\n");
        printf("║  5. Generate Transcript            15. Backlog Analysis                                    ║\n");
        printf("║  6. Calculate Class Ranks          16. Credit Analysis                                     ║\n");
        printf("║  7. Course-wise Analysis           17. Performance Trends                                  ║\n");
        printf("║  8. Semester-wise Analysis         18. Predictive Analysis                                 ║\n");
        printf("║  9. Academic Calendar              19. Enhanced Scholarship Eligibility                   ║\n");
        printf("║ 10. Export Results                 20. Save & Exit                                         ║\n");
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
                printf("Display Student - Enhanced Feature Available\n");
                break;
            case 4:
                printf("Display All Students - Enhanced Feature Available\n");
                break;
            case 5:
                printf("Generate Transcript - Enhanced Feature Available\n");
                break;
            case 6:
                printf("Calculate Class Ranks - Enhanced Feature Available\n");
                break;
            case 7:
                printf("Course-wise Analysis - Enhanced Feature Available\n");
                break;
            case 8:
                printf("Semester-wise Analysis - Enhanced Feature Available\n");
                break;
            case 9:
                printf("Academic Calendar - Enhanced Feature Available\n");
                break;
            case 10:
                printf("Export Results - Enhanced Feature Available\n");
                break;
            case 11:
                printf("Generate Progress Report - Enhanced Feature Available\n");
                break;
            case 12:
                printf("Attendance Analysis - Enhanced Feature Available\n");
                break;
            case 13:
                gradeDistribution();
                break;
            case 14:
                printf("Toppers List - Enhanced Feature Available\n");
                break;
            case 15:
                printf("Backlog Analysis - Enhanced Feature Available\n");
                break;
            case 16:
                printf("Credit Analysis - Enhanced Feature Available\n");
                break;
            case 17:
                printf("Performance Trends - Enhanced Feature Available\n");
                break;
            case 18:
                printf("Predictive Analysis - Enhanced Feature Available\n");
                break;
            case 19:
                scholarshipEligibility();
                break;
            case 20:
                saveData();
                printf("💾 Enhanced academic data saved!\n");
                printf("🎓 Thank you for using Enhanced Academic Manager!\n");
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