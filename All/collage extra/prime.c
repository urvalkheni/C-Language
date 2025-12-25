#include <stdio.h>
#include <math.h>

// Basic method to check if number is prime
int isPrimeBasic(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to find all prime numbers up to n (Sieve of Eratosthenes)
void sieveOfEratosthenes(int n) {
    int prime[n + 1];
    
    // Initialize all as prime
    for (int i = 0; i <= n; i++)
        prime[i] = 1;
    
    prime[0] = prime[1] = 0;
    
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
    
    // Print all prime numbers
    printf("\nPrime numbers from 1 to %d:\n", n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
    printf("\n\nTotal prime numbers: %d\n", count);
}

// Function to find prime factors
void primeFactors(int n) {
    printf("Prime factors of %d: ", n);
    
    while (n % 2 == 0) {
        printf("2 ");
        n = n / 2;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }
    
    if (n > 2)
        printf("%d", n);
    
    printf("\n");
}

int main() {
    int choice, num;
    
    printf("=== Prime Number Utilities ===\n\n");
    printf("1. Check if a number is Prime\n");
    printf("2. List all Primes up to N\n");
    printf("3. Find Prime Factors\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nEnter a number: ");
            scanf("%d", &num);
            if (isPrimeBasic(num))
                printf("\n%d is a PRIME number.\n", num);
            else
                printf("\n%d is NOT a prime number.\n", num);
            break;
            
        case 2:
            printf("\nEnter upper limit: ");
            scanf("%d", &num);
            if (num < 2) {
                printf("No prime numbers less than 2.\n");
            } else {
                sieveOfEratosthenes(num);
            }
            break;
            
        case 3:
            printf("\nEnter a number: ");
            scanf("%d", &num);
            if (num < 2) {
                printf("No prime factors for numbers less than 2.\n");
            } else {
                primeFactors(num);
            }
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
