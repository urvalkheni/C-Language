#include<stdio.h>
void swap(int *x,int *y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
int main(){
    int x,y;
    printf("Enter The First Number :: ");
    scanf("%d",&x);
    printf("Enter The Second Number :: ");
    scanf("%d",&y);
    printf("Number Before Swap x --> %d and y --> %d\n",x,y);
    swap(&x,&y);
    printf("Number After Swap x --> %d and y --> %d",x,y);
    return 0;
}