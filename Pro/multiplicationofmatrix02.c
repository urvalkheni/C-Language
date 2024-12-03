#include<stdio.h>
int main(){
    int m,n,p,q,cr;
    printf("Enter The Row of first Matrix :: ");
    scanf("%d",&m);
    printf("Enter The Column of first Matrix :: ");
    scanf("%d",&n);
    printf("Enter The Row of Second Matrix :: ");
    scanf("%d",&p);
    printf("Enter The Column of Second Matrix :: ");
    scanf("%d",&q);
    int res[m][q];
    for(int x=0;x<m;x++){
        for(int y=1;y<q;y++){
            res[x][y] = 0;
        }
    }
    int a[m][n];
    int b[p][q];
    printf("First Matrix ::\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("a[%d][%d] = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Second Matrix ::\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("b[%d][%d] = ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
   if(n==p){ 
    cr = n;
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            for(int k=0;k<cr;k++){
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }}
    else printf("These matrix Can't be multiplyed...\n");
    if(n==p){ for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
           printf("%d ",res[i][j]);
        }
        printf("\n");
    }}

    return 0;
}