#include<stdio.h>
#include<string.h>
void main(){
    char str1[15]= "Bottle";
    char str2[15]= "Hottle";
    int result;
    result = strcmp(str1,str2);
    if(result==0){
        printf("Both strings are equal.\n");
    }
    else if(result>0){
        printf("%s is bigger.\n",str1);
    }
    else{
        printf("%s is bigger.\n",str2);
    }
}