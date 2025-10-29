// Enhanced Number Analyzer with Comprehensive Mathematical Properties
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

// Function prototypes
void analyzeNumber(long long num);
bool isPrime(long long n);
bool isPerfect(long long n);
bool isArmstrong(long long n);
bool isPalindrome(long long n);
bool isHappy(long long n);
long long sumOfSquareDigits(long long n);
void findFactors(long long n);
void primeFactorization(long long n);
long long fibonacci(int n);
bool isFibonacci(long long n);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
int countDigits(long long n);
long long reverseNumber(long long n);
long long sumOfDigits(long long n);
long long productOfDigits(long long n);
void displayNumberProperties(long long n);

int main() {
    long long number;
    char choice;

    printf("=============================================\n");
    printf("    ENHANCED NUMBER ANALYZER v2.0\n");
    printf("=============================================\n");
    printf("Comprehensive Mathematical Property Checker\n");
    printf("=============================================\n\n");

    do {
        printf("Enter a number to analyze: ");
        scanf("%lld", &number);

        // Basic classification
        printf("\n============ BASIC CLASSIFICATION ============\n");
        if(number == 0) {
            printf("Number %lld is ZERO\n", number);
        } else if(number > 0) {
            printf("Number %lld is POSITIVE\n", number);
        } else {
            printf("Number %lld is NEGATIVE\n", number);
        }

        // Comprehensive analysis
        analyzeNumber(llabs(number)); // Use absolute value for analysis

        printf("\nDo you want to analyze another number? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");

    } while(choice == 'y' || choice == 'Y');

    printf("Thank you for using Enhanced Number Analyzer!\n");
    return 0;
}

void analyzeNumber(long long num) {
    printf("\n=========== COMPREHENSIVE ANALYSIS ===========\n");
    printf("Number: %lld\n", num);
    
    // Basic properties
    printf("\n--- Basic Properties ---\n");
    printf("Absolute value: %lld\n", num);
    printf("Number of digits: %d\n", countDigits(num));
    printf("Reversed number: %lld\n", reverseNumber(num));
    printf("Sum of digits: %lld\n", sumOfDigits(num));
    printf("Product of digits: %lld\n", productOfDigits(num));

    // Even/Odd classification
    if(num == 0) {
        printf("Parity: Neither even nor odd (Zero)\n");
    } else if(num % 2 == 0) {
        printf("Parity: EVEN\n");
    } else {
        printf("Parity: ODD\n");
    }

    // Mathematical properties
    printf("\n--- Mathematical Properties ---\n");
    printf("Is Prime: %s\n", isPrime(num) ? "YES" : "NO");
    printf("Is Perfect: %s\n", isPerfect(num) ? "YES" : "NO");
    printf("Is Armstrong: %s\n", isArmstrong(num) ? "YES" : "NO");
    printf("Is Palindrome: %s\n", isPalindrome(num) ? "YES" : "NO");
    printf("Is Happy Number: %s\n", isHappy(num) ? "YES" : "NO");
    printf("Is Fibonacci: %s\n", isFibonacci(num) ? "YES" : "NO");

    // Special number classifications
    printf("\n--- Special Classifications ---\n");
    if(num > 0) {
        long long square = (long long)sqrt(num);
        if(square * square == num) {
            printf("Perfect Square: YES (√%lld = %lld)\n", num, square);
        } else {
            printf("Perfect Square: NO\n");
        }

        long long cube = (long long)round(cbrt(num));
        if(cube * cube * cube == num) {
            printf("Perfect Cube: YES (∛%lld = %lld)\n", num, cube);
        } else {
            printf("Perfect Cube: NO\n");
        }
    }

    // Factors and factorization
    if(num > 0 && num <= 10000) { // Limit for performance
        printf("\n--- Factor Analysis ---\n");
        findFactors(num);
        printf("\nPrime Factorization: ");
        primeFactorization(num);
        printf("\n");
    }

    // Number theory properties
    if(num > 1) {
        printf("\n--- Number Theory ---\n");
        printf("GCD with 12: %lld\n", gcd(num, 12));
        printf("LCM with 12: %lld\n", lcm(num, 12));
    }

    displayNumberProperties(num);
}

