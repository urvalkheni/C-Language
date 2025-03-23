#include<stdio.h>
int main(){
    int n=5;
    for(int i=1;i<=n*2-1;i++){
        for(int j=1;j<=n*2-1;j++){
            if(n<5 && (j>i || i+j<n*2 ))printf("* ");
            else printf("# ");
        }
        printf("\n");
    }
    for(int i=1;i<=n*2-1;i++){
        for(int j=1;j<=n*2-1;j++){
            printf("(%d,%d) ",i,j);
        }
        printf("\n");
    }
    return 0;
}
