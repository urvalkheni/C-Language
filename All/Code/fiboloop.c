//Print the nth term of fibonacci terms with series display //
#include<stdio.h>
#include<stdbool.h>

void printFibonacciSeries(int n);

int main(){
    int n,i;
    printf("Enter The number :: ");
    scanf("%d",&n);
    if(n <= 0) {
        printf("Error: Please enter a positive number!\n");
        return 1;
    }
    if(n > 100) {
        printf("Error: Number too large (max 100)!\n");
        return 1;
    }
    int a = 1;
    int b = 1;
    int sum = 1;
    for(i=1;i<=(n-2);i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    printf("The %dth Term is %d\n",n,sum);
    
    // Display the series
    printf("\nFibonacci Series up to %d terms:\n", n);
    printFibonacciSeries(n);
    
    return 0;
}

// Function to print Fibonacci series
void printFibonacciSeries(int n) {
    int a = 1, b = 1, next;
    
    if(n >= 1) printf("1");
    if(n >= 2) printf(", 1");
    
    for(int i = 3; i <= n; i++) {
        next = a + b;
        printf(", %d", next);
        a = b;
        b = next;
    }
    printf("\n");
}