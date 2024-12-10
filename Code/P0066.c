//WAP to find all armstrong numbe fomr 1 to n //
#include<stdio.h>
int main(){
    int n,r,c,on,sum=0;
    printf("Enter The Number :: ");
    scanf("%d",&n);
   
        on = n;
        while(n!=0){
            r = n % 10;
            c = (r*r*r);
            sum = sum + c;
            n = n /10; 
        }
        if(sum==on) printf("%d is armstrong.",on);
        else printf("%d is not armstrong.",on);
    
    return 0;
}