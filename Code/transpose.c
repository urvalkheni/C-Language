#include<stdio.h>
int main(){
    int r,c;
    printf("Enter Number of rows :: ");
    scanf("%d",&r);
    printf("Enter Number of cols :: ");
    scanf("%d",&c);
    int mat1[r][c]; // = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat1[i][j]);
        }
    }printf("\n");
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%3d",mat1[i][j]);
        }
        printf("\n");
    }printf("\n");
for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            printf("%d ",mat1[i][j]);
        }
        printf("\n");
    }
    return 0;
}