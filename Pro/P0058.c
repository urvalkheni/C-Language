//Print Series of 1 - 2 + 3 - 4 + 5 - 6 ...up to n terms // 
#include<stdio.h>
int main(){
    long long n,sum=0;
    printf("Enter The Number :: ");
    scanf("%lld",&n);
    if(n%2==0) sum = (-n/2);
    else if(n%2!=0) sum = (-n/2) + n;
    printf("The Sum of n terms of number is :: %lld",sum);
    
    return 0;
}