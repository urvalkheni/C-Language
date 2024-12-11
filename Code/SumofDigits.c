// WAP to print sum of digits num //
#include<stdio.h>
int main(){
    long long sum = 0;
    long long n,lastDigit;
    printf("Enter any Number :: ");
    scanf("%lld",&n);
    while(n!=0){

        lastDigit = n % 10;
        n = n /10;
        sum = sum + lastDigit;
    }
    printf("The Sum of the Number is :: %lld",sum);
    return 0;
    
}