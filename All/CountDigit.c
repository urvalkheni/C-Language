//WAP to count digits of a number //
#include<stdio.h>
int main(){
    int count = 0;
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    while(n!=0){
        n = n/10;
        count++;
    }
    printf("The Number of digits is %d.\n",count);
}