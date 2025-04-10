#include<stdio.h>
int main(){
    int n,r,c;
    printf("Enter N for n x n matrix :: ");
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         arr[i][j] = 0; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          printf(" %d ",arr[i][j]);
        }
       printf("\n"); 
    }
    printf("Enter The Position of the Queen :: ");
    scanf("%d %d",&r,&c);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==r || j==c) arr[i][j] = 4;

            else arr[i][j] = 0; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          printf(" %d ",arr[i][j]);
        }
       printf("\n"); 
    }
    return 0;
}