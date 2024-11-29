// Area and Perameter of Rectangle //
#include<stdio.h>
int main(){

    int area,length,perameter,height;
    printf("Please enter the Length of Rectangle :: ");
    scanf("%d",&length);
    printf("Please enter the Height of Rectangle :: ");
    scanf("%d",&height);

    area = length * height;
    perameter = 2 * (length + height);

    printf("The Area Of rectangle is :: '%d' \n",area);
    printf("The perameter of rectangle is :: '%d' \n",perameter);
    if(area>perameter){
        printf("The Area of Rectangle is Bigger than Perameter.");
    }
    else{
        printf("The Perameter of Rectangle is Bigger than Area.");  
    }

    return 0;
}         