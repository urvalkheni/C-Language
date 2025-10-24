#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR 256
#define MAX_STACK 100

// Stack for numbers
typedef struct {
    double data[MAX_STACK];
    int top;
} NumberStack;

// Stack for operators
typedef struct {
    char data[MAX_STACK];
    int top;
} OperatorStack;

// Function prototypes
void initNumberStack(NumberStack *s);
void initOperatorStack(OperatorStack *s);
void pushNumber(NumberStack *s, double val);
void pushOperator(OperatorStack *s, char op);
double popNumber(NumberStack *s);
char popOperator(OperatorStack *s);
int isOperator(char c);
int precedence(char op);
double evaluateExpression(char *expr);
double performOperation(double a, double b, char op);
void scientificFunctions();
void statisticalCalculations();
void unitConversions();
void matrixOperations();
void programmingModeCalculations();

void initNumberStack(NumberStack *s) {
    s->top = -1;
}

void initOperatorStack(OperatorStack *s) {
    s->top = -1;
}

void pushNumber(NumberStack *s, double val) {
    if (s->top < MAX_STACK - 1) {
        s->data[++s->top] = val;
    }
}

void pushOperator(OperatorStack *s, char op) {
    if (s->top < MAX_STACK - 1) {
        s->data[++s->top] = op;
    }
}

double popNumber(NumberStack *s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    }
    return 0;
}

char popOperator(OperatorStack *s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    }
    return '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            else {
                printf("Error: Division by zero!\n");
                return 0;
            }
        case '^': return pow(a, b);
        case '%': return fmod(a, b);
        default: return 0;
    }
}

double evaluateExpression(char *expr) {
    NumberStack numStack;
    OperatorStack opStack;
    initNumberStack(&numStack);
    initOperatorStack(&opStack);
    
    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        
        if (isdigit(expr[i]) || expr[i] == '.') {
            double num = 0;
            int decimal = 0;
            double fraction = 1;
            
            while (isdigit(expr[i]) || expr[i] == '.') {
                if (expr[i] == '.') {
                    decimal = 1;
                } else if (!decimal) {
                    num = num * 10 + (expr[i] - '0');
                } else {
                    fraction /= 10;
                    num += (expr[i] - '0') * fraction;
                }
                i++;
            }
            pushNumber(&numStack, num);
        } else if (expr[i] == '(') {
            pushOperator(&opStack, expr[i]);
            i++;
        } else if (expr[i] == ')') {
            while (opStack.top >= 0 && opStack.data[opStack.top] != '(') {
                char op = popOperator(&opStack);
                double b = popNumber(&numStack);
                double a = popNumber(&numStack);
                pushNumber(&numStack, performOperation(a, b, op));
            }
            popOperator(&opStack); // Remove '('
            i++;
        } else if (isOperator(expr[i])) {
            while (opStack.top >= 0 && precedence(opStack.data[opStack.top]) >= precedence(expr[i])) {
                char op = popOperator(&opStack);
                double b = popNumber(&numStack);
                double a = popNumber(&numStack);
                pushNumber(&numStack, performOperation(a, b, op));
            }
            pushOperator(&opStack, expr[i]);
            i++;
        } else {
            i++;
        }
    }
    
    while (opStack.top >= 0) {
        char op = popOperator(&opStack);
        double b = popNumber(&numStack);
        double a = popNumber(&numStack);
        pushNumber(&numStack, performOperation(a, b, op));
    }
    
    return numStack.data[0];
}

