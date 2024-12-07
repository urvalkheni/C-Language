//Find The sum of First and last digit of any number by using loop //
#include<stdio.h>
int main(){
    int num,sum=0,firstDigit,lastDigit;

    printf("Enter Any Number to Find sum pf first and last digit :: ");
    scanf("%d",&num);

    lastDigit = num % 10;

    firstDigit = num;

    while(num >=10){
        num = num / 10;
    }
    firstDigit = num;

    sum = firstDigit + lastDigit;

    printf("The Sum of firstDigit and LastDigit is :: %d",sum);
    return 0; 
}