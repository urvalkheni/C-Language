//Take Positive integar and disiable by 5 & 3 but not by 15 //
#include<stdio.h>
int main(){
    int a;
    printf("Enter Positive Integer Number :: ");
    scanf("%d",&a);
    if(a % 5 == 0 || a % 3 == 0){
        if(a%15!=0){
        printf("Number is divisable by 5 or 3.");
        }
    else{
        printf("Number is  divisable by 15.");
    }
    }
    else{
        printf("Number is not divisable by 5 & 3.");
    }
    return 0;
}           