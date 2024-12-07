//Pattern 22 number pyramid mast//
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
        int a=1;
        for(int k=1;k<=i;k++){
               printf("%d ",a);
               a=a+1;
        }
        int b =i-1;
        for(int o=1;o<=i-1;o++){
                printf("%d ",b);
                b--;
               }
        
        
        printf("\n");
    }
    return 0;
}