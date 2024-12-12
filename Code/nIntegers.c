#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter The Number of Integer you Want :: ");
    scanf("%d",&n);
    int *ptr = (int*) malloc(n*sizeof(int));
    int *p = ptr;
    printf("Enter The Number :: ");
    for(int i=1;i<=n;i++){
        scanf("%d",&(*ptr));
        ptr++;
    }
    ptr = p;
    for(int i=1;i<=n;i++){
        printf("%d ",(*ptr));
        ptr++;
    }
    free(ptr);
    free(p);
    return 0;
}