#include<stdio.h>
int main(){
    int n;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    int m[n][n];
    for(int i=0,a=1;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j] = a;
            a++;
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){for(int j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }}
        else {for(int j=n-1;j>=0;j--){
            printf("%d ",m[i][j]);
        }}
        printf("\n");
    }
    return 0;
}