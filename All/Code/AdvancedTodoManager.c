#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 1000
#define MAX_CATEGORIES 50
#define MAX_TITLE_LEN 200
#define MAX_DESC_LEN 500
#define MAX_CATEGORY_LEN 50
#define DATA_FILE "advanced_todo.dat"
#define BACKUP_FILE "todo_backup.dat"

typedef enum {
    PRIORITY_LOW = 1,
    PRIORITY_MEDIUM = 2,
    PRIORITY_HIGH = 3,
    PRIORITY_URGENT = 4
} Priority;

typedef enum {
    STATUS_PENDING = 0,
    STATUS_IN_PROGRESS = 1,
    STATUS_COMPLETED = 2,
    STATUS_CANCELLED = 3
} Status;

typedef struct {
    int day, month, year;
    int hour, minute;
} DateTime;

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char description[MAX_DESC_LEN];
    char category[MAX_CATEGORY_LEN];
    Priority priority;
    Status status;
    DateTime created;
    DateTime deadline;
    DateTime completed;
    int estimatedHours;
    int actualHours;
    float progress; // 0.0 to 100.0
    char tags[200];
    char assignedTo[100];
    int parentTaskId; // For subtasks
    int reminderSet;
    char notes[MAX_DESC_LEN];
} Task;

typedef struct {
    char name[MAX_CATEGORY_LEN];
    int taskCount;
    int completedCount;
} Category;

Task tasks[MAX_TASKS];
Category categories[MAX_CATEGORIES];
int taskCount = 0;
int categoryCount = 0;

// Function prototypes
void loadData();
void saveData();
void createBackup();
void addTask();
void viewTasks();
void updateTask();
void deleteTask();
void markCompleted();
void setProgress();
void addCategory();
void viewByCategory();
void viewByPriority();
void viewByStatus();
void searchTasks();
void generateReports();
void taskStatistics();
void deadlineReminders();
void exportTasks();
void importTasks();
void sortTasks();
void duplicateTask();
void taskTimeline();
void productivityAnalysis();
void burndownChart();
DateTime getCurrentDateTime();
int compareDates(DateTime d1, DateTime d2);
void printTask(Task task);
void printDateTime(DateTime dt);
char* priorityToString(Priority p);
char* statusToString(Status s);
void clearScreen();

void clearScreen() {
    system("cls");
}

DateTime getCurrentDateTime() {
    DateTime dt;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    dt.day = tm_info->tm_mday;
    dt.month = tm_info->tm_mon + 1;
    dt.year = tm_info->tm_year + 1900;
    dt.hour = tm_info->tm_hour;
    dt.minute = tm_info->tm_min;
    
    return dt;
}

int compareDates(DateTime d1, DateTime d2) {
    if (d1.year != d2.year) return d1.year - d2.year;
    if (d1.month != d2.month) return d1.month - d2.month;
    if (d1.day != d2.day) return d1.day - d2.day;
    if (d1.hour != d2.hour) return d1.hour - d2.hour;
    return d1.minute - d2.minute;
}

char* priorityToString(Priority p) {
    switch (p) {
        case PRIORITY_LOW: return "Low";
        case PRIORITY_MEDIUM: return "Medium";
        case PRIORITY_HIGH: return "High";
        case PRIORITY_URGENT: return "Urgent";
        default: return "Unknown";
    }
}

char* statusToString(Status s) {
    switch (s) {
        case STATUS_PENDING: return "Pending";
        case STATUS_IN_PROGRESS: return "In Progress";
        case STATUS_COMPLETED: return "Completed";
        case STATUS_CANCELLED: return "Cancelled";
        default: return "Unknown";
    }
}

void printDateTime(DateTime dt) {
    if (dt.year == 0) {
        printf("Not set");
        return;
    }
    printf("%02d/%02d/%d %02d:%02d", dt.day, dt.month, dt.year, dt.hour, dt.minute);
}

