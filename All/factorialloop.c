//Print the factorial(n!) of a given number //
#include<stdio.h>
int main(){
    long long n,i;
    printf("Enter The Number to get it's fectorial :: ");
    scanf("%lld",&n);
    long long pro = 1;
    for(i=1;i<=n;i++){
        pro = pro * i;
    }
    printf("The Factorial is %lld \n",pro);
    return 0;
}