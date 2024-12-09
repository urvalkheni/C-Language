#include<stdio.h>
int main(){
    char str[] = "Urval Kheni";
    int i=0;
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
    }
    printf("\n");
    i=0;
    while(str[i]!='\0'){
        printf("%c",i[str]);
        i++;
    }
    printf("\n");
    i=0;
    while(str[i]!='\0'){
        printf("%c",*(str+i));
        i++;
    }
    printf("\n");
   
    return 0;
}