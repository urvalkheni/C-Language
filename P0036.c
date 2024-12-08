//Enter Gp 100 50 25 ...//
#include<stdio.h>
int main(){
    int i,n;

    printf("Enter the n'th term :: ");
    scanf("%d",&n);
    float a = 100;
    for(i=1;i<=n;i++){
        printf("%f ",a);
        a /= 2;
    }
    return 0;
}