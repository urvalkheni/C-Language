//Pattern 22 alphabet pyramid mast//
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
        int a=65;
        for(int k=1;k<=i;k++){
               printf("%c ",a);
               a=a+1;
        }
        int b =(i+64)-1;
        for(int o=1;o<=i-1;o++){
                printf("%c ",b);
                b--;
               }
        
        
        printf("\n");
    }
    return 0;
}