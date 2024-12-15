// Pascal triangle //
#include<stdio.h>
int factorial(int n){
    int fact  = 1;
    for(int i=1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}
int combination(int n,int r){
    int ncr=(factorial(n)/(factorial(r)*factorial(n-r)));
    return ncr;
}
int main(){
    int n;
    printf("Enter Number How many lines you want :: ");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        for(int k=0;k<=n;k++){
            if(k>=i) printf(" ");
        }
        for(int j=0;j<=i;j++){
            int icj = combination(i,j);
            printf("%d ",icj);
        }
        printf("\n");
    }

    return 0;
}