//Stair Path -1// for 1,2.
#include<stdio.h>
int stair(int n){
    if(n==1 || n==2) return n;
    int totalways = stair(n-1) + stair(n-2);
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