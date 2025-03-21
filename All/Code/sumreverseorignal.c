//WAP to reverse a number and sum it with the orignal one //
#include<stdio.h>
int main(){
    long long n,sum,orignalnum,lastDigit,reversenum = 0;
    printf("Enter The Number :: ");
    scanf("%lld",&n);
    orignalnum = n;
    while(n!=0){
        reversenum = reversenum * 10;
        reversenum = reversenum + (n%10);
        n=n/10;
        

    }
    sum = orignalnum + reversenum;
    printf("The Revrese of the number is :: %lld and thier sum is % lld \n",reversenum,sum);
    return 0;
}