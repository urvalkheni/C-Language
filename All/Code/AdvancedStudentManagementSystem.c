#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTS 1000
#define MAX_SUBJECTS 10
#define MAX_NAME_LEN 100
#define DATA_FILE "students_data.dat"
#define BACKUP_FILE "students_backup.dat"

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[50];
    float marks;
    int credits;
} Subject;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    char phone[15];
    char address[200];
    Date birthDate;
    Date admissionDate;
    char course[50];
    int semester;
    Subject subjects[MAX_SUBJECTS];
    int subjectCount;
    float cgpa;
    int attendance;
    char status[20]; // Active, Graduated, Suspended
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void loadData();
void saveData();
void createBackup();
void addStudent();
void displayAllStudents();
void searchStudents();
void updateStudent();
void deleteStudent();
void calculateGrades();
void generateReports();
void attendanceManagement();
void exportData();
void importData();
void advancedSearch();
void studentStatistics();
int validateEmail(char *email);
int validatePhone(char *phone);
void clearScreen();

void clearScreen() {
    system("cls");
}

int validateEmail(char *email) {
    int atCount = 0, dotCount = 0;
    int len = strlen(email);
    
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') atCount++;
        if (email[i] == '.') dotCount++;
    }
    
    return (atCount == 1 && dotCount >= 1 && len > 5);
}

int validatePhone(char *phone) {
    int len = strlen(phone);
    if (len != 10) return 0;
    
    for (int i = 0; i < len; i++) {
        if (phone[i] < '0' || phone[i] > '9') return 0;
    }
    return 1;
}

void loadData() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        fread(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("Data loaded successfully! %d students found.\n", studentCount);
    } else {
        printf("No previous data found. Starting fresh.\n");
        studentCount = 0;
    }
}

void saveData() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file) {
        fwrite(&studentCount, sizeof(int), 1, file);
        fwrite(students, sizeof(Student), studentCount, file);
        fclose(file);
        printf("Data saved successfully!\n");
    } else {
        printf("Error saving data!\n");
    }
}

void createBackup() {
    FILE *source = fopen(DATA_FILE, "rb");
    FILE *backup = fopen(BACKUP_FILE, "wb");
    
    if (source && backup) {
        char buffer[1024];
        size_t bytes;
        
        while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
            fwrite(buffer, 1, bytes, backup);
        }
        
        fclose(source);
        fclose(backup);
        printf("Backup created successfully!\n");
    } else {
        printf("Error creating backup!\n");
    }
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    Student *s = &students[studentCount];
    
    printf("\n=== ADD NEW STUDENT ===\n");
    printf("Enter Student ID: ");
    scanf("%d", &s->id);
    
    // Check for duplicate ID
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == s->id) {
            printf("Student ID already exists!\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);
    
    do {
        printf("Enter Email: ");
        scanf(" %[^\n]", s->email);
        if (!validateEmail(s->email)) {
            printf("Invalid email format! Please try again.\n");
        }
    } while (!validateEmail(s->email));
    
    do {
        printf("Enter Phone (10 digits): ");
        scanf(" %[^\n]", s->phone);
        if (!validatePhone(s->phone)) {
            printf("Invalid phone number! Please enter 10 digits.\n");
        }
    } while (!validatePhone(s->phone));
    
    printf("Enter Address: ");
    scanf(" %[^\n]", s->address);
    
    printf("Enter Birth Date (DD MM YYYY): ");
    scanf("%d %d %d", &s->birthDate.day, &s->birthDate.month, &s->birthDate.year);
    
    printf("Enter Admission Date (DD MM YYYY): ");
    scanf("%d %d %d", &s->admissionDate.day, &s->admissionDate.month, &s->admissionDate.year);
    
    printf("Enter Course: ");
    scanf(" %[^\n]", s->course);
    
    printf("Enter Semester: ");
    scanf("%d", &s->semester);
    
    printf("Enter number of subjects: ");
    scanf("%d", &s->subjectCount);
    
    float totalMarks = 0, totalCredits = 0;
    for (int i = 0; i < s->subjectCount; i++) {
        printf("Subject %d Name: ", i + 1);
        scanf(" %[^\n]", s->subjects[i].name);
        printf("Subject %d Marks: ", i + 1);
        scanf("%f", &s->subjects[i].marks);
        printf("Subject %d Credits: ", i + 1);
        scanf("%d", &s->subjects[i].credits);
        
        totalMarks += s->subjects[i].marks * s->subjects[i].credits;
        totalCredits += s->subjects[i].credits;
    }
    
    s->cgpa = totalCredits > 0 ? totalMarks / (totalCredits * 10) : 0;
    
    printf("Enter Attendance percentage: ");
    scanf("%d", &s->attendance);
    
    strcpy(s->status, "Active");
    
    studentCount++;
    printf("Student added successfully!\n");
    saveData();
}

void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students to display!\n");
        return;
    }
    
    printf("\n=== ALL STUDENTS ===\n");
    printf("%-5s %-20s %-25s %-12s %-10s %-8s %-10s %-10s\n", 
           "ID", "Name", "Email", "Phone", "Course", "Sem", "CGPA", "Status");
    printf("-------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-5d %-20s %-25s %-12s %-10s %-8d %-10.2f %-10s\n",
               students[i].id, students[i].name, students[i].email,
               students[i].phone, students[i].course, students[i].semester,
               students[i].cgpa, students[i].status);
    }
}

