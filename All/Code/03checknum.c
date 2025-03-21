//Check number is negative,positive or zero //
#include<stdio.h>
int main(){
    int a;

    printf("Enter the number :: ");
    scanf("%d",&a);
    if(a==0){
        printf("%d is Zero. \n",a);
    }
    else if(a>0){
        printf("%d is Positive. \n",a);
    }
    else{
        printf("%d is Negative.\n",a);
    }
    return 0;
} 