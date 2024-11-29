//print 1 to n method 2//
#include<stdio.h>
int dec(int n){
    if(n==0) return 1;
    dec(n-1);
    printf("%d \n",n);
    
}
int main(){
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    dec(n);
    return 0;
}