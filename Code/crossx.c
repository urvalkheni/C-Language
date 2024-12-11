//Pattern 13 coss x //
#include<stdio.h>
int main(){
    int i,j,m,n;
    
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    m = n;

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==j || (i+j==n+1) || (i+j==m+1)){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    } return 0;
} 