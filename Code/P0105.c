// Pascal Ultimate Method //
#include<stdio.h>
int main(){
    int n;
    printf("Enter n :: ");
    scanf("%d",&n);

    for(int i=0;i<=n;i++){
        int first = 1;
        for(int k=0;k<=n;k++){
            if(k>=i)  printf(" ");
        }
        for(int j = 0;j<=i;j++){
            printf("%d ",first);
            first = first * (i-j)/(j+1);
        }
        printf("\n");
    }
    return 0;
}