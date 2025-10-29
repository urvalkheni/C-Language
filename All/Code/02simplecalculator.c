// Enhanced Scientific Calculator with History and Advanced Operations
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define MAX_HISTORY 50
#define PI 3.14159265358979323846

// Structure to store calculation history
typedef struct {
    char operation[100];
    double result;
    time_t timestamp;
} CalculationHistory;

// Global variables
CalculationHistory history[MAX_HISTORY];
int historyCount = 0;
double memory = 0.0;
double lastResult = 0.0;

// Function prototypes
void displayMenu();
void basicOperations();
void scientificOperations();
void unitConversions();
void memoryOperations();
void showHistory();
void clearHistory();
void addToHistory(const char* operation, double result);
double factorial(int n);
double power(double base, double exp);
double degreeToRadian(double degree);
double radianToDegree(double radian);
void clearInputBuffer();

int main() {
    int choice;
    printf("===============================================\n");
    printf("    ENHANCED SCIENTIFIC CALCULATOR v2.0\n");
    printf("===============================================\n");
    printf("Features: Basic Math, Scientific Functions,\n");
    printf("          Unit Conversion, Memory, History\n");
    printf("===============================================\n\n");

    while(1) {
        displayMenu();
        printf("Enter your choice (1-8, 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 0:
                printf("\nThank you for using Enhanced Calculator!\n");
                printf("Total calculations performed: %d\n", historyCount);
                exit(0);
            case 1:
                basicOperations();
                break;
            case 2:
                scientificOperations();
                break;
            case 3:
                unitConversions();
                break;
            case 4:
                memoryOperations();
                break;
            case 5:
                showHistory();
                break;
            case 6:
                clearHistory();
                break;
            case 7:
                printf("Last Result: %.6f\n", lastResult);
                break;
            case 8:
                printf("\n=== CALCULATOR STATISTICS ===\n");
                printf("Total calculations: %d\n", historyCount);
                printf("Memory value: %.6f\n", memory);
                printf("Last result: %.6f\n", lastResult);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}

void displayMenu() {
    printf("\n================ MAIN MENU ================\n");
    printf("1. Basic Operations (+, -, *, /, %, ^)\n");
    printf("2. Scientific Functions (sin, cos, tan, log, etc.)\n");
    printf("3. Unit Conversions (temp, length, weight)\n");
    printf("4. Memory Operations (store, recall, clear)\n");
    printf("5. Show Calculation History\n");
    printf("6. Clear History\n");
    printf("7. Show Last Result\n");
    printf("8. Calculator Statistics\n");
    printf("0. Exit\n");
    printf("==========================================\n");
}

void basicOperations() {
    double num1, num2, result;
    char operator;
    char operation[100];

    printf("\n=== BASIC OPERATIONS ===\n");
    printf("Available operators: +, -, *, /, %%, ^\n");
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operator: ");
    scanf(" %c", &operator);
    
    if(operator != 's' && operator != 'r' && operator != 'f') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
    }

    switch(operator) {
        case '+':
            result = num1 + num2;
            sprintf(operation, "%.3f + %.3f", num1, num2);
            break;
        case '-':
            result = num1 - num2;
            sprintf(operation, "%.3f - %.3f", num1, num2);
            break;
        case '*':
            result = num1 * num2;
            sprintf(operation, "%.3f * %.3f", num1, num2);
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                sprintf(operation, "%.3f / %.3f", num1, num2);
            } else {
                printf("Error: Division by zero!\n");
                return;
            }
            break;
        case '%':
            if((int)num2 != 0) {
                result = (int)num1 % (int)num2;
                sprintf(operation, "%.0f %% %.0f", num1, num2);
            } else {
                printf("Error: Modulo by zero!\n");
                return;
            }
            break;
        case '^':
            result = power(num1, num2);
            sprintf(operation, "%.3f ^ %.3f", num1, num2);
            break;
        case 's':
            result = sqrt(num1);
            sprintf(operation, "sqrt(%.3f)", num1);
            break;
        case 'r':
            result = 1.0 / num1;
            sprintf(operation, "1/%.3f", num1);
            break;
        case 'f':
            if(num1 >= 0 && num1 <= 20 && num1 == (int)num1) {
                result = factorial((int)num1);
                sprintf(operation, "%.0f!", num1);
            } else {
                printf("Error: Factorial only for integers 0-20!\n");
                return;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return;
    }

    printf("\nResult: %s = %.6f\n", operation, result);
    lastResult = result;
    addToHistory(operation, result);
}

void scientificOperations() {
    double num, result;
    int choice;
    char operation[100];

    printf("\n=== SCIENTIFIC FUNCTIONS ===\n");
    printf("1. Trigonometric (sin, cos, tan)\n");
    printf("2. Inverse Trigonometric (asin, acos, atan)\n");
    printf("3. Logarithmic (log, ln)\n");
    printf("4. Exponential (e^x, 10^x)\n");
    printf("5. Hyperbolic (sinh, cosh, tanh)\n");
    printf("Choose function type (1-5): ");
    scanf("%d", &choice);

    printf("Enter number: ");
    scanf("%lf", &num);

    switch(choice) {
        case 1:
            printf("Choose: 1-sin, 2-cos, 3-tan: ");
            int trigChoice;
            scanf("%d", &trigChoice);
            switch(trigChoice) {
                case 1:
                    result = sin(degreeToRadian(num));
                    sprintf(operation, "sin(%.3f°)", num);
                    break;
                case 2:
                    result = cos(degreeToRadian(num));
                    sprintf(operation, "cos(%.3f°)", num);
                    break;
                case 3:
                    result = tan(degreeToRadian(num));
                    sprintf(operation, "tan(%.3f°)", num);
                    break;
            }
            break;
        case 2:
            printf("Choose: 1-asin, 2-acos, 3-atan: ");
            int invTrigChoice;
            scanf("%d", &invTrigChoice);
            switch(invTrigChoice) {
                case 1:
                    if(num >= -1 && num <= 1) {
                        result = radianToDegree(asin(num));
                        sprintf(operation, "asin(%.3f)", num);
                    } else {
                        printf("Error: asin domain is [-1, 1]\n");
                        return;
                    }
                    break;
                case 2:
                    if(num >= -1 && num <= 1) {
                        result = radianToDegree(acos(num));
                        sprintf(operation, "acos(%.3f)", num);
                    } else {
                        printf("Error: acos domain is [-1, 1]\n");
                        return;
                    }
                    break;
                case 3:
                    result = radianToDegree(atan(num));
                    sprintf(operation, "atan(%.3f)", num);
                    break;
            }
            break;
        case 3:
            printf("Choose: 1-log10, 2-ln: ");
            int logChoice;
            scanf("%d", &logChoice);
            if(num <= 0) {
                printf("Error: Logarithm undefined for non-positive numbers!\n");
                return;
            }
            switch(logChoice) {
                case 1:
                    result = log10(num);
                    sprintf(operation, "log10(%.3f)", num);
                    break;
                case 2:
                    result = log(num);
                    sprintf(operation, "ln(%.3f)", num);
                    break;
            }
            break;
        case 4:
            printf("Choose: 1-e^x, 2-10^x: ");
            int expChoice;
            scanf("%d", &expChoice);
            switch(expChoice) {
                case 1:
                    result = exp(num);
                    sprintf(operation, "e^%.3f", num);
                    break;
                case 2:
                    result = pow(10, num);
                    sprintf(operation, "10^%.3f", num);
                    break;
            }
            break;
        case 5:
            printf("Choose: 1-sinh, 2-cosh, 3-tanh: ");
            int hypChoice;
            scanf("%d", &hypChoice);
            switch(hypChoice) {
                case 1:
                    result = sinh(num);
                    sprintf(operation, "sinh(%.3f)", num);
                    break;
                case 2:
                    result = cosh(num);
                    sprintf(operation, "cosh(%.3f)", num);
                    break;
                case 3:
                    result = tanh(num);
                    sprintf(operation, "tanh(%.3f)", num);
                    break;
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\nResult: %s = %.6f\n", operation, result);
    lastResult = result;
    addToHistory(operation, result);
}

void unitConversions() {
    double value, result;
    int choice;
    char operation[100];

    printf("\n=== UNIT CONVERSIONS ===\n");
    printf("1. Temperature (C/F/K)\n");
    printf("2. Length (m/ft/in)\n");
    printf("3. Weight (kg/lb/oz)\n");
    printf("Choose conversion type (1-3): ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%lf", &value);

    switch(choice) {
        case 1:
            printf("Convert from: 1-Celsius, 2-Fahrenheit, 3-Kelvin: ");
            int tempFrom;
            scanf("%d", &tempFrom);
            printf("Convert to: 1-Celsius, 2-Fahrenheit, 3-Kelvin: ");
            int tempTo;
            scanf("%d", &tempTo);

            if(tempFrom == 1 && tempTo == 2) {
                result = (value * 9.0/5.0) + 32;
                sprintf(operation, "%.2f°C to °F", value);
            } else if(tempFrom == 1 && tempTo == 3) {
                result = value + 273.15;
                sprintf(operation, "%.2f°C to K", value);
            } else if(tempFrom == 2 && tempTo == 1) {
                result = (value - 32) * 5.0/9.0;
                sprintf(operation, "%.2f°F to °C", value);
            } else if(tempFrom == 2 && tempTo == 3) {
                result = ((value - 32) * 5.0/9.0) + 273.15;
                sprintf(operation, "%.2f°F to K", value);
            } else if(tempFrom == 3 && tempTo == 1) {
                result = value - 273.15;
                sprintf(operation, "%.2fK to °C", value);
            } else if(tempFrom == 3 && tempTo == 2) {
                result = ((value - 273.15) * 9.0/5.0) + 32;
                sprintf(operation, "%.2fK to °F", value);
            } else {
                result = value;
                sprintf(operation, "Same unit conversion");
            }
            break;
            
        case 2:
            printf("Convert from: 1-Meters, 2-Feet, 3-Inches: ");
            int lengthFrom;
            scanf("%d", &lengthFrom);
            printf("Convert to: 1-Meters, 2-Feet, 3-Inches: ");
            int lengthTo;
            scanf("%d", &lengthTo);

            // Convert to meters first, then to target unit
            double meters = value;
            if(lengthFrom == 2) meters = value * 0.3048;
            else if(lengthFrom == 3) meters = value * 0.0254;

            if(lengthTo == 1) result = meters;
            else if(lengthTo == 2) result = meters / 0.3048;
            else if(lengthTo == 3) result = meters / 0.0254;

            sprintf(operation, "%.3f length units converted", value);
            break;

        case 3:
            printf("Convert from: 1-Kilograms, 2-Pounds, 3-Ounces: ");
            int weightFrom;
            scanf("%d", &weightFrom);
            printf("Convert to: 1-Kilograms, 2-Pounds, 3-Ounces: ");
            int weightTo;
            scanf("%d", &weightTo);

            // Convert to kg first, then to target unit
            double kg = value;
            if(weightFrom == 2) kg = value * 0.453592;
            else if(weightFrom == 3) kg = value * 0.0283495;

            if(weightTo == 1) result = kg;
            else if(weightTo == 2) result = kg / 0.453592;
            else if(weightTo == 3) result = kg / 0.0283495;

            sprintf(operation, "%.3f weight units converted", value);
            break;

        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("\nResult: %s = %.6f\n", operation, result);
    lastResult = result;
    addToHistory(operation, result);
}

void memoryOperations() {
    int choice;
    double value;

    printf("\n=== MEMORY OPERATIONS ===\n");
    printf("Current memory value: %.6f\n", memory);
    printf("1. Store value in memory (MS)\n");
    printf("2. Add to memory (M+)\n");
    printf("3. Subtract from memory (M-)\n");
    printf("4. Recall memory (MR)\n");
    printf("5. Clear memory (MC)\n");
    printf("Choose operation (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter value to store: ");
            scanf("%lf", &value);
            memory = value;
            printf("Value %.6f stored in memory\n", value);
            break;
        case 2:
            printf("Enter value to add: ");
            scanf("%lf", &value);
            memory += value;
            printf("Added %.6f to memory. New value: %.6f\n", value, memory);
            break;
        case 3:
            printf("Enter value to subtract: ");
            scanf("%lf", &value);
            memory -= value;
            printf("Subtracted %.6f from memory. New value: %.6f\n", value, memory);
            break;
        case 4:
            printf("Memory recall: %.6f\n", memory);
            lastResult = memory;
            break;
        case 5:
            memory = 0.0;
            printf("Memory cleared\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void showHistory() {
    if(historyCount == 0) {
        printf("\nNo calculations in history.\n");
        return;
    }

    printf("\n=== CALCULATION HISTORY ===\n");
    printf("Last %d calculations:\n", historyCount > 10 ? 10 : historyCount);
    printf("%-30s %-15s %s\n", "Operation", "Result", "Time");
    printf("--------------------------------------------------------\n");

    int start = historyCount > 10 ? historyCount - 10 : 0;
    for(int i = start; i < historyCount; i++) {
        char timeStr[50];
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", localtime(&history[i].timestamp));
        printf("%-30s %-15.6f %s\n", history[i].operation, history[i].result, timeStr);
    }
}

void clearHistory() {
    historyCount = 0;
    printf("Calculation history cleared.\n");
}

void addToHistory(const char* operation, double result) {
    if(historyCount < MAX_HISTORY) {
        strcpy(history[historyCount].operation, operation);
        history[historyCount].result = result;
        history[historyCount].timestamp = time(NULL);
        historyCount++;
    } else {
        // Shift history and add new entry
        for(int i = 0; i < MAX_HISTORY - 1; i++) {
            history[i] = history[i + 1];
        }
        strcpy(history[MAX_HISTORY - 1].operation, operation);
        history[MAX_HISTORY - 1].result = result;
        history[MAX_HISTORY - 1].timestamp = time(NULL);
    }
}

double factorial(int n) {
    if(n <= 1) return 1;
    double result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double power(double base, double exp) {
    return pow(base, exp);
}

double degreeToRadian(double degree) {
    return degree * PI / 180.0;
}

double radianToDegree(double radian) {
    return radian * 180.0 / PI;
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}