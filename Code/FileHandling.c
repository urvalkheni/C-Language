#include<stdio.h>
int main(){
    // FILE *ptr = fopen("Urval.txt","r"); 
    // char str[100];
    // while(fgets(str,100,ptr)!=NULL){
    //     printf("%s",str);
    // }
    FILE *ptr = fopen("Urval.txt","w");
    char str[] = "Charusat Is Good";
    fputs(str,ptr);
    fclose(ptr);
    return 0;
}