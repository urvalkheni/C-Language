// Take three Numbers and Tell if they can be side of triangle //
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter The First side :: ");
    scanf("%d",&a);
    printf("Enter The Second side :: ");
    scanf("%d",&b);
    printf("Enter The Third Side :: ");
    scanf("%d",&c);

    if(a + b > c && b + c > a && a + c > b ){
        printf("Triangle is Possible.");
    }
    else{
        printf("Triangle is not Possible.");
    }    

    return 0;
}