//WAP to find value of one number to the power of another //
#include<stdio.h>
int main(){
    long long a,b,i;
    long long power = 1;

    printf("Enter The Number for base :: ");
    scanf("%lld",&a);
    printf("Enter The Number for power :: ");
    scanf("%lld",&b);

    for(i=1;i<=b;i++){
        power = power * a;
    }
    printf("The Power %lld of base %lld is %lld. \n",b,a,power);

    return 0;
}