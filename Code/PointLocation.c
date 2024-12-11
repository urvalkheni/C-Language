//Point Location //
#include<stdio.h>
int main(){
    int y,x;

    printf("Enter The Points(x,y) :: ");
    scanf("%d %d",&x,&y);
    if(x==0 && y==0){
        printf("The Point is The Origin.");
    }
    else if(x==0){
        printf("The Point is on Y-axis.");
    }
    else if(y==0){
        printf("The Point is on X-axis.");
    }
    else{
        printf("The Point doesn't lie on any axis.");
    }
    return 0;
}