// WAP to print sum of digits(only even number)num //
#include<stdio.h>
int main(){
    long long sum = 0;
    long long n,lastDigit;
    printf("Enter any Number :: ");
    scanf("%lld",&n);
    while(n!=0){

        lastDigit = n % 10;
        if(lastDigit%2==0){sum = sum + lastDigit;}
        n = n /10;
        
    }
    printf("The Sum of the Number is :: %lld",sum);
    return 0;
    
}