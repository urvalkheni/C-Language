//patern 2//
#include<stdio.h>
int main(){
    int i,j,n,m;
    printf("Enter The rows :: ");
    scanf("%d",&n);
    printf("Enter The cols :: ");
    scanf("%d",&m); 
    for(i=1;i<=n;i++){ // outer loop no. of line rows i
        for(j=1;j<=m;j++){ // inner loop no. of cols j
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}