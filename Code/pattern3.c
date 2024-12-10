#include<stdio.h>
int main(){
    int n,m=1;
    printf("Enter The Number :: ");
    scanf("%d",&n);
    int a=65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i){if(i % 2 == 1)
            {
                printf("%c ",a);
            }
            else
            {
                printf("%d ",i/2);
            }
            }
        }
        if(i%2==1) a++;
        printf("\n");
    }
    return 0;
}
