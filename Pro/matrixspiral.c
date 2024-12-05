#include<stdio.h>
int main(){
    int n,i,j,a;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    int m[n][n];
    for(i=0,a=1;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j] = a;
            a++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}