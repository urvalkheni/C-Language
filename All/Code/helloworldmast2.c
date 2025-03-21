#include<stdio.h>
#include<windows.h>
#include<string.h>
int main(){
    char str[] = "Welcome to C Programing...!";
    int x= strlen(str);
    for(int i=0;str[i]!='\0';i++){
        for(int j=0;j<=i+1;j++){
            printf("%c",str[x-j]);
            Sleep(100);
        }
        
        printf("\n");
    }
    return 0;
}