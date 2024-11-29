//Write a function to calculate the nth term fibonacci terms //
#include<stdio.h>
int fibo(int n){
    if(n==1 || n==2) return 1;
    int num = fibo(n-1) + fibo(n-2);
    return num;
}
int main(){
    int n;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    printf("nth fibonaci term is %d",fibo(n));
    return 0;
}