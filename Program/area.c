#include<stdio.h>
int main(){
    float radius;
    float area;

    scanf("%f",&radius);

    area = 4 * (22.0/7) * radius * radius ;
    printf("\n Your Circle's Area is '%f' \n",area);

    return 0;
}