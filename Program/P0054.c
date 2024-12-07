// WAP to print product of digits num //
#include<stdio.h>
int main(){
    long long product = 1;
    long long n,lastDigit;
    printf("Enter any Number :: ");
    scanf("%lld",&n);
    while(n!=0){

        lastDigit = n % 10;
        n = n /10;
        product = product * lastDigit;
    }
    printf("The Product of the Number is :: %lld",product);
    return 0;
    
}