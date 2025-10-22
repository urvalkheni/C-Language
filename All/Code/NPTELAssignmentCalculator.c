#include <stdio.h>

// Function to sort marks in descending order
void sortDescending(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int weeks, bestCount;
    printf("Enter number of weeks (4, 8, or 12): ");
    scanf("%d", &weeks);

    if (weeks != 4 && weeks != 8 && weeks != 12) {
        printf("Invalid input! Please enter 4, 8, or 12.\n");
        return 0;
    }

    float marks[12];
    printf("Enter assignment marks for each week (out of 100):\n");
    for (int i = 0; i < weeks; i++) {
        printf("Week %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Decide best week count
    if (weeks == 4)
        bestCount = 3;
    else if (weeks == 8)
        bestCount = 6;
    else
        bestCount = 8;

    // Sort marks in descending order
    sortDescending(marks, weeks);

    // Calculate average of best weeks
    float sum = 0;
    for (int i = 0; i < bestCount; i++)
        sum += marks[i];
    float average = sum / bestCount;

    // Calculate marks out of 25
    float marksOutOf25 = (average / 100) * 25;

    printf("\n------------------------------\n");
    printf("Average of Best %d Assignments: %.2f\n", bestCount, average);
    printf("Assignment Marks (Out of 25): %.2f\n", marksOutOf25);
    printf("------------------------------\n");

    return 0;
}