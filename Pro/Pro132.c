#include<stdio.h>
int main(){
    int arr[5],max;
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    for(int j=0;j<5;j++){
        if(max < arr[j]) max = arr[j];
    }
    printf("max element of array is %d. \n",max);
    return 0;
}