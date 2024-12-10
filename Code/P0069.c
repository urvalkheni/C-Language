//patern 3//
#include<stdio.h>
int main(){
    int i,j,n,m;
    printf("Enter The rows :: ");
    scanf("%d",&n);
    printf("Enter The cols :: ");
    scanf("%d",&m);
    for(i=1;i<=n;i++){ 
        for(j=1;j<=m;j++){
            if(i>=j){printf("* ");}
        }
        printf("\n");
    } 
    
    return 0;
}