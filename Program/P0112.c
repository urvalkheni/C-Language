//print 1 to n parameter method 1//
#include<stdio.h>
int ace(int x,int n){
    printf("%d \n",x);
    if(x>=n) return n;
    ace(x+1,n);
    
    
}
int main(){
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    ace(1,n);
    return 0;
}