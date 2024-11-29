// Take Positive Input and Say it is Divisable by 5 or 3 //
#include<stdio.h>
int main(){
    int a;
    printf("Enter Positive Integer Number :: ");
    scanf("%d",&a);
    if(a % 5 == 0 || a % 3 == 0){
        printf("Number is divisable by 5 & 3.");
    }
    else{
        printf("Number is not divisable by 5 & 3.");
    }
    return 0;
}