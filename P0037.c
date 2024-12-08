//Prime Number only two factors (1 and that number) //
#include<stdio.h>
int main(){
    int i,n;
    int a;
     printf("Enter a number :: ");
     scanf("%d",&n);
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            a = 1;
            break;
        }
       
    }
    if(n==1)printf("1 is Neither Prime Nor Composite.\n");
    if(a==0) printf("The Given Number is Prime. \n");
    else printf("The Number is Composite.\n");
    return 0;
}       