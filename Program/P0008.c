// Fractional Part of Number //
#include<stdio.h>
int main(){
    float x;
    int y;
    printf("Please Enter The First (Decimal Number) Digit :: ");
    scanf("%f",&x);
    y = x;
    printf("\nThe Number of X is :: '%f' and It's Integer Part is :: '%d' ",x,y);
    float z;
    z = x - y;
    printf("\nFractional Part is :: '%f' ",z);
    return 0;
}