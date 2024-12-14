//swap the number //
#include<stdio.h>
int main(){
    int a,b;

    printf("Enter the first number :: ");
    scanf("%d",&a);
    printf("Enter the second number :: ");
    scanf("%d",&b);

    b = a + b;
    a = b - a;
    b = b - a;

    printf("Swap Number == first is %d and second is %d. \n",a,b);

    return 0;
}