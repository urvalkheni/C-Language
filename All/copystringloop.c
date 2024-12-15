#include<stdio.h>
int main(){
    int size=0,i=0;
    char str1[50];
    printf("Enter The Frist String :: ");
    gets(str1);
    while(str1[i]!='\0'){
        i++;
        size++;
    }
    char str2[size];
    for(int j=0;j<size;j++){
        str2[j] = str1[j];
    }
    printf("Copy of Entered String :: %s",str2);
}