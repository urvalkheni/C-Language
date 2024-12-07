//Print sum from 1 to n (return type) //
#include<stdio.h>
int sum(int n){
    int recAns;
    if(n==1 || n==0) return 1;
    recAns = n + sum (n-1);
    return recAns;
}
int main(){
    int n;
    printf("Enter any Number :: ");
    scanf("%d",&n);
    printf("The Sum is :: %d \n",sum(n));
    return 0;
}