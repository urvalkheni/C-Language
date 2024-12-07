//Pattern 16 0 & 1 triangle//
#include<stdio.h>
int main(){
    int i,j,m,n;
    
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    printf("Enter The cols :: ");
    scanf("%d",&m);
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
          if(j>=i){ if((i+j)%2==0) printf("1 ");
           else printf("0 ");}
        }
        printf("\n");
    }
    return 0;
}