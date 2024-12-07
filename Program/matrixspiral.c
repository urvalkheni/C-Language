#include<stdio.h>
int main(){
    int n,m,i,j,a;
    printf("Enter The Row Number :: ");
    scanf("%d",&m);
    printf("Enter The Coloumn Number :: ");
    scanf("%d",&n);
    int m[m][n];
    for(i=0,a=1;i<m;i++){
        for(j=0;j<n;j++){
            m[i][j] = a;
            a++;
        }
    }
    // spiral Print
    printf("\n");
    int minr=0,maxc=n-1,maxr=m-1,minc=0,count;
    while(){
        
    }
    return 0;
}