#include<stdio.h>
int main(){
    int a[5];
    for(int i=0;i<5;i++){
        printf("Ennter the %d element :: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Orignal array. \n");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Reverse array. \n");
    for(int i=4;i>=0;i--){
        printf("%d ",a[i]);
    }
    return 0;
}