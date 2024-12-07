//Print Table of any Number //
#include<stdio.h>
int main(){
    int i,n;
    printf("Enter The Number which Table You want to print :: ");
    scanf("%d",&n);
    for(i=1;i<=10;i++){printf("%d x %d = %d\n",n,i,(n*i));}
    return 0;
}