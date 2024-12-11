// maze path 2 parameter //
#include<stdio.h>
int maze2(int n,int m){
    int rightways = 0;
    int downways = 0;
    if(n==1 && m==1) return 1;
    if(n==1){
        rightways += maze2(n,m-1);
    }
    if(m==1){
        downways += maze2(n-1,m);
    }
    if(n>1 && m>1){
        rightways += maze2(n,m-1);
        downways += maze2(n-1,m);
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
    int numofWays = maze2(a,b);
    printf("The Number of ways is %d",numofWays);    
    return 0;

}