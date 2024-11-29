//Maze Path one step only//
#include<stdio.h>
int maze(int cr,int cc,int er,int ec){
    int rightways = 0;
    int downways = 0;
    if(cr==er && cc==ec) return 1;
    if(cr==er) {
        rightways += maze(cr,cc+1,er,ec);
        }
    if(cc==ec) {
        downways += maze(cr+1,cc,er,ec);
        }
    if(cr<er && cc<ec){
        downways += maze(cr+1,cc,er,ec);
        rightways += maze(cr,cc+1,er,ec);
    }
    int totalways = rightways + downways;
    return totalways;
}
int main(){
    int a,b;
    printf("Enter Number of rows :: ");
    scanf("%d",&a);
    printf("Enter Number of cols :: ");
    scanf("%d",&b);
    int numofWays = maze(1,1,a,b);
    printf("The Number of ways is %d",numofWays);    
    return 0;

}