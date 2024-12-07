#include<stdio.h>
int main(){
    int matrix[3][4] = {{1,0,1,1},{1,0,1,0},{0,1,0,1}};
    int maxcount=0,count;
    for(int i=0;i<3;i++){
        count = 0;
        for(int j=0;j<4;j++){
            if(matrix[i][j]==1) count += 1;
        }
        if(maxcount < count){
            maxcount = count;
           }    
        }
        printf("there are %d 1. \n",maxcount);
    return 0;
}