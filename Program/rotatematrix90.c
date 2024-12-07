#include<stdio.h>
int main(){

    int matrix[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printf("Before 90 rotation :: \n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("After 90 Rotation :: \n");
    for(int i=0;i<4;i++){
        for(int j=3;j>=0;j--){
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}
/*
1 2 3   7 4 1  (0,0) (0,1) (0,2)    (2,0) (1,0) (0,0)
4 5 6 = 8 5 2  (1,0) (1,1) (1,2) =  (2,1) (1,1) (0,1)
7 8 9   9 6 3  (2,0) (2,1) (2,2)    (2,2) (1,2) (0,2)

*/