void searchStudents() {
    int choice, id, found = 0;
    char searchTerm[100];
    
    printf("\n=== SEARCH STUDENTS ===\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Course\n");
    printf("4. Search by Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            for (int i = 0; i < studentCount; i++) {
                if (students[i].id == id) {
                    printf("\nStudent Found:\n");
                    printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\n",
                           students[i].id, students[i].name, students[i].email, students[i].phone);
                    printf("Course: %s\nSemester: %d\nCGPA: %.2f\nStatus: %s\n",
                           students[i].course, students[i].semester, students[i].cgpa, students[i].status);
                    found = 1;
                    break;
                }
            }
            break;
        case 2:
        case 3:
        case 4:
            printf("Enter search term: ");
            scanf(" %[^\n]", searchTerm);
            
            for (int i = 0; i < studentCount; i++) {
                int match = 0;
                switch (choice) {
                    case 2: match = strstr(students[i].name, searchTerm) != NULL; break;
                    case 3: match = strstr(students[i].course, searchTerm) != NULL; break;
                    case 4: match = strstr(students[i].email, searchTerm) != NULL; break;
                }
                
                if (match) {
                    printf("ID: %d, Name: %s, Course: %s, CGPA: %.2f\n",
                           students[i].id, students[i].name, students[i].course, students[i].cgpa);
                    found = 1;
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    if (!found) {
        printf("No students found!\n");
    }
}

void updateStudent() {
    int id, found = -1;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Student not found!\n");
        return;
    }
    
    Student *s = &students[found];
    int choice;
    
    printf("\n=== UPDATE STUDENT ===\n");
    printf("1. Update Name\n2. Update Email\n3. Update Phone\n");
    printf("4. Update Address\n5. Update Course\n6. Update Semester\n");
    printf("7. Update Status\n8. Update Attendance\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", s->name);
            break;
        case 2:
            do {
                printf("Enter new email: ");
                scanf(" %[^\n]", s->email);
                if (!validateEmail(s->email)) {
                    printf("Invalid email format!\n");
                }
            } while (!validateEmail(s->email));
            break;
        case 3:
            do {
                printf("Enter new phone: ");
                scanf(" %[^\n]", s->phone);
                if (!validatePhone(s->phone)) {
                    printf("Invalid phone number!\n");
                }
            } while (!validatePhone(s->phone));
            break;
        case 4:
            printf("Enter new address: ");
            scanf(" %[^\n]", s->address);
            break;
        case 5:
            printf("Enter new course: ");
            scanf(" %[^\n]", s->course);
            break;
        case 6:
            printf("Enter new semester: ");
            scanf("%d", &s->semester);
            break;
        case 7:
            printf("Enter new status (Active/Graduated/Suspended): ");
            scanf(" %[^\n]", s->status);
            break;
        case 8:
            printf("Enter new attendance percentage: ");
            scanf("%d", &s->attendance);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    printf("Student updated successfully!\n");
    saveData();
}

void generateReports() {
    if (studentCount == 0) {
        printf("No students to generate reports!\n");
        return;
    }
    
    int choice;
    printf("\n=== GENERATE REPORTS ===\n");
    printf("1. High Achievers (CGPA > 8.0)\n");
    printf("2. Low Attendance Students (< 75%%)\n");
    printf("3. Course-wise Distribution\n");
    printf("4. Semester-wise Statistics\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nHigh Achievers (CGPA > 8.0):\n");
            for (int i = 0; i < studentCount; i++) {
                if (students[i].cgpa > 8.0) {
                    printf("ID: %d, Name: %s, CGPA: %.2f\n",
                           students[i].id, students[i].name, students[i].cgpa);
                }
            }
            break;
        case 2:
            printf("\nLow Attendance Students (< 75%%):\n");
            for (int i = 0; i < studentCount; i++) {
                if (students[i].attendance < 75) {
                    printf("ID: %d, Name: %s, Attendance: %d%%\n",
                           students[i].id, students[i].name, students[i].attendance);
                }
            }
            break;
        case 3:
            printf("\nCourse-wise Distribution:\n");
            // Simple course counting
            for (int i = 0; i < studentCount; i++) {
                int count = 1;
                for (int j = i + 1; j < studentCount; j++) {
                    if (strcmp(students[i].course, students[j].course) == 0) {
                        count++;
                    }
                }
                if (count > 0) {
                    printf("Course: %s, Students: %d\n", students[i].course, count);
                }
            }
            break;
        case 4:
            printf("\nSemester-wise Statistics:\n");
            for (int sem = 1; sem <= 8; sem++) {
                int count = 0;
                float totalCGPA = 0;
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].semester == sem) {
                        count++;
                        totalCGPA += students[i].cgpa;
                    }
                }
                if (count > 0) {
                    printf("Semester %d: %d students, Average CGPA: %.2f\n",
                           sem, count, totalCGPA / count);
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int choice;
    
    // Load existing data
    loadData();
    
    while (1) {
        printf("\n======= ADVANCED STUDENT MANAGEMENT SYSTEM =======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Students\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Generate Reports\n");
        printf("7. Create Backup\n");
        printf("8. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudents();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                // deleteStudent(); // Implementation left for brevity
                printf("Delete function - Implementation pending\n");
                break;
            case 6:
                generateReports();
                break;
            case 7:
                createBackup();
                break;
            case 8:
                saveData();
                printf("Data saved. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}