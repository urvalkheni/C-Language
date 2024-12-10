//Print all odd numbers from 1 to 100 In Different Lines //
#include<stdio.h>
int main(){
    int i;
    for(i=1;i<=100;i++){

        if(i%2==1)printf("%d ",i);
    }
    return 0; 
}