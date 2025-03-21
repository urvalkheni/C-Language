//Stair Path -2// for 1,2,3.
#include<stdio.h>
int stair(int n){
    if(n==1 || n==2 || n==3) return n;
    int totalways = stair(n-1) + stair(n-2) + stair(n-3);
    return totalways;

}
int main(){
    int n;
    printf("Enter The Number :: ");
    scanf("%d",&n); 
    int ways = stair(n);
    printf("Total ways to ground to %d is %d. \n",n,ways);
    return 0;
}