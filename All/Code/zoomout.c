//Pattern 27 zoom out // just valid for 4
#include<stdio.h>
int main(){
    int n;

    printf("Enter the number :: ");
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            if(i==1  || i==2*n-1 || j==2*n-1 || j==1){
            printf("%d ",n);}
            else if(i==2  || i==2*n-2 || j==2*n-2 || j==2){
                printf("%d ",n-1);
            }
            else if(i==3 || i==2*n-3 || j==2*n-3 || j==3){
                printf("%d ",n-2);
            }
            else{
                printf("%d ",n-3);
            }
        }
        printf("\n");
    }
    return 0;
}