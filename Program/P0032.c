//AP Without Using maths //
#include<stdio.h>
int main(){
    int i,n;
    printf("Enter The value of n :: ");
    scanf("%d",&n);

    int a = 4;
    for(i=1;i<=n;i++){
        printf("%d ",a);
        a+=3;

    }
    return 0;
}