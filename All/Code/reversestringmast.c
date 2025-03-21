#include<stdio.h>
#include<windows.h>
#include<string.h>
int main(){
    char str1[50];
    char str2[50];
    int x,i,j;
    char temp;
    printf("Enter The String :: ");
    gets(str1);
    strcpy(str2,str1);
    x = strlen(str1);
   for (i = 0, j = x - 1; i < j; i++, j--) {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }
    printf("Your String's Are :: \n");
    printf("Orignal string --> %s \n",str2);
    printf("Reverse string --> \n");
     for(int i=0;str1[i]!='\0';i++){
        for(int j=0;j<=i;j++){
            printf("%c",str1[j]);
            Sleep(100);
        }
        printf("\n");
    }

    return 0;
}