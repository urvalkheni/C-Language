//Pattern 18 Rhombus//
#include<stdio.h>
int main(){
    int i,j,m,n;
    
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    m=n;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m-i;j++){
               printf("# ");        
        }
        for(int k=1;k<=n;k++){
            printf("* ");
        }
        
        printf("\n");
    }
    return 0;
}