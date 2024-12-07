#include<stdio.h>
int main(){
    int matrix1[3][3];
    int matrix2[3][3];
    int resultmatrix[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter Second Matrix :: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            resultmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",resultmatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}