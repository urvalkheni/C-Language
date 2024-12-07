//Double pointer //
#include<stdio.h>
int main(){
    int a = 25;
    int* x = &a;
    int** y = &x;
    int*** z = &y;
    int**** w = &z;
    printf("%d\n",a);
    printf("%d\n",*x);
    printf("%d\n",**y);
    printf("%d\n",***z);
    printf("%d\n",****w);
    return 0;
}