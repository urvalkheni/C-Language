//pattern 24 star triangle ulta mast //
#include<stdio.h>
int main(){
    int i,j,m,n;
    printf("Enter The number :: ");
    scanf("%d",&n);
    int nsp = 0;
    int nst = n;
        
    for(i=1;i<=n;i++){
           for(j=1;j<=nsp;j++){
            printf("  ");
           }
           for(int k =1;k<=nst;k++){
            printf("* ");
            }
            nsp++;
            nst--;
          
        printf("\n");
    }
    return 0;
}
    