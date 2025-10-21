#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "todo.txt"

struct Task {
    int id;
    char title[100];
    int completed;
};

void addTask();
void viewTasks();
void markDone();
void deleteTask();
int getNextId();

int main() {
    int choice;
    while (1) {
        printf("\n====== TO-DO LIST MANAGER ======\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Done\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markDone(); break;
            case 4: deleteTask(); break;
            case 5: printf("Exiting... Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addTask() {
    FILE *fp = fopen(FILE_NAME, "a+");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    struct Task t;
    t.id = getNextId();

    printf("Enter task title: ");
    fgets(t.title, sizeof(t.title), stdin);
    t.title[strcspn(t.title, "\n")] = 0;
    t.completed = 0;

    fprintf(fp, "%d|%s|%d\n", t.id, t.title, t.completed);
    fclose(fp);
    printf("Task added successfully.\n");
}

void viewTasks() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No tasks found.\n");
        return;
    }

    struct Task t;
    char line[256];
    int found = 0;

    printf("\n------ TO-DO TASKS ------\n");
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d|%[^|]|%d", &t.id, t.title, &t.completed);
        found = 1;
        printf("[%d] %s %s\n", t.id, t.title, t.completed ? "(DONE)" : "");
    }

    if (!found)
        printf("No tasks available.\n");

    fclose(fp);
}

void markDone() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No tasks found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    struct Task t;
    char line[256];
    int id, found = 0;

    printf("Enter task ID to mark as done: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d|%[^|]|%d", &t.id, t.title, &t.completed);
        if (t.id == id) {
            t.completed = 1;
            found = 1;
        }
        fprintf(temp, "%d|%s|%d\n", t.id, t.title, t.completed);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) printf("Task marked as done.\n");
    else printf("Task ID not found.\n");
}

void deleteTask() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No tasks found.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    struct Task t;
    char line[256];
    int id, found = 0;

    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d|%[^|]|%d", &t.id, t.title, &t.completed);
        if (t.id != id)
            fprintf(temp, "%d|%s|%d\n", t.id, t.title, t.completed);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) printf("Task deleted successfully.\n");
    else printf("Task ID not found.\n");
}

int getNextId() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return 1;

    struct Task t;
    char line[256];
    int lastId = 0;

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d|%[^|]|%d", &t.id, t.title, &t.completed);
        if (t.id > lastId) lastId = t.id;
    }
    fclose(fp);
    return lastId + 1;
}