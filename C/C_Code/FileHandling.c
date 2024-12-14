#include<stdio.h>
int main(){
    FILE *ptr = fopen("Urval.txt","w");
    char str[] = "Charusat Is Good";
    fputs(str,ptr);
    fclose(ptr);
    return 0;
}