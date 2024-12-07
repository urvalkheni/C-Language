//Find The Number is even or odd only for integer //
#include<stdio.h>
int main(){
    int i;
    printf("Please Enter your number (integer type) :: ");
    scanf("%d",&i);

    if(i%2==0 && i!=0){
        printf("Your Number is Even Number.");
    }
    if(i==0){
        printf("Your Number is Zero.");
    }
    if(i%2==1){
        printf("Your Number is Odd Number.");
    }
    

    return 0;
}