void scientificFunctions() {
    int choice;
    double num, result;
    
    printf("\n=== SCIENTIFIC FUNCTIONS ===\n");
    printf("1. Trigonometric Functions\n");
    printf("2. Logarithmic Functions\n");
    printf("3. Exponential Functions\n");
    printf("4. Hyperbolic Functions\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter number: ");
    scanf("%lf", &num);
    
    switch (choice) {
        case 1:
            printf("sin(%.2f) = %.6f\n", num, sin(num));
            printf("cos(%.2f) = %.6f\n", num, cos(num));
            printf("tan(%.2f) = %.6f\n", num, tan(num));
            break;
        case 2:
            if (num > 0) {
                printf("log(%.2f) = %.6f\n", num, log(num));
                printf("log10(%.2f) = %.6f\n", num, log10(num));
            } else {
                printf("Error: Logarithm undefined for non-positive numbers!\n");
            }
            break;
        case 3:
            printf("exp(%.2f) = %.6f\n", num, exp(num));
            printf("2^%.2f = %.6f\n", num, pow(2, num));
            break;
        case 4:
            printf("sinh(%.2f) = %.6f\n", num, sinh(num));
            printf("cosh(%.2f) = %.6f\n", num, cosh(num));
            printf("tanh(%.2f) = %.6f\n", num, tanh(num));
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void statisticalCalculations() {
    int n, i;
    double data[100], sum = 0, mean, variance = 0, stddev;
    
    printf("\n=== STATISTICAL CALCULATIONS ===\n");
    printf("Enter number of values (max 100): ");
    scanf("%d", &n);
    
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
        sum += data[i];
    }
    
    mean = sum / n;
    
    for (i = 0; i < n; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= n;
    stddev = sqrt(variance);
    
    // Sort for median
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    
    double median;
    if (n % 2 == 0) {
        median = (data[n/2 - 1] + data[n/2]) / 2;
    } else {
        median = data[n/2];
    }
    
    printf("\nStatistical Results:\n");
    printf("Sum: %.2f\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);
    printf("Range: %.2f\n", data[n-1] - data[0]);
}

void unitConversions() {
    int choice;
    double value, result;
    
    printf("\n=== UNIT CONVERSIONS ===\n");
    printf("1. Temperature (Celsius to Fahrenheit)\n");
    printf("2. Length (Meters to Feet)\n");
    printf("3. Weight (Kg to Pounds)\n");
    printf("4. Currency (USD to INR)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%lf", &value);
    
    switch (choice) {
        case 1:
            result = (value * 9.0/5.0) + 32;
            printf("%.2f°C = %.2f°F\n", value, result);
            break;
        case 2:
            result = value * 3.28084;
            printf("%.2f meters = %.2f feet\n", value, result);
            break;
        case 3:
            result = value * 2.20462;
            printf("%.2f kg = %.2f pounds\n", value, result);
            break;
        case 4:
            result = value * 83.0; // Approximate rate
            printf("$%.2f = ₹%.2f\n", value, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void programmingModeCalculations() {
    int num, choice;
    
    printf("\n=== PROGRAMMING MODE ===\n");
    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Hexadecimal\n");
    printf("3. Bitwise Operations\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter decimal number: ");
    scanf("%d", &num);
    
    switch (choice) {
        case 1:
            printf("Binary: ");
            for (int i = 31; i >= 0; i--) {
                printf("%d", (num >> i) & 1);
                if (i % 4 == 0) printf(" ");
            }
            printf("\n");
            break;
        case 2:
            printf("Hexadecimal: %X\n", num);
            break;
        case 3:
            printf("Number: %d\n", num);
            printf("NOT: %d\n", ~num);
            printf("Left Shift by 1: %d\n", num << 1);
            printf("Right Shift by 1: %d\n", num >> 1);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int choice;
    char expression[MAX_EXPR];
    
    while (1) {
        printf("\n======= ADVANCED SCIENTIFIC CALCULATOR =======\n");
        printf("1. Basic Expression Evaluation\n");
        printf("2. Scientific Functions\n");
        printf("3. Statistical Calculations\n");
        printf("4. Unit Conversions\n");
        printf("5. Programming Mode\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter expression (use +, -, *, /, ^, %%, parentheses): ");
                getchar(); // Clear buffer
                fgets(expression, MAX_EXPR, stdin);
                printf("Result: %.6f\n", evaluateExpression(expression));
                break;
            case 2:
                scientificFunctions();
                break;
            case 3:
                statisticalCalculations();
                break;
            case 4:
                unitConversions();
                break;
            case 5:
                programmingModeCalculations();
                break;
            case 6:
                printf("Thank you for using Advanced Scientific Calculator!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}