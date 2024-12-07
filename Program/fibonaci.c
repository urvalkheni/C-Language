#include<stdio.h>
int main(){
    int i,n;
    int a,b,c;
    a = 0; 
    b = 1;
    printf("Enter the least value :: ");
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        if(i==1) printf("%d ",b);
        c = a + b;
        printf("%d ",c);
        a = b;
        b = c;
    }
    return 0;
}