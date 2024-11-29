//print n to 1//
#include<stdio.h>
int dec(int n){
    printf("%d \n",n);
    if(n==1) return 1;
    dec(n-1);
    
}
int main(){
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    dec(n);
    return 0;
}