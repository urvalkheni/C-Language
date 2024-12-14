#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr = (int*) malloc(10*4);
    printf("%d\n",*ptr);
    ptr++;
    printf("%d\n",*ptr);
    ptr++;
    printf("%d\n",*ptr);
    ptr++;
    printf("%d\n",*ptr);
    return 0;
}