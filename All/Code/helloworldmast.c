#include<stdio.h>
#include<windows.h>
int main(){
    char str[] = "Welcome to C Programing...!";
    for(int i=0;str[i]!='\0';i++){
        for(int j=0;j<=i;j++){
            printf("%c",str[j]);
            Sleep(100);
        }
        
        printf("\n");
    }
    return 0;
}