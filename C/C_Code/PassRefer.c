//Pass by reference //
#include<stdio.h>
void swap(int*a,int* b){
    int temp = *a;
    *a = *b;
    *b  = temp;

    return;

}
int main(){
    int a,b;       
    printf("Enter the value of a :: ");
    scanf("%d",&a);
    printf("Enter the value of b :: ");
    scanf("%d",&b);

    swap(&a,&b);

    printf("Now the Number a is :: %d \n",a);
    printf("Now the Number b is :: %d \n",b);

    return 0;  
}