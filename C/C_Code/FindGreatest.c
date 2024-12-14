// Take three Positive Integer and Find out which is Greatest //
#include<stdio.h>
int main(){
    int a, b,c;
    printf("Enter Three Positive Integer Numbers :: ");
    scanf("%d %d %d",&a,&b,&c);
    if(a > b && a > c && a!=b &&a!=c){
        printf("%d is greatest among %d %d and %d \n",a,a,b,c);
    }
    if(b > c && b > a && b!=a && b!=c){
        printf("%d is greatest among %d %d and %d \n",b,a,b,c);
    }
    if(c > a && c > b && c!=a && c!=b){
        printf("%d is greatest among %d %d and %d \n",c,a,b,c);
    }
    else{
        printf("all are Equal.");
    }
    return 0;
}