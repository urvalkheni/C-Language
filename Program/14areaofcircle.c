//write a programme to find area of circle//
#include<stdio.h>
int main(){
    float r;
    float pi,area;

    pi = 22.0/7;

    printf("The Radius of the circle is :: ");
    scanf("%f",&r);

    area = pi * r * r;

    printf("The area of the circle is %f. \n",area);

    return 0;
}