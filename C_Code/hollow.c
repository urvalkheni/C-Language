#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n-1;j++){
            if(i+j<=n+1)printf("* ");
            else printf("  ");
        }
        for(j=n+1;j<=n+n;j++){
            if(j>=i+n)printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    for(i=n+1;i<=n+n;i++){
        for(j=1;j<=n-1;j++){
            if(i>=j+n)printf("* ");
            else printf("  ");
        }
        for(j=n+1;j<=n+n;j++){
            if(i+j>=(3*n)+1)printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    return 0;
}