//Print All odd numbers from 1 to 100 with continue //
#include<stdio.h>
int main(){
    for(int i = 1;i<=100;i++){
        if(i%2==0){
            continue;
        }
        printf("%d ",i);
    }
    return 0;
}