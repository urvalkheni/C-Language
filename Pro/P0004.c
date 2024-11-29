//Area of Circle By input //
#include<stdio.h>
int main(){
    float radius;
    float pi = (22.0/7);
    
    printf("Enter The Radius of Circle :: ");
    scanf("%f",&radius);
    float area = pi * radius * radius;

    printf("\n The Area of Circle is :: '%f' ",area);
    return 0;
}