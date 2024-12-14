//fibonaci terms //
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the terms :: ");
    scanf("%d",&n);
    int a = 0;
    int b = 1;
    int c;
    printf("%d ",b);
    for(i=1;i<n;i++){
        c = a + b;
        printf("%d ",c);
        a = b;
        b = c;
    }
    return 0;
}