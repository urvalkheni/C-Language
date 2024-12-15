//Pattern 12 holllow rectangle//
#include<stdio.h>
int main(){
    int i,j,m,n;
    printf("\n\nKindly Input with difference of 2 or 4.\n\n");
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    printf("Enter The cols :: ");
    scanf("%d",&m);

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i == 1 || j==1 ||  j==m || i==n){
                printf("* ");
                }
            else{
                printf("  ");
                }
        }
        printf("\n");
    }
    return 0;
}