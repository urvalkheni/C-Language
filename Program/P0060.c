//Print the factorial(n!) of all n number //
#include<stdio.h>
int main(){
    long long n,i;
    printf("Enter The Number to get it's fectorial :: ");
    scanf("%lld",&n);
    long long pro = 1;
    for(i=1;i<=n;i++){
        pro = pro * i;
        printf("The Factorial of %lld is %lld \n",i,pro);
    }
    
    return 0;
}