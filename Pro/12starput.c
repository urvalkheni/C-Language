//star diamond//
#include<stdio.h>
int main(){
    int i,j,m,n;
    
    printf("Enter The Rows :: ");
    scanf("%d",&n);
    int nsp = n/2;
    int nst = 1;
    int ml = (n/2) + 1;
    m=n;
    
    for(i=1;i<=n;i++){
           for(j=1;j<=nsp;j++){
            printf("  ");
           }
           for(int k =1;k<=nst;k++){
            printf("* ");
            
           }
           if(i<ml){
            nsp--;
           nst+=2;
           }
           else{
            nsp++;
           nst-=2;
           }
        printf("\n");
    }
    return 0;
}