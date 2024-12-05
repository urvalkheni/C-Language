#include<stdio.h>
int main(){
    int n,m,i,j,a;
    printf("Enter The Row Number :: ");
    scanf("%d",&n);
    printf("Enter The Coloumn Number :: ");
    scanf("%d",&m);
    int m[n][n];
    for(i=0,a=1;i<n;i++){
        for(j=0;j<m;j++){
            m[i][j] = a;
            a++;
        }
    }
    // spiral Print
    printf("\n");
    int minr,maxc,maxr,minc;
    return 0;
}