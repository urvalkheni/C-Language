#include<stdio.h>
int main(){
    int marks[10];
    for(int i=0;i<10;i++){
        printf("Enter The Marks of %d Student :: ",i+1);
        scanf("%d",&marks[i]);
    }
    for(int i=0;i<10;i++){
        if(marks[i]<37)printf("%d student has marks less than 37 and marks is %d. \n",i,marks[i]);
    }

    return 0;
}