bool isPrime(long long n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(long long i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isPerfect(long long n) {
    if(n <= 1) return false;
    
    long long sum = 1;
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            sum += i;
            if(i * i != n) sum += n / i;
        }
    }
    return sum == n;
}

bool isArmstrong(long long n) {
    long long original = n;
    int digits = countDigits(n);
    long long sum = 0;
    
    while(n > 0) {
        long long digit = n % 10;
        sum += (long long)pow(digit, digits);
        n /= 10;
    }
    
    return sum == original;
}

bool isPalindrome(long long n) {
    return n == reverseNumber(n);
}

bool isHappy(long long n) {
    long long slow = n, fast = n;
    
    do {
        slow = sumOfSquareDigits(slow);
        fast = sumOfSquareDigits(sumOfSquareDigits(fast));
    } while(slow != fast);
    
    return slow == 1;
}

long long sumOfSquareDigits(long long n) {
    long long sum = 0;
    while(n > 0) {
        long long digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

void findFactors(long long n) {
    printf("Factors: ");
    int count = 0;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            printf("%lld ", i);
            count++;
            if(i != n / i) {
                printf("%lld ", n / i);
                count++;
            }
        }
    }
    printf("\nTotal factors: %d\n", count);
}

void primeFactorization(long long n) {
    // Handle 2
    while(n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    
    // Handle odd factors
    for(long long i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            printf("%lld ", i);
            n /= i;
        }
    }
    
    // If n is still greater than 2, then it's prime
    if(n > 2) {
        printf("%lld ", n);
    }
}

bool isFibonacci(long long n) {
    if(n < 0) return false;
    
    long long a = 0, b = 1;
    if(n == a || n == b) return true;
    
    long long c = a + b;
    while(c <= n) {
        if(c == n) return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}

long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int countDigits(long long n) {
    if(n == 0) return 1;
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

long long reverseNumber(long long n) {
    long long reversed = 0;
    while(n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

long long sumOfDigits(long long n) {
    long long sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long productOfDigits(long long n) {
    if(n == 0) return 0;
    long long product = 1;
    while(n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

void displayNumberProperties(long long n) {
    printf("\n--- Advanced Properties ---\n");
    
    // Digital root
    long long digitalRoot = n;
    while(digitalRoot >= 10) {
        digitalRoot = sumOfDigits(digitalRoot);
    }
    printf("Digital root: %lld\n", digitalRoot);
    
    // Divisibility rules
    printf("\nDivisibility tests:\n");
    if(n % 2 == 0) printf("- Divisible by 2\n");
    if(sumOfDigits(n) % 3 == 0) printf("- Divisible by 3\n");
    if(n % 4 == 0) printf("- Divisible by 4\n");
    if(n % 10 == 0 || n % 10 == 5) printf("- Divisible by 5\n");
    if(n % 2 == 0 && sumOfDigits(n) % 3 == 0) printf("- Divisible by 6\n");
    if(n % 8 == 0) printf("- Divisible by 8\n");
    if(sumOfDigits(n) % 9 == 0) printf("- Divisible by 9\n");
    if(n % 10 == 0) printf("- Divisible by 10\n");
    
    // Binary representation
    if(n > 0 && n <= 1024) {
        printf("\nBinary representation: ");
        if(n == 0) {
            printf("0");
        } else {
            char binary[65];
            int index = 0;
            long long temp = n;
            while(temp > 0) {
                binary[index++] = (temp % 2) + '0';
                temp /= 2;
            }
            for(int i = index - 1; i >= 0; i--) {
                printf("%c", binary[i]);
            }
        }
        printf("\n");
    }
} 