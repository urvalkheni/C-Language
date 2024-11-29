//patern 6//
#include<stdio.h>
int main(){
    int i,j,n,m;
    printf("Enter The rows :: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){ 
        for(j=1;j<=5-i;j++){
            printf("%d ",j);
        }
        printf("\n");
    } 
    
    return 0;
}