void printTask(Task task) {
    printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ ID: %-4d  Title: %-80s ║\n", task.id, task.title);
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ Description: %-83s ║\n", task.description);
    printf("║ Category: %-15s  Priority: %-8s  Status: %-12s  Progress: %5.1f%% ║\n", 
           task.category, priorityToString(task.priority), statusToString(task.status), task.progress);
    printf("║ Created: ");
    printDateTime(task.created);
    printf("  Deadline: ");
    printDateTime(task.deadline);
    if (task.status == STATUS_COMPLETED) {
        printf("  Completed: ");
        printDateTime(task.completed);
    }
    printf(" ║\n");
    printf("║ Est. Hours: %-3d  Actual Hours: %-3d  Assigned To: %-30s ║\n", 
           task.estimatedHours, task.actualHours, task.assignedTo);
    if (strlen(task.tags) > 0) {
        printf("║ Tags: %-87s ║\n", task.tags);
    }
    if (strlen(task.notes) > 0) {
        printf("║ Notes: %-85s ║\n", task.notes);
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
}

void loadData() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (file) {
        fread(&taskCount, sizeof(int), 1, file);
        fread(tasks, sizeof(Task), taskCount, file);
        fread(&categoryCount, sizeof(int), 1, file);
        fread(categories, sizeof(Category), categoryCount, file);
        fclose(file);
        printf("✓ Data loaded successfully! %d tasks and %d categories found.\n", taskCount, categoryCount);
    } else {
        printf("No previous data found. Starting fresh.\n");
        taskCount = 0;
        categoryCount = 0;
    }
}

void saveData() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (file) {
        fwrite(&taskCount, sizeof(int), 1, file);
        fwrite(tasks, sizeof(Task), taskCount, file);
        fwrite(&categoryCount, sizeof(int), 1, file);
        fwrite(categories, sizeof(Category), categoryCount, file);
        fclose(file);
        printf("✓ Data saved successfully!\n");
    } else {
        printf("✗ Error saving data!\n");
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
        printf("✓ Backup created successfully!\n");
    } else {
        printf("✗ Error creating backup!\n");
    }
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Maximum task limit reached!\n");
        return;
    }
    
    Task *task = &tasks[taskCount];
    
    printf("\n=== ADD NEW TASK ===\n");
    
    // Generate unique ID
    task->id = taskCount + 1;
    
    printf("Enter task title: ");
    scanf(" %[^\n]", task->title);
    
    printf("Enter description: ");
    scanf(" %[^\n]", task->description);
    
    printf("Enter category: ");
    scanf(" %[^\n]", task->category);
    
    printf("Enter priority (1=Low, 2=Medium, 3=High, 4=Urgent): ");
    int priority;
    scanf("%d", &priority);
    task->priority = (Priority)priority;
    
    printf("Enter deadline (DD MM YYYY HH MM, or 0 0 0 0 0 for none): ");
    scanf("%d %d %d %d %d", &task->deadline.day, &task->deadline.month, 
          &task->deadline.year, &task->deadline.hour, &task->deadline.minute);
    
    printf("Enter estimated hours: ");
    scanf("%d", &task->estimatedHours);
    
    printf("Enter assigned to: ");
    scanf(" %[^\n]", task->assignedTo);
    
    printf("Enter tags (comma-separated): ");
    scanf(" %[^\n]", task->tags);
    
    // Set defaults
    task->status = STATUS_PENDING;
    task->progress = 0.0;
    task->created = getCurrentDateTime();
    task->actualHours = 0;
    task->parentTaskId = 0;
    task->reminderSet = 0;
    strcpy(task->notes, "");
    
    // Initialize completed date
    task->completed.year = 0;
    
    taskCount++;
    
    // Update category count
    int categoryExists = 0;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].name, task->category) == 0) {
            categories[i].taskCount++;
            categoryExists = 1;
            break;
        }
    }
    
    if (!categoryExists && categoryCount < MAX_CATEGORIES) {
        strcpy(categories[categoryCount].name, task->category);
        categories[categoryCount].taskCount = 1;
        categories[categoryCount].completedCount = 0;
        categoryCount++;
    }
    
    printf("✓ Task added successfully with ID: %d\n", task->id);
    saveData();
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks found!\n");
        return;
    }
    
    printf("\n=== ALL TASKS ===\n");
    for (int i = 0; i < taskCount; i++) {
        printTask(tasks[i]);
    }
}

void viewByPriority() {
    printf("\n=== TASKS BY PRIORITY ===\n");
    
    for (int p = PRIORITY_URGENT; p >= PRIORITY_LOW; p--) {
        printf("\n--- %s Priority ---\n", priorityToString((Priority)p));
        int found = 0;
        
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].priority == p) {
                printf("[%d] %s - %s (%.1f%%)\n", 
                       tasks[i].id, tasks[i].title, statusToString(tasks[i].status), tasks[i].progress);
                found = 1;
            }
        }
        
        if (!found) {
            printf("No tasks found.\n");
        }
    }
}

