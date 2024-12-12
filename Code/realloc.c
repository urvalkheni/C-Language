#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr = malloc(10*4);
    printf("%p\n",ptr);
    ptr = realloc(ptr,200*4);
    printf("%p",ptr);
    free(ptr);
    return 0;
}