//Print GP 3,12,48.... //
#include<stdio.h>
int main(){
    int i,n;

    printf("Enter The term Number :: ");
    scanf("%d",&n);

    int a = 3;

    for(i=1;i<=n;i++){
        printf("%d ",a);
        a *= 4;
    }
    return 0;
}