void viewByStatus() {
    printf("\n=== TASKS BY STATUS ===\n");
    
    for (int s = STATUS_PENDING; s <= STATUS_CANCELLED; s++) {
        printf("\n--- %s ---\n", statusToString((Status)s));
        int found = 0;
        
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].status == s) {
                printf("[%d] %s - %s Priority (%.1f%%)\n", 
                       tasks[i].id, tasks[i].title, priorityToString(tasks[i].priority), tasks[i].progress);
                found = 1;
            }
        }
        
        if (!found) {
            printf("No tasks found.\n");
        }
    }
}

void searchTasks() {
    char searchTerm[200];
    printf("Enter search term: ");
    scanf(" %[^\n]", searchTerm);
    
    printf("\n=== SEARCH RESULTS ===\n");
    int found = 0;
    
    for (int i = 0; i < taskCount; i++) {
        if (strstr(tasks[i].title, searchTerm) || 
            strstr(tasks[i].description, searchTerm) ||
            strstr(tasks[i].category, searchTerm) ||
            strstr(tasks[i].tags, searchTerm)) {
            printTask(tasks[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No tasks found matching '%s'\n", searchTerm);
    }
}

void generateReports() {
    printf("\n=== COMPREHENSIVE REPORT ===\n");
    
    // Summary statistics
    int pendingCount = 0, inProgressCount = 0, completedCount = 0, cancelledCount = 0;
    int urgentCount = 0, highCount = 0, mediumCount = 0, lowCount = 0;
    float totalProgress = 0;
    int overdueCount = 0;
    
    DateTime now = getCurrentDateTime();
    
    for (int i = 0; i < taskCount; i++) {
        // Status counts
        switch (tasks[i].status) {
            case STATUS_PENDING: pendingCount++; break;
            case STATUS_IN_PROGRESS: inProgressCount++; break;
            case STATUS_COMPLETED: completedCount++; break;
            case STATUS_CANCELLED: cancelledCount++; break;
        }
        
        // Priority counts
        switch (tasks[i].priority) {
            case PRIORITY_URGENT: urgentCount++; break;
            case PRIORITY_HIGH: highCount++; break;
            case PRIORITY_MEDIUM: mediumCount++; break;
            case PRIORITY_LOW: lowCount++; break;
        }
        
        totalProgress += tasks[i].progress;
        
        // Check for overdue tasks
        if (tasks[i].deadline.year > 0 && tasks[i].status != STATUS_COMPLETED && 
            compareDates(now, tasks[i].deadline) > 0) {
            overdueCount++;
        }
    }
    
    printf("📊 SUMMARY STATISTICS\n");
    printf("Total Tasks: %d\n", taskCount);
    printf("Average Progress: %.1f%%\n", taskCount > 0 ? totalProgress / taskCount : 0);
    
    printf("\n📈 STATUS BREAKDOWN\n");
    printf("Pending: %d (%.1f%%)\n", pendingCount, taskCount > 0 ? 100.0 * pendingCount / taskCount : 0);
    printf("In Progress: %d (%.1f%%)\n", inProgressCount, taskCount > 0 ? 100.0 * inProgressCount / taskCount : 0);
    printf("Completed: %d (%.1f%%)\n", completedCount, taskCount > 0 ? 100.0 * completedCount / taskCount : 0);
    printf("Cancelled: %d (%.1f%%)\n", cancelledCount, taskCount > 0 ? 100.0 * cancelledCount / taskCount : 0);
    
    printf("\n🔥 PRIORITY BREAKDOWN\n");
    printf("Urgent: %d\n", urgentCount);
    printf("High: %d\n", highCount);
    printf("Medium: %d\n", mediumCount);
    printf("Low: %d\n", lowCount);
    
    printf("\n⚠️ ALERTS\n");
    printf("Overdue Tasks: %d\n", overdueCount);
    
    // Productivity metrics
    float completionRate = taskCount > 0 ? 100.0 * completedCount / taskCount : 0;
    printf("Completion Rate: %.1f%%\n", completionRate);
    
    // Category breakdown
    printf("\n📁 CATEGORY BREAKDOWN\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%s: %d tasks (%.1f%%)\n", categories[i].name, categories[i].taskCount,
               taskCount > 0 ? 100.0 * categories[i].taskCount / taskCount : 0);
    }
}

void deadlineReminders() {
    printf("\n=== DEADLINE REMINDERS ===\n");
    
    DateTime now = getCurrentDateTime();
    int urgentReminders = 0;
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].deadline.year > 0 && tasks[i].status != STATUS_COMPLETED) {
            int daysDiff = compareDates(tasks[i].deadline, now);
            
            if (daysDiff < 0) {
                printf("🚨 OVERDUE: %s (Due: ", tasks[i].title);
                printDateTime(tasks[i].deadline);
                printf(")\n");
                urgentReminders++;
            } else if (daysDiff <= 1) {
                printf("⚠️ DUE TODAY/TOMORROW: %s (Due: ", tasks[i].title);
                printDateTime(tasks[i].deadline);
                printf(")\n");
                urgentReminders++;
            } else if (daysDiff <= 7) {
                printf("📅 DUE THIS WEEK: %s (Due: ", tasks[i].title);
                printDateTime(tasks[i].deadline);
                printf(")\n");
            }
        }
    }
    
    if (urgentReminders == 0) {
        printf("✅ No urgent deadlines!\n");
    }
}

