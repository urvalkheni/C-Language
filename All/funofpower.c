//Make a Function calculates a raised to the power of b//
#include<stdio.h>
int power(int a,int b){
    int recAns = 1;
    if(b==0) return 1;
    recAns = a * power(a,b-1);
    return recAns;
}
int main(){
    int a,b;

    printf("Enter The Base :: ");
    scanf("%d",&a);
    printf("Enter The Power :: ");
    scanf("%d",&b);
    int p = power(a,b);
    printf("The Power of %d  of the base %d is %d. \n",b,a,p);
    return 0;
}