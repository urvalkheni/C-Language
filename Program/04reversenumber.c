//WAP to reverse a number and store it //
#include<stdio.h>
int main(){
    long long n,lastDigit,reversenum = 0;
    printf("Enter The Number :: ");
    scanf("%lld",&n);
    while(n!=0){
        reversenum = reversenum * 10;
        reversenum = reversenum + (n%10);
        n=n/10;
        

    }
    printf("The Revrese of the number is :: %lld \n",reversenum);
    return 0;
}