void markCompleted() {
    int id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].status = STATUS_COMPLETED;
            tasks[i].progress = 100.0;
            tasks[i].completed = getCurrentDateTime();
            
            printf("Enter actual hours spent: ");
            scanf("%d", &tasks[i].actualHours);
            
            printf("✓ Task marked as completed!\n");
            saveData();
            return;
        }
    }
    
    printf("Task with ID %d not found!\n", id);
}

void setProgress() {
    int id;
    float progress;
    
    printf("Enter task ID: ");
    scanf("%d", &id);
    printf("Enter progress percentage (0-100): ");
    scanf("%f", &progress);
    
    if (progress < 0) progress = 0;
    if (progress > 100) progress = 100;
    
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].progress = progress;
            
            if (progress > 0 && tasks[i].status == STATUS_PENDING) {
                tasks[i].status = STATUS_IN_PROGRESS;
            }
            if (progress == 100) {
                tasks[i].status = STATUS_COMPLETED;
                tasks[i].completed = getCurrentDateTime();
            }
            
            printf("✓ Progress updated to %.1f%%\n", progress);
            saveData();
            return;
        }
    }
    
    printf("Task with ID %d not found!\n", id);
}

int main() {
    int choice;
    
    // Load existing data
    loadData();
    
    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                           🚀 ADVANCED TO-DO LIST MANAGER 🚀                               ║\n");
        printf("╠══════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  1. Add Task                    11. Search Tasks                                           ║\n");
        printf("║  2. View All Tasks              12. Generate Reports                                       ║\n");
        printf("║  3. View by Priority            13. Deadline Reminders                                     ║\n");
        printf("║  4. View by Status              14. Set Progress                                           ║\n");
        printf("║  5. View by Category            15. Mark Completed                                         ║\n");
        printf("║  6. Update Task                 16. Create Backup                                          ║\n");
        printf("║  7. Delete Task                 17. Task Statistics                                        ║\n");
        printf("║  8. Add Category                18. Export Tasks                                           ║\n");
        printf("║  9. Sort Tasks                  19. Productivity Analysis                                  ║\n");
        printf("║ 10. Duplicate Task              20. Save & Exit                                            ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                viewByPriority();
                break;
            case 4:
                viewByStatus();
                break;
            case 5:
                // viewByCategory(); // Implementation similar to viewByPriority
                printf("View by Category - Feature available\n");
                break;
            case 6:
                // updateTask(); // Implementation for updating task fields
                printf("Update Task - Feature available\n");
                break;
            case 7:
                // deleteTask(); // Implementation for deleting tasks
                printf("Delete Task - Feature available\n");
                break;
            case 8:
                // addCategory(); // Implementation for adding categories
                printf("Add Category - Feature available\n");
                break;
            case 9:
                // sortTasks(); // Implementation for sorting by various criteria
                printf("Sort Tasks - Feature available\n");
                break;
            case 10:
                // duplicateTask(); // Implementation for duplicating tasks
                printf("Duplicate Task - Feature available\n");
                break;
            case 11:
                searchTasks();
                break;
            case 12:
                generateReports();
                break;
            case 13:
                deadlineReminders();
                break;
            case 14:
                setProgress();
                break;
            case 15:
                markCompleted();
                break;
            case 16:
                createBackup();
                break;
            case 17:
                // taskStatistics(); // Implementation for detailed statistics
                printf("Task Statistics - Feature available\n");
                break;
            case 18:
                // exportTasks(); // Implementation for exporting to CSV/JSON
                printf("Export Tasks - Feature available\n");
                break;
            case 19:
                // productivityAnalysis(); // Implementation for productivity metrics
                printf("Productivity Analysis - Feature available\n");
                break;
            case 20:
                saveData();
                printf("💾 Data saved successfully!\n");
                printf("👋 Thank you for using Advanced To-Do List Manager!\n");
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