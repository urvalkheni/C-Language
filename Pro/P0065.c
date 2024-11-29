//WAP to print all the ASCII Values and Thier Equvivlent charcters //
#include<stdio.h>
int main(){
    int i,j;
    for(i=65;i<91;i++) printf("The ASCII value of %d is %c.\n",i,i);
    for(j=97;j<123;j++)  printf("The ASCII value of %d is %c.\n",j,j);
    return 0;
}