#include<stdio.h>
int main(){
    char str1[] = "Hello";
    char str2[] = "Hello";
    printf("%p\n",&str1);
    printf("%p",&str2);
    return 0;
}