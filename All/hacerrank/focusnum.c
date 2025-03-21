
#include<stdio.h>
int main(){
    int n;
    int x= 0;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
       for(int j=1;j<=2*n-1;j++){
       int a = i;
       if(i>n) a = 2*n-i;
       int b = j;
       if(j>n) b = 2*n - j;
       if(a<b) x = a;
       else x = b; 
        printf("%d ",n+1-x);
       }
        printf("\n");
    }
    return 0;
}  