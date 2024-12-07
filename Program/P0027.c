//Print Hello world for n times //
#include<stdio.h>
int main(){
    int n;

    printf("Enter Number to print :: ");
    scanf("%d",&n);

    for(int i=1;i<=n; i++){
        printf("Hello world.\n");
    }
    return 0;
}   