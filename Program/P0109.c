#include<stdio.h>
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
int gcd(int a,int b){
    int hcf;
    for(int i =min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            hcf = i;
            break;
        }
    }
}
int main(){
    int a;
    printf("Enter First number :: ");
    scanf("%d",&a);
    int b; 
    printf("Enter Second number :: ");
    scanf("%d",&b);
    int hcf = gcd(a,b);
    printf("The HCF/GCD od %d and %d is :: %d. \n",a,b,hcf);
    return 0;
}     