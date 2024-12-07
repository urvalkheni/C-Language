//Disply Ap 100,97,94...But Trems must be positive /
#include<stdio.h>
int main(){
    int i;
    int a = 100;

   for(i=1;a>=0;i++){
        printf("%d ",a);
        a -= 3;
    };
    return 0;
}