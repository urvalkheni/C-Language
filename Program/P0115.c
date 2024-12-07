//Print sum from 1 to n (Parameterised) //
#include<stdio.h>
void sum(int n,int s){
    if(n==0) 
    {printf("The sum is :: %d",s);
    return;}
    sum(n-1,s+n);
    return;
}
int main(){
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    sum(n,0);
    
    return 0;
}