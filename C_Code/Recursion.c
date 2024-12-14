//Recursion//
#include<stdio.h>
int factorial(int a){
    if(a==1 || a===0) return 1;
     int recAns = a*factorial(a-1);
    return recAns;
}
int main(){
    int n;
    printf("Enter The Number :: ");
    scanf("%d",&n);
      int fact = factorial(n); 
      printf("Factorial of %d is %d. \n",n,fact);
    return 0;  
}          