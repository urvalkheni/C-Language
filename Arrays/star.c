//Pattern 11 star//
#include<stdio.h>
int main(){
    int i,j,m,n;
    printf("\n\nKindly Input odd number to print star.\n\n");
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    printf("Enter The cols :: ");
    scanf("%d",&m);

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(i==(n/2+1) || j==(n/2+1)){
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