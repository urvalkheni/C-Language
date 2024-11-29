//Modulo two Numbers //
#include<stdio.h>
int main(){
int a,b;
int c;

printf("Please Enter First Digit :: ");
scanf("%d",&a);
printf("Please Enter Second Digit :: ");
scanf("%d",&b);

if(a>b){
c = a / b ;
}
else{
    c = b / a;
}
printf("Reminder of a and b is :: '%d' ",c);

}