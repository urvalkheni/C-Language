// check leap year by if else //
#include<stdio.h>
int main(){
    int year;

    printf("Enter the year :: ");
    scanf("%d",&year);

    if((year%4==0 && year%100!=0) || (year%400==0)){
        printf("IT'S LEAP YEAR. \n");
    }
    else{
        printf("IT'S COMMON YEAR. \n");
    }
    return 0;
}