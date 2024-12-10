//Pattern 17 star triangle mast//
#include<stdio.h>
int main(){
    int i,j,m,n;
    
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    m=n;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m-i;j++){
               printf("  ");        
        }
        for(int k=1;k<=i;k++){
            printf("* ");
        }
        
        printf("\n");
    }
    return 0;
}