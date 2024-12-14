//simple calculator //
#include<stdio.h>
int main(){
    char ch;
    float num1,num2,result=0.0f;

    printf("Welcome to simple calculator\n");
    printf("----------------------------\n");
    printf("Enter Opration [+ - * /] :: ");
    scanf("%c",&ch);
    printf("Enter The [Number 1] :: ");
    scanf("%f",&num1);
    printf("Enter The [Number 2] :: ");
    scanf("%f",&num2);
    
    switch(ch){
        case '+':
        result = num1 + num2;
        break;
        case '-':
        result = num1 - num2;
        break;
        case '*':
        result = num1*num2;
        break;
        case '/':
        result = num1 / num2;
        break;
        default :
        printf("Invalid Operator.");

    }
    printf("%.2f %c %.2f = %.2f \n",num1,ch,num2,result);

    return 0;
}