//Print GP //
#include<stdio.h>
int main(){
    int i,n;

    printf("Enter The term Number :: ");
    scanf("%d",&n);

    int a = 1;

    for(i=1;i<=n;i++){
        printf("%d ",a);
        a *= 2;
    }
    return 0;
}