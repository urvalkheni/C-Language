//Pattern 22 Alphabet pyramid//
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
        int a = 65;
        for(int k=1;k<=(2*i-1);k++){
               printf("%c ",a);
               a = a+1;
        }
        
        printf("\n");
    }
    return 0;
}