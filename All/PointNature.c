//Giventhree points (x1,y1), (x2,y2) & (x3,y3) so find that all three points fall on one straight //
#include <stdio.h>
int main(){
    float x1,y1;
    float x2,y2;
    float x3,y3;
    double m1,m2;

    printf("Enter Point of A(x1,y1) :: ");
    scanf("%f %f",&x1,&y1);
    printf("Enter Point of B(x2,y2) :: ");
    scanf("%f %f",&x2,&y2);
    printf("Enter Point of C(x3,y3) :: ");
    scanf("%f %f",&x3,&y3);

    m1 = ((y2 - y1)/(x2 - x1));
    m2 = ((y3 - y2)/(x3 - x2));

    if(m1 == m2){
        printf("All Points are on one Straight Line.");
    }
    else{
        printf("Not All Points Are on One straight Line.");
    }

    return 0;
}