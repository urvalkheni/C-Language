//Check Whether input is character,digit or special charcter //
#include<stdio.h>
int main(){
    char a;

    printf("Enter the input :: ");
    scanf("%c",&a);
    if(a>='a' && a<='z' || a>='A' && a<='Z'){
        printf("The Input is an Alphabet.\n");
    }
    else if(a>='0' && a<='9'){
        printf("The Input is Digit.\n");
    }
    else{
        printf("The Input is Special Charcater.\n");
    }
    return 0;
} 