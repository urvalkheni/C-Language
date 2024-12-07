//Combination and permutation //
#include<stdio.h>
int factorial(int n){
    int fact  = 1;
    for(int i=1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}
int main(){
    int n,r;
    printf("Enter n :: ");
    scanf("%d",&n);
    printf("Enter r :: ");
    scanf("%d",&r);
    if(n>r){int ncr = (factorial(n)/(factorial(r)*(factorial(n-r))));
    printf("%d",ncr);}
    else printf("Please enter the value of n greater than r. \n");
    return 0;
}