//Print the nth term of fibonaci terms //
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter The number :: ");
    scanf("%d",&n);
    int a = 1;
    int b = 1;
    int sum = 1;
    for(i=1;i<=(n-2);i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    printf("The %dth Term is %d ",n,sum);
    return 0;
}