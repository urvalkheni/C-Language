#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int sum[n];
     for(int i=0;i<n;i++){
        scanf("%d",&sum[i]);
    } 
    
    for(int i=1;i<n;i++){
        sum[0] += sum[i];
    } 
    printf("%d",sum[0]);   
    return 0;
}