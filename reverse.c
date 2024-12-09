#include<stdio.h>
int main(){
    int n,r,revrsenum=0,c;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    c = n;
    while(n!=0){
        r = n % 10;
        revrsenum = 10 * revrsenum + r; 
        n /=10;
    }
    printf("Your Orignal Number is :: %d\n",c);
    printf("Your Reverse Number is :: %d",revrsenum);
